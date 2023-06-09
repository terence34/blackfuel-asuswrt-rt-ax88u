/*
 * Registrar protocol messages
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
 * $Id: reg_protomsg.h 542265 2015-03-19 08:29:38Z $
 */

#ifndef _WPS_MSG_H
#define _WPS_MSG_H

#ifdef __cplusplus
extern "C" {
#endif // endif

#include <reg_prototlv.h>
#include <wps_sslist.h>

/* Message Structures */

/* Message M1 */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvUuid uuid;
	CTlvMacAddr macAddr;
	CTlvEnrolleeNonce enrolleeNonce;
	CTlvPublicKey publicKey;
	CTlvAuthTypeFlags authTypeFlags;
	CTlvEncrTypeFlags encrTypeFlags;
	CTlvConnTypeFlags connTypeFlags;
	CTlvConfigMethods configMethods;
	CTlvScState scState;
	CTlvManufacturer manufacturer;
	CTlvModelName modelName;
	CTlvModelNumber modelNumber;
	CTlvSerialNum serialNumber;
	CTlvPrimDeviceType primDeviceType;
	CTlvDeviceName deviceName;
	CTlvRfBand rfBand;
	CTlvAssocState assocState;
	CTlvDevicePwdId devPwdId;
	CTlvConfigError configError;
	CTlvOsVersion osVersion;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */
	CSubTlvReqToEnr reqToEnr; /* O: WSC 2.0 */
} WpsM1;

/* Message M2 */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvEnrolleeNonce enrolleeNonce;
	CTlvRegistrarNonce registrarNonce;
	CTlvUuid uuid;
	CTlvPublicKey publicKey;
	CTlvAuthTypeFlags authTypeFlags;
	CTlvEncrTypeFlags encrTypeFlags;
	CTlvConnTypeFlags connTypeFlags;
	CTlvConfigMethods configMethods;
	CTlvManufacturer manufacturer;
	CTlvModelName modelName;
	CTlvModelNumber modelNumber;
	CTlvSerialNum serialNumber;
	CTlvPrimDeviceType primDeviceType;
	CTlvDeviceName deviceName;
	CTlvRfBand rfBand;
	CTlvAssocState assocState;
	CTlvConfigError configError;
	CTlvDevicePwdId devPwdId;
	CTlvOsVersion osVersion;

	CTlvEncrSettings encrSettings;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */

	CTlvAuthenticator authenticator;
} WpsM2;

/* Message M2D */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvEnrolleeNonce enrolleeNonce;
	CTlvRegistrarNonce registrarNonce;
	CTlvUuid uuid;
	CTlvAuthTypeFlags authTypeFlags;
	CTlvEncrTypeFlags encrTypeFlags;
	CTlvConnTypeFlags connTypeFlags;
	CTlvConfigMethods configMethods;
	CTlvManufacturer manufacturer;
	CTlvModelName modelName;
	CTlvModelNumber modelNumber;
	CTlvSerialNum serialNumber;
	CTlvPrimDeviceType primDeviceType;
	CTlvDeviceName deviceName;
	CTlvRfBand rfBand;
	CTlvAssocState assocState;
	CTlvConfigError configError;
	CTlvDevicePwdId devPwdId;
	CTlvOsVersion osVersion;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */
} WpsM2D;

/* Message M3 */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvRegistrarNonce registrarNonce;
	CTlvHash eHash1;
	CTlvHash eHash2;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */

	CTlvAuthenticator authenticator;
} WpsM3;

/* Message M4 */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvEnrolleeNonce enrolleeNonce;
	CTlvHash rHash1;
	CTlvHash rHash2;
	CTlvEncrSettings encrSettings;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */

	CTlvAuthenticator authenticator;
} WpsM4;

/* Message M5 */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvRegistrarNonce registrarNonce;
	CTlvEncrSettings encrSettings;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */

	CTlvAuthenticator authenticator;
} WpsM5;

/* Message M6 */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvEnrolleeNonce enrolleeNonce;
	CTlvEncrSettings encrSettings;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */

	CTlvAuthenticator authenticator;
} WpsM6;

/* Message M7 */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvRegistrarNonce registrarNonce;
	CTlvEncrSettings encrSettings;

	CTlvX509CertReq x509CertReq;

	CTlvVendorExt vendorExt;
	CSubTlvSettingsDelayTime settingsDelayTime; /* O: WSC 2.0 */
	CSubTlvVersion2 version2; /* C: WSC 2.0 */

	CTlvAuthenticator authenticator;
} WpsM7;

/* Message M8 */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvEnrolleeNonce enrolleeNonce;
	CTlvEncrSettings encrSettings;

	CTlvX509Cert x509Cert;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */

	CTlvAuthenticator authenticator;
} WpsM8;

/* ACK and DONE Messages */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvEnrolleeNonce enrolleeNonce;
	CTlvRegistrarNonce registrarNonce;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */
} WpsACK, WpsDone;

/* NACK Message */
typedef struct {
	CTlvVersion version;
	CTlvMsgType msgType;
	CTlvEnrolleeNonce enrolleeNonce;
	CTlvRegistrarNonce registrarNonce;
	CTlvConfigError configError;

	CTlvVendorExt vendorExt;
	CSubTlvVersion2 version2; /* C: WSC 2.0 */
} WpsNACK;

/* Encrypted settings for various messages */

/*
 * M4, M5, M6 - contain only Nonce and vendor extension
 * this structure doesn't allocate dyamic memory
 * doesn't need a free function at the moment.
 */
typedef struct {
	CTlvNonce nonce; /* could be RS1, ES1 or RS2 */
	CTlvAuthenticator keyWrapAuth; /* reuse Authenticator data struct */
} TlvEsNonce;

/* M7 */
/* NOTE : this structure MUST be freed using reg_msg_m7enr_del */
typedef struct {
	int es_type;
	CTlvNonce nonce; /* ES2 */
	CTlvIdentityProof idProof;
	CTlvAuthenticator keyWrapAuth; /* reuse Authenticator data struct */
} EsM7Enr;

/* NOTE : this structure MUST be freed using reg_msg_m7ap_del */
typedef struct {
	int es_type;
	CTlvNonce nonce; /* ES2 */
	CTlvSsid ssid;
	CTlvMacAddr macAddr;
	CTlvAuthType authType;
	CTlvEncrType encrType;
	WPS_SSLIST *nwKeyIndex;
	WPS_SSLIST *nwKey;
	CTlvWEPTransmitKey wepIdx;
	CTlvAuthenticator keyWrapAuth; /* reuse Authenticator data struct */
} EsM7Ap;

/* M8 */
/* NOTE : this structure MUST be freed using reg_msg_m8ap_del */
typedef struct {
	int es_type;
	CTlvNwIndex nwIndex;
	CTlvSsid ssid;
	CTlvAuthType authType;
	CTlvEncrType encrType;
	WPS_SSLIST *nwKeyIndex;
	WPS_SSLIST *nwKey;
	CTlvMacAddr macAddr;
	CTlvNewPwd new_pwd;
	CTlvDevicePwdId pwdId;
	CTlvWEPTransmitKey wepIdx;
	CTlvAuthenticator keyWrapAuth; /* reuse Authenticator data struct */
} EsM8Ap;

typedef struct {
	int es_type;
	WPS_SSLIST *credential;
	CTlvNewPwd new_pwd;
	CTlvDevicePwdId pwdId;
	CTlvAuthenticator keyWrapAuth; /* reuse Authenticator data struct */
} EsM8Sta;

#define ES_TYPE_M7ENR	1
#define ES_TYPE_M7AP	2
#define ES_TYPE_M8AP	3
#define ES_TYPE_M8STA	4

void reg_msg_init(void *m, int type);
int reg_msg_version_check(uint8 msgId, BufferObj *theBuf, TlvObj_uint8 *version,
	TlvObj_uint8 *msgType);
int reg_msg_nonce_parse(TlvEsNonce *t, uint16 theType, BufferObj *theBuf, BufferObj *authKey);
void reg_msg_nonce_write(TlvEsNonce *t, BufferObj *theBuf, BufferObj *authKey);

uint32 reg_msg_m7enr_parse(EsM7Enr *t, BufferObj *theBuf, BufferObj *authKey, bool allocate);
void reg_msg_m7enr_write(EsM7Enr *t, BufferObj *theBuf, BufferObj *authKey);
uint32 reg_msg_m7ap_parse(EsM7Ap *tlv, BufferObj *theBuf, BufferObj *authKey, bool allocate);
void reg_msg_m7ap_write(EsM7Ap *tlv, BufferObj *theBuf, BufferObj *authKey);
int reg_msg_m8ap_parse(EsM8Ap *t, BufferObj *theBuf, BufferObj *authKey, bool allocate);
void reg_msg_m8ap_write(EsM8Ap *t, BufferObj *theBuf, BufferObj *authKey, bool b_wsp_version2);
int reg_msg_m8sta_parse(EsM8Sta *t, BufferObj *theBuf, BufferObj *authKey, bool allocate);
void reg_msg_m8sta_write(EsM8Sta *t, BufferObj *theBuf);
void reg_msg_m8sta_write_cred(EsM8Sta *t, BufferObj *theBuf);
void reg_msg_m8sta_write_key(EsM8Sta *t, BufferObj *theBuf, BufferObj *authKey);

void *reg_msg_es_new(int es_type);
void reg_msg_es_del(void *tlv, bool content_only);

#ifdef __cplusplus
}
#endif // endif

#endif /* _WPS_MSG_H */
