#
# Makefile for the Broadcom EMF Layer
#
# Copyright (C) 2018, Broadcom. All Rights Reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
# SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
# OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
# CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#
# <<Broadcom-WL-IPTag/Open:>>
#
# $Id$
#
# Choose BASE_DIR based on where router-sysdep resides - src or components
ifeq ($(strip $(USE_WLAN_SHARED)), 1)
ifneq ($(strip $(WLAN_SHARED_DIR)),)
-include $(WLAN_SHARED_DIR)/wifi_cfg_common.mk
endif
endif

EMF_BASE_DIR := $(firstword $(wildcard ../hnd_shared/../../../components/router-sysdep/emf	\
                                       ../hnd_shared/../../../src-rt-5.02axhnd/router-sysdep/emf))
EMFDIR      := ../emf
EMFSRCDIR  := $(EMFDIR)/emf
EMFCSRCDIR := ../hnd_shared/../../components/emf/emf

SRCBASE_OFFSET := ../hnd_shared/../../../main/src
EMFFILES_SRC   := $(SRCBASE_OFFSET)/shared
SRCBASE        := $(src)/$(SRCBASE_OFFSET)
COMPONENTSBASE_OFFSET := ../hnd_shared/../../components
COMPONENTSBASE := $(src)/$(COMPONENTSBASE_OFFSET)
SRCBASE_ROUTER := $(COMPONENTSBASE)/router-sysdep

ifeq ($(PREBUILT_EXTRAMOD),1)
REBUILD_EMF_MODULE=0
else
REBUILD_EMF_MODULE=$(shell if [ -d "$(src)/$(EMFSRCDIR)" -a "$(REUSE_PREBUILT_EMF)" != "1" ]; then echo 1; else echo 0; fi)
endif

ifeq ($(REBUILD_EMF_MODULE),1)

EMF_OBJS := $(EMFCSRCDIR)/emfc.o        $(EMFSRCDIR)/emf_linux.o

ifeq ($(CONFIG_BUZZZ_FUNC),y)
subdir-ccflags-y += -O0 -fno-inline -finstrument-functions
endif # CONFIG_BUZZZ_FUNC

# Search for sources under src/router-sysdep/emf/emf
ifneq ($(wildcard $(src)/$(EMFSRCDIR)),)
    EXTRA_CFLAGS += -I$(SRCBASE_ROUTER)/emf/emf  -I$(SRCBASE_ROUTER)/emf/igs
    EXTRA_CFLAGS += -I$(SRCBASE_ROUTER)/bcmdrv/include -I$(SRCBASE_ROUTER)/bcmdrv/include/emf/igs
    EXTRA_CFLAGS += -I$(SRCBASE_ROUTER)/bcmdrv/include/emf/emf
    EXTRA_CFLAGS += -I$(SRCBASE)/include         -I$(COMPONENTSBASE)/proto/include
    # BCA build identifier
    EXTRA_CFLAGS += -DBCMDRIVER -DBCA_HNDROUTER
    emf-objs := $(EMF_OBJS)
endif

obj-$(CONFIG_BCM_WLAN) := emf.o

else # EMFSRCDIR doesn't exist
    # Otherwise, assume prebuilt object module(s) in src/emf/linux directory
    prebuilt := emf.o
    emf-objs := $(SRCBASE_OFFSET)/router-sysdep/hnd_emf/prebuilt/$(prebuilt)
    obj-$(CONFIG_BCM_WLAN) := emf.o
endif

clean-files += $(EMFCSRCDIR)/*.o $(EMFSRCDIR)/*.o $(EMFCSRCDIR)/.*.o.cmd $(EMFSRCDIR)/.*.o.cmd
