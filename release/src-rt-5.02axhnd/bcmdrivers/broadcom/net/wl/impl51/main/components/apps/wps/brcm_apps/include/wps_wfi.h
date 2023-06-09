/*
 * WPS WiFi Invite (WFI) header file
 *
 * Copyright 2018 Broadcom
 *
 * This program is the proprietary software of Broadcom and/or
 * its licensors, and may only be used, duplicated, modified or distributed
 * pursuant to the terms and conditions of a separate, written license
 * agreement executed between you and Broadcom (an "Authorized License").
 * Except as set forth in an Authorized License, Broadcom grants no license
 * (express or implied), right to use, or waiver of any kind with respect to
 * the Software, and Broadcom expressly reserves all rights in and to the
 * Software and all intellectual property rights therein.  IF YOU HAVE NO
 * AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE IN ANY
 * WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE ALL USE OF
 * THE SOFTWARE.
 *
 * Except as expressly set forth in the Authorized License,
 *
 * 1. This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof, and to
 * use this information only in connection with your use of Broadcom
 * integrated circuit products.
 *
 * 2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED
 * "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR
 * OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 *
 * 3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL,
 * SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR
 * IN ANY WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
 * IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR (ii)
 * ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF
 * OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY
 * NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
 *
 *
 * <<Broadcom-WL-IPTag/Proprietary:>>
 *
 * $Id: wps_wfi.h 525052 2015-01-08 20:18:35Z $
 */

#ifndef _WPS_WFI_H_
#define _WPS_WFI_H_

#pragma pack(push, 1)
#define BWL_PRE_PACKED_STRUCT
#define BWL_POST_PACKED_STRUCT

typedef BWL_PRE_PACKED_STRUCT struct {
	uint8 vndr_id[3]; /* Vendor OUI: 00 11 3d */
	union {
		uint8 vndr_data[1]; /* Friendly name, variable length, non-null-terminated */
		uint8 type; /* Friendly name, variable length, non-null-terminated */
	};
} BWL_POST_PACKED_STRUCT wps_vndr_ext_t;
#define BRCM_VENDOR_ID			"\x00\x11\x3d"

typedef BWL_PRE_PACKED_STRUCT struct {
	uint8 type;        /* type of this IE = WFI_IE_TYPE. Will be defined in wlioctl.h */
	uint8 version;     /* WFI version = 1 */
	uint8 cap;         /* WFI capabilities. HOTSPOT = 0x1, Bits 1-7 : Reserved */
	uint32 pin;        /* PIN to be used */
	uint8 mac_addr[6]; /* MAC address of the STA requesting WFI (ProbeReq) or
	                   *  MAC address of the STA for whome the WFI is destined (ProbeRsp).
	                   */
	uint8 fname_len;   /* Length of the BDD friendly name (of STA in case of ProbeReq,
	                   *  of AP in case of ProbeRsp).
	                   */
	uint8 fname[1];    /* BDD Friendly name, variable length, non-null-terminated */
} BWL_POST_PACKED_STRUCT brcm_wfi_ie_t;
#pragma pack(pop)

#define WPS_WFI_VENDOR_EXT_LEN		(sizeof(brcm_wfi_ie_t) + sizeof(wps_vndr_ext_t) + 32)

#define WPS_WFI_TYPE				1
#define WPS_WFI_HOTSPOT			0x01	/* Hotspot mode when WPS is not required */

#if defined(BCMWPSAP)
/*
*  WiFi Invite Common code, implemented in wps_wfi.c:
*/

extern int wps_wfi_process_prb_req(uint8 *pcWPSIE,
	int siIELen,
	uint8 *pcAddr,
	char *pcIFname);
/*
*  Return < 0 if error; >= 0 if OK.
*  pcWPSIE: Input, WPS IE content.
*  siIELen: Input, WPS IE total length.
*  pcAddr: Input, MAC Address of the STA sending ProbeReq.
*  pcIFname: Input, Interface where the ProbeReq comes from.
*/

extern int wps_wfi_process_sta_ind(uint8 *ptData,
	int siLen,
	uint8 *ptAddr,
	uint8 *ptIFName,
	int biJoin);
/*
*  Return < 0 if error; >= 0 if OK.
*  ptData: Input, event data.
*  siLen: Input, event data total length.
*  pcAddr: Input, MAC Address of the STA sending ProbeReq.
*  pcIFname: Input, Interface where the ProbeReq comes from.
*  biJoin: 0: leaving event; !0: joining event.
*/

extern int wps_wfi_init(void);
/*
*  Initialize WFI feature.
*  Return < 0 if error; >= 0 if OK.
*/

extern int wps_wfi_rejected(void);
/*
*  Call when EAP-NAK is received.
*  Return < 0 if error; >= 0 if OK.
*/

extern int wps_wfi_cleanup(void);
/*
*  Deinitialize WFI feature.
*  Return < 0 if error; >= 0 if OK.
*/

extern void wps_wfi_check(void);
/*
*  Check the WFI operation.
*/
#endif /* BCMWPSAP */

#endif /* _WPS_WFI_H_ */
