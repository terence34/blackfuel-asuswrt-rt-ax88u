#! /bin/bash
#
# Create the wpsvers.h file from version.h.in
#
# Copyright 2018 Broadcom
#
# This program is the proprietary software of Broadcom and/or
# its licensors, and may only be used, duplicated, modified or distributed
# pursuant to the terms and conditions of a separate, written license
# agreement executed between you and Broadcom (an "Authorized License").
# Except as set forth in an Authorized License, Broadcom grants no license
# (express or implied), right to use, or waiver of any kind with respect to
# the Software, and Broadcom expressly reserves all rights in and to the
# Software and all intellectual property rights therein.  IF YOU HAVE NO
# AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE IN ANY
# WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE ALL USE OF
# THE SOFTWARE.
#
# Except as expressly set forth in the Authorized License,
#
# 1. This program, including its structure, sequence and organization,
# constitutes the valuable trade secrets of Broadcom, and you shall use
# all reasonable efforts to protect the confidentiality thereof, and to
# use this information only in connection with your use of Broadcom
# integrated circuit products.
#
# 2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED
# "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
# REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR
# OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
# DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
# NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
# ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
# CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
# OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
#
# 3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
# BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL,
# SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR
# IN ANY WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
# IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR (ii)
# ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF
# OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY
# NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
#
#
# <<Broadcom-WL-IPTag/Proprietary:>>
#
# $Id: wpsvers.sh,v 1.2 2010-04-08 00:08:22 $

# Check for the in file, if not there we're probably in the wrong directory
if [ ! -f version.h.in ]; then
	echo No version.h.in found
	exit 1
fi

if echo "${TAG}" | grep -q "BRANCH\|TWIG"; then
	branchtag=$TAG
else
	branchtag=""
fi

if [ -f wpsvers.h ]; then
	# If the out file already exists, increment its build number
	build=`grep MOD_BUILD_NUMBER wpsvers.h | sed -e "s,.*BUILD_NUMBER[ 	]*,,"`
	build=`expr ${build} + 1`
	echo build=${build}
	sed -e "s,.*_BUILD_NUMBER.*,#define MOD_BUILD_NUMBER	${build}," \
		< wpsvers.h > wpsvers.h.new
	mv wpsvers.h wpsvers.h.prev
	mv wpsvers.h.new wpsvers.h
else
	# Otherwise create a new file.

	# CVS will insert the cvs tag name when this file is checked out.
	# If this is a tagged build, use the tag to supply the numbers
	# Tag should be in the form
	#    <NAME>_REL_<MAJ>_<MINOR>
	# or
	#    <NAME>_REL_<MAJ>_<MINOR>_RC<RCNUM>
	# or
	#    <NAME>_REL_<MAJ>_<MINOR>_RC<RCNUM>_<INCREMENTAL>
	#

	CVSTAG="$Name: not supported by cvs2svn $"

	# Remove leading cvs "Name: " and trailing " $"
	CVSTAG=${CVSTAG/#*: /}
	CVSTAG=${CVSTAG/% $/}

	# TAG env var is supplied by calling makefile or build process
	#
	# If the checkout is from a branch tag, cvs checkout or export does
	# not replace rcs keywords. In such instances TAG env variable can
	# be used (by uncommenting following line). TAG env variable format
	# itself needs to be validated for number of fields before being used.
	# (e.g: HEAD is not a valid tag, which results in all '0' values below)
	#
        if [ -n "$branchtag" ]; then
	   TAG=${TAG:-${CVSTAG}}
        else
	   TAG=${CVSTAG/HEAD/}
        fi

	# Split the tag into an array on underbar or whitespace boundaries.
	IFS="_	     " tag=(${TAG})
	unset IFS

        tagged=1
	if [ ${#tag[*]} -eq 0 ]; then
	   tag=(`date '+TOT REL %Y %m %d 0 %y'`);
	   # reconstruct a TAG from the date
	   TAG=${tag[0]}_${tag[1]}_${tag[2]}_${tag[3]}_${tag[4]}_${tag[5]}
	   tagged=0
	fi

	# Allow environment variable to override values.
	# Missing values default to 0
	#
	maj=${MOD_MAJOR_VERSION:-${tag[2]:-0}}
	min=${MOD_MINOR_VERSION:-${tag[3]:-0}}
	rcnum=${MOD_RC_NUMBER:-${tag[4]:-0}}

	if [ -n "$branchtag" ]; then
		[ "${tag[5]:-0}" -eq 0 ] && echo "Using date suffix for incr"
		today=`date '+%Y%m%d'`
		incremental=${MOD_INCREMENTAL_NUMBER:-${tag[5]:-${today:-0}}}
	else
		incremental=${MOD_INCREMENTAL_NUMBER:-${tag[5]:-0}}
	fi
	origincr=${MOD_INCREMENTAL_NUMBER:-${tag[5]:-0}}
	build=${MOD_BUILD_NUMBER:-0}

	# Strip 'RC' from front of rcnum if present
	rcnum=${rcnum/#RC/}

	# strip leading zero off the number (otherwise they look like octal)
	maj=${maj/#0/}
	min=${min/#0/}
	rcnum=${rcnum/#0/}
	incremental=${incremental/#0/}
	origincr=${origincr/#0/}
	build=${build/#0/}

	# some numbers may now be null.  replace with with zero.
	maj=${maj:-0}
	min=${min:-0}
	rcnum=${rcnum:-0}
	incremental=${incremental:-0}
	origincr=${origincr:-0}
	build=${build:-0}

	if [ ${tagged} -eq 1 ]; then
	    # vernum is 32chars max
	    vernum=`printf "0x%02x%02x%02x%02x" ${maj} ${min} ${rcnum} ${origincr}`
	else
	    vernum=`printf "0x00%02x%02x%02x" ${tag[7]} ${min} ${rcnum}`
	fi

	# make sure the size of vernum is under 32 bits. Otherwise, truncate. The string will keep
	# full information.
	vernum=${vernum:0:10}

	# build the string directly from the tag, irrespective of its length
	# remove the name , the tag type, then replace all _ by .
	tag_ver_str=${TAG/${tag[0]}_}
	tag_ver_str=${tag_ver_str/${tag[1]}_}
	tag_ver_str=${tag_ver_str//_/.}

	# record tag type
	tagtype=

	if [ "${tag[1]}" = "BRANCH" -o "${tag[1]}" = "TWIG" ]; then
	    tagtype="(TOB)"
	fi

	echo version string : "$tag_ver_str"
	echo tag type $tagtype

	# OK, go do it

	echo "maj=${maj}, min=${min}, rc=${rcnum}, inc=${incremental}, build=${build}"

	sed \
		-e "s;@MOD_MAJOR_VERSION@;${maj};" \
		-e "s;@MOD_MINOR_VERSION@;${min};" \
		-e "s;@MOD_RC_NUMBER@;${rcnum};" \
		-e "s;@MOD_INCREMENTAL_NUMBER@;${incremental};" \
		-e "s;@MOD_BUILD_NUMBER@;${build};" \
		-e "s;@MOD_VERSION@;${maj}, ${min}, ${rcnum}, ${incremental};" \
		-e "s;@MOD_VERSION_STR@;${tag_ver_str};" \
		-e "s;@MOD_ROUTER_VERSION_STR@;${tag_ver_str};" \
		-e "s;@VERSION_TYPE@;${tagtype};" \
                -e "s;@MOD_VERSION_NUM@;${vernum};" \
		< version.h.in > wpsvers.h

fi
