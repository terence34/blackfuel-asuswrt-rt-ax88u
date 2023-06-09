/*
 *-----------------------------------------------------------------------------
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
 *-----------------------------------------------------------------------------
 *
 * DO NOT EDIT THIS FILE, IT WAS MACHINE GENERATED
 * by paulc on Tue Jul 29 10:24:24 2014 using:
 *
 *  $ txgaintables_tcl2c.py 47xxtcl wlc_phytbl_ac_gains.h wlc_phytbl_ac_gains.c
 *
 * $Id: wlc_phytbl_ac_gains.h 767381 2018-09-07 23:44:46Z $
 */
/* FILE-CSTYLED */

#ifndef WLC_PHYTBL_AC_GAINS_H_
#define WLC_PHYTBL_AC_GAINS_H_

#include <typedefs.h>

#define TXGAIN_TABLES_LEN 384
extern uint16 txgain_20691_phyrev13_2g_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev13_2g_ipa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev13_2g_point5_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev13_5g_1_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev13_5g_1_point5_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev13_5g_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev13_5g_ipa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev13_5g_point5_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev13_ipa_2g_for_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev16_2g_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev16_2g_ipa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev16_5g_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20691_phyrev16_5g_ipa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev12_2g_epa[TXGAIN_TABLES_LEN];

extern uint16 txgain_20693_phyrev12_2g_ipa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev12_5g_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev12_5g_epa_rev10[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev12_5g_ipa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev12_5g_epa_die2[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev12_2g_epa_die2[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev15_5g_epa_53573[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev15_5g_ipa_53573[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev32_2g_epa[TXGAIN_TABLES_LEN];
extern uint16 txgain_20693_phyrev32_5g_epa[TXGAIN_TABLES_LEN];
extern const uint16 txgain_20695_phyrev36_2g_ipa[TXGAIN_TABLES_LEN];
extern const uint16 txgain_20695_phyrev36_5g_ipa[TXGAIN_TABLES_LEN];
extern const uint16 txgain_20695_phyrev36_2g_epa[TXGAIN_TABLES_LEN];
extern const uint16 txgain_20695_phyrev36_5g_epa[TXGAIN_TABLES_LEN];
extern const uint16 txgain_20695_phyrev36_5g_epa_B0[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_5g_p5_20694a0_rev5[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_2g_p5_20694a0_rev5[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_2g_p5_20696a0_rev0[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_5g_p5_20696a0_rev0[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_2g_p5_20698a0_rev0[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_2g_p5_20698b0_rev2[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_5g_p5_20698a0_rev0[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_5g_p5_20698b0_rev2[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_2g_p5_20704a0_rev0[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_5g_p5_20704a0_rev0[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_5g_p5_20694a0_rev4[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_2g_p5_20694a0_rev4[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_ipa_2g_p5_20694a0_rev4[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_ipa_2g_p5_20694b0_rev11[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_5g_p5_20694b0_rev8[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_epa_2g_p5_20694b0_rev8[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_main_epa_5g_p5_20697a0_rev6[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_aux_epa_2g_p5_20697a0_rev7[TXGAIN_TABLES_LEN];
extern const uint16 acphy28nm_txgain_aux_ipa_2g_p5_20697a0_rev9[TXGAIN_TABLES_LEN];
#endif /* WLC_PHYTBL_AC_GAINS_H_ */
