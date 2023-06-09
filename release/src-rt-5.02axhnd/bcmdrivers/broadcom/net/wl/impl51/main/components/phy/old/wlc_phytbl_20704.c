/*
 * Radio 20704 table definition
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
 * $Id$
 */

#include <wlc_cfg.h>
#include <typedefs.h>

#include "wlc_phy_int.h"
#include "wlc_phytbl_20704.h"
#include "wlc_radioreg_20704.h"
#include "phy_ac_rxgcrs.h"

/* 20704 register dumping and initialization tables */
#if (defined(BCMDBG) && defined(DBG_PHY_IOV)) || defined(BCMDBG_PHYDUMP)

const radio_20xx_dumpregs_t dumpregs_20704_rev0[] = {
	// copied from 20704_rev0_regs.txt r740985
	{ RF0_20704_REV_ID(0)},
	{ RF0_20704_DEV_ID(0)},
	{ RF0_20704_READOVERRIDES(0)},
	{ RF0_20704_CORE_INFO(0)},
	{ RF0_20704_CONFIG_CORE01(0)},
	{ RF0_20704_CONFIG_CORE23(0)},
	{ RF0_20704_CONFIG_CORE45(0)},
	{ RF0_20704_CONFIG_CORE67(0)},
	{ RF0_20704_CONFIG_INFO_PLL(0)},
	{ RF0_20704_CONFIG_RXDIV0(0)},
	{ RF0_20704_CONFIG_RXDIV1(0)},
	{ RF0_20704_CONFIG_RXDIV2(0)},
	{ RF0_20704_CONFIG_RXDIV3(0)},
	{ RF0_20704_LPF_NOTCH_REG1(0)},
	{ RF0_20704_LPF_NOTCH_REG2(0)},
	{ RF0_20704_LPF_NOTCH_REG5(0)},
	{ RF0_20704_LPF_NOTCH_REG3(0)},
	{ RF0_20704_LPF_NOTCH_REG4(0)},
	{ RF0_20704_LPF_NOTCH_REG6(0)},
	{ RF0_20704_LPF_NOTCH_OVR1(0)},
	{ RF0_20704_RX_TOP_REG2(0)},
	{ RF0_20704_RX_TOP_REG3(0)},
	{ RF0_20704_RX_TOP_REG1(0)},
	{ RF0_20704_TX2G_MISC_CFG1(0)},
	{ RF0_20704_TX2G_CFG1_OVR(0)},
	{ RF0_20704_LOGEN_CORE_REG5(0)},
	{ RF0_20704_TXDB_REG0(0)},
	{ RF0_20704_RXADC_CFG10(0)},
	{ RF0_20704_LPF_NOTCH_LUT1(0)},
	{ RF0_20704_LPF_NOTCH_LUT4(0)},
	{ RF0_20704_LPF_NOTCH_LUT7(0)},
	{ RF0_20704_LPF_NOTCH_LUT10(0)},
	{ RF0_20704_LPF_NOTCH_LUT2(0)},
	{ RF0_20704_LPF_NOTCH_LUT5(0)},
	{ RF0_20704_LPF_NOTCH_LUT8(0)},
	{ RF0_20704_LPF_NOTCH_LUT11(0)},
	{ RF0_20704_LPF_NOTCH_LUT3(0)},
	{ RF0_20704_LPF_NOTCH_LUT6(0)},
	{ RF0_20704_LPF_NOTCH_LUT9(0)},
	{ RF0_20704_TX5G_MISC_CFG1(0)},
	{ RF0_20704_TXDB_CFG1_OVR(0)},
	{ RF0_20704_TX5G_CFG2_OVR(0)},
	{ RF0_20704_LPF_NOTCH_LUT12(0)},
	{ RF0_20704_LPF_NOTCH_CONTROL2(0)},
	{ RF0_20704_TX2G_MIX_REG4(0)},
	{ RF0_20704_TX2G_PA_REG0(0)},
	{ RF0_20704_TX2G_PA_REG1(0)},
	{ RF0_20704_TX2G_PA_REG2(0)},
	{ RF0_20704_LPF_REG1(0)},
	{ RF0_20704_LPF_REG2(0)},
	{ RF0_20704_LPF_REG3(0)},
	{ RF0_20704_LPF_REG4(0)},
	{ RF0_20704_LPF_REG6(0)},
	{ RF0_20704_LPF_REG7(0)},
	{ RF0_20704_LPF_REG8(0)},
	{ RF0_20704_LPF_REG9(0)},
	{ RF0_20704_LPF_REG10(0)},
	{ RF0_20704_LPF_REG11(0)},
	{ RF0_20704_LPF_REG12(0)},
	{ RF0_20704_LPF_GMULT_BQ2(0)},
	{ RF0_20704_LPF_GMULT_RC(0)},
	{ RF0_20704_LPF_GMULT_RC_BW(0)},
	{ RF0_20704_LPF_OVR1(0)},
	{ RF0_20704_LPF_OVR2(0)},
	{ RF0_20704_AUXPGA_CFG1(0)},
	{ RF0_20704_AUXPGA_VMID(0)},
	{ RF0_20704_AUXPGA_OVR1(0)},
	{ RF0_20704_TESTBUF_CFG1(0)},
	{ RF0_20704_TESTBUF_OVR1(0)},
	{ RF0_20704_PMU_CFG1(0)},
	{ RF0_20704_PMU_OP1(0)},
	{ RF0_20704_PMU_CFG2(0)},
	{ RF0_20704_PMU_CFG3(0)},
	{ RF0_20704_PMU_CFG4(0)},
	{ RF0_20704_LDO1P65_STAT(0)},
	{ RF0_20704_PMU_OVR1(0)},
	{ RF0_20704_IQCAL_CFG1(0)},
	{ RF0_20704_IQCAL_CFG2(0)},
	{ RF0_20704_IQCAL_CFG3(0)},
	{ RF0_20704_IQCAL_IDAC(0)},
	{ RF0_20704_IQCAL_GAIN_RFB(0)},
	{ RF0_20704_IQCAL_GAIN_RIN(0)},
	{ RF0_20704_IQCAL_CFG4(0)},
	{ RF0_20704_IQCAL_CFG5(0)},
	{ RF0_20704_IQCAL_CFG6(0)},
	{ RF0_20704_IQCAL_OVR1(0)},
	{ RF0_20704_RX2G_REG4(0)},
	{ RF0_20704_RX2G_CFG1_OVR(0)},
	{ RF0_20704_RX5G_REG1(0)},
	{ RF0_20704_RX5G_REG2(0)},
	{ RF0_20704_RX5G_WRSSI0(0)},
	{ RF0_20704_RX5G_WRSSI1(0)},
	{ RF0_20704_RX5G_REG4(0)},
	{ RF0_20704_RX5G_REG5(0)},
	{ RF0_20704_RX5G_REG6(0)},
	{ RF0_20704_RX5G_WRSSI(0)},
	{ RF0_20704_RXDB_CFG1_OVR(0)},
	{ RF0_20704_TIA_REG1(0)},
	{ RF0_20704_TIA_REG2(0)},
	{ RF0_20704_TIA_REG3(0)},
	{ RF0_20704_TIA_REG4(0)},
	{ RF0_20704_TIA_REG5(0)},
	{ RF0_20704_TIA_REG6(0)},
	{ RF0_20704_TIA_REG7(0)},
	{ RF0_20704_TIA_REG8(0)},
	{ RF0_20704_TIA_DCDAC_REG1(0)},
	{ RF0_20704_TIA_DCDAC_REG2(0)},
	{ RF0_20704_TIA_NBRSSI_REG1(0)},
	{ RF0_20704_TIA_NBRSSI_REG2(0)},
	{ RF0_20704_TIA_NBRSSI_REG3(0)},
	{ RF0_20704_TIA_GMULT_BQ1(0)},
	{ RF0_20704_TIA_CFG1_OVR(0)},
	{ RF0_20704_AFEDIV_CFG1_OVR(0)},
	{ RF0_20704_AFEDIV_REG2(0)},
	{ RF0_20704_AFEDIV_REG1(0)},
	{ RF0_20704_VBAT_CFG(0)},
	{ RF0_20704_GPAIO_SEL3(0)},
	{ RF0_20704_AFEBIAS_REG0(0)},
	{ RF0_20704_AFEBIAS_REG1(0)},
	{ RF0_20704_TXDAC_REG0(0)},
	{ RF0_20704_TXDAC_REG1(0)},
	{ RF0_20704_TXDAC_REG2(0)},
	{ RF0_20704_RXADC_CFG0(0)},
	{ RF0_20704_RXADC_CFG1(0)},
	{ RF0_20704_RXADC_CFG2(0)},
	{ RF0_20704_RXADC_CFG3(0)},
	{ RF0_20704_RXADC_CFG5(0)},
	{ RF0_20704_RXADC_CFG6(0)},
	{ RF0_20704_RXADC_CFG8(0)},
	{ RF0_20704_RXADC_CFG9(0)},
	{ RF0_20704_RXADC_REG0(0)},
	{ RF0_20704_RXADC_REG1(0)},
	{ RF0_20704_RXADC_REG2(0)},
	{ RF0_20704_RXADC_REG3(0)},
	{ RF0_20704_RXADC_REG4(0)},
	{ RF0_20704_RXADC_REG5(0)},
	{ RF0_20704_RXADC_CAL_STATUS(0)},
	{ RF0_20704_AFE_CFG1_OVR1(0)},
	{ RF0_20704_AFE_CFG1_OVR2(0)},
	{ RF0_20704_SPARE_CFG0(0)},
	{ RF0_20704_SPARE_CFG1(0)},
	{ RF0_20704_SPARE_CFG2(0)},
	{ RF0_20704_SPARE_CFG3(0)},
	{ RF0_20704_SPARE_CFG4(0)},
	{ RF0_20704_SPARE_CFG5(0)},
	{ RF0_20704_SPARE_CFG6(0)},
	{ RF0_20704_SPARE_CFG7(0)},
	{ RF0_20704_SPARE_CFG8(0)},
	{ RF0_20704_SPARE_CFG9(0)},
	{ RF0_20704_SPARE_CFG10(0)},
	{ RF0_20704_SPARE_CFG11(0)},
	{ RF0_20704_SPARE_CFG12(0)},
	{ RF0_20704_GPAIO_SEL2(0)},
	{ RF0_20704_GPAIO_SEL1(0)},
	{ RF0_20704_GPAIO_SEL0(0)},
	{ RF0_20704_TEMPSENSE_OVR1(0)},
	{ RF0_20704_TEMPSENSE_CFG(0)},
	{ RF0_20704_VBAT_OVR1(0)},
	{ RF0_20704_SPARE_CFG13(0)},
	{ RF0_20704_BG_REG13(0)},
	{ RF0_20704_BG_REG14(0)},
	{ RF0_20704_TX2G_PAD_REG1(0)},
	{ RF0_20704_TX2G_MIX_REG2(0)},
	{ RF0_20704_TX2G_PAD_REG2(0)},
	{ RF0_20704_TXDB_PAD_REG3(0)},
	{ RF0_20704_TX2G_PAD_REG0(0)},
	{ RF0_20704_RXADC_CAP1_STAT(0)},
	{ RF0_20704_LOGEN_CORE_REG4(0)},
	{ RF0_20704_RXADC_CONV_STAT_I(0)},
	{ RF0_20704_TX2G_MISC_CFG3(0)},
	{ RF0_20704_LPF_REG13(0)},
	{ RF0_20704_TIA_REG9(0)},
	{ RF0_20704_TX5G_MISC_CFG5(0)},
	{ RF0_20704_TX5G_MISC_CFG3(0)},
	{ RF0_20704_TX5G_MISC_CFG4(0)},
	{ RF0_20704_RXADC_CAP0_STAT(0)},
	{ RF0_20704_TX2G_PAD_GC_REG(0)},
	{ RF0_20704_RXADC_CAP2_STAT(0)},
	{ RF0_20704_TX2G_BIAS_REG0(0)},
	{ RF0_20704_TX2G_MIX_REG1(0)},
	{ RF0_20704_TX2G_MIX_REG0(0)},
	{ RF0_20704_TX2G_MIX_REG3(0)},
	{ RF0_20704_TX5G_MISC_CFG6(0)},
	{ RF0_20704_TX2G_MISC_CFG2(0)},
	{ RF0_20704_TX5G_MISC_CFG2(0)},
	{ RF0_20704_TX2G_MISC_CFG4(0)},
	{ RF0_20704_TX2G_MISC_CFG5(0)},
	{ RF0_20704_TX2G_MISC_CFG6(0)},
	{ RF0_20704_LOGEN_CORE_REG0(0)},
	{ RF0_20704_LOGEN_CORE_REG1(0)},
	{ RF0_20704_LOGEN_CORE_REG2(0)},
	{ RF0_20704_LOGEN_CORE_REG3(0)},
	{ RF0_20704_AFEDIV_REG0(0)},
	{ RF0_20704_LOGEN_CORE_OVR0(0)},
	{ RF0_20704_RXADC_CONV_STAT_Q(0)},
	{ RF0_20704_BG_OVR2(0)},
	{ RF0_20704_TX2G_MIX_GC_REG(0)},
	{ RF0_20704_TXDAC_REG3(0)},
	{ RF0_20704_TX5G_MIX_REG0(0)},
	{ RF0_20704_TX2G_BIAS_REG1(0)},
	{ RF1_20704_REV_ID(0)},
	{ RF1_20704_DEV_ID(0)},
	{ RF1_20704_READOVERRIDES(0)},
	{ RF1_20704_CORE_INFO(0)},
	{ RF1_20704_CONFIG_CORE01(0)},
	{ RF1_20704_CONFIG_CORE23(0)},
	{ RF1_20704_CONFIG_CORE45(0)},
	{ RF1_20704_CONFIG_CORE67(0)},
	{ RF1_20704_CONFIG_INFO_PLL(0)},
	{ RF1_20704_CONFIG_RXDIV0(0)},
	{ RF1_20704_CONFIG_RXDIV1(0)},
	{ RF1_20704_CONFIG_RXDIV2(0)},
	{ RF1_20704_CONFIG_RXDIV3(0)},
	{ RF1_20704_LPF_NOTCH_REG1(0)},
	{ RF1_20704_LPF_NOTCH_REG2(0)},
	{ RF1_20704_LPF_NOTCH_REG5(0)},
	{ RF1_20704_LPF_NOTCH_REG3(0)},
	{ RF1_20704_LPF_NOTCH_REG4(0)},
	{ RF1_20704_LPF_NOTCH_REG6(0)},
	{ RF1_20704_LPF_NOTCH_OVR1(0)},
	{ RF1_20704_RX_TOP_REG2(0)},
	{ RF1_20704_RX_TOP_REG3(0)},
	{ RF1_20704_RX_TOP_REG1(0)},
	{ RF1_20704_TX2G_MISC_CFG1(0)},
	{ RF1_20704_TX2G_CFG1_OVR(0)},
	{ RF1_20704_LOGEN_CORE_REG5(0)},
	{ RF1_20704_TXDB_REG0(0)},
	{ RF1_20704_RXADC_CFG10(0)},
	{ RF1_20704_LPF_NOTCH_LUT1(0)},
	{ RF1_20704_LPF_NOTCH_LUT4(0)},
	{ RF1_20704_LPF_NOTCH_LUT7(0)},
	{ RF1_20704_LPF_NOTCH_LUT10(0)},
	{ RF1_20704_LPF_NOTCH_LUT2(0)},
	{ RF1_20704_LPF_NOTCH_LUT5(0)},
	{ RF1_20704_LPF_NOTCH_LUT8(0)},
	{ RF1_20704_LPF_NOTCH_LUT11(0)},
	{ RF1_20704_LPF_NOTCH_LUT3(0)},
	{ RF1_20704_LPF_NOTCH_LUT6(0)},
	{ RF1_20704_LPF_NOTCH_LUT9(0)},
	{ RF1_20704_TX5G_MISC_CFG1(0)},
	{ RF1_20704_TXDB_CFG1_OVR(0)},
	{ RF1_20704_TX5G_CFG2_OVR(0)},
	{ RF1_20704_LPF_NOTCH_LUT12(0)},
	{ RF1_20704_LPF_NOTCH_CONTROL2(0)},
	{ RF1_20704_TX2G_MIX_REG4(0)},
	{ RF1_20704_TX2G_PA_REG0(0)},
	{ RF1_20704_TX2G_PA_REG1(0)},
	{ RF1_20704_TX2G_PA_REG2(0)},
	{ RF1_20704_GPAIO_SEL9(0)},
	{ RF1_20704_LDO1P8_STAT(0)},
	{ RF1_20704_LPF_REG1(0)},
	{ RF1_20704_LPF_REG2(0)},
	{ RF1_20704_LPF_REG3(0)},
	{ RF1_20704_LPF_REG4(0)},
	{ RF1_20704_LPF_REG6(0)},
	{ RF1_20704_LPF_REG7(0)},
	{ RF1_20704_LPF_REG8(0)},
	{ RF1_20704_LPF_REG9(0)},
	{ RF1_20704_LPF_REG10(0)},
	{ RF1_20704_LPF_REG11(0)},
	{ RF1_20704_LPF_REG12(0)},
	{ RF1_20704_LPF_GMULT_BQ2(0)},
	{ RF1_20704_LPF_GMULT_RC(0)},
	{ RF1_20704_LPF_GMULT_RC_BW(0)},
	{ RF1_20704_LPF_OVR1(0)},
	{ RF1_20704_LPF_OVR2(0)},
	{ RF1_20704_AUXPGA_CFG1(0)},
	{ RF1_20704_AUXPGA_VMID(0)},
	{ RF1_20704_AUXPGA_OVR1(0)},
	{ RF1_20704_TESTBUF_CFG1(0)},
	{ RF1_20704_TESTBUF_OVR1(0)},
	{ RF1_20704_PMU_CFG1(0)},
	{ RF1_20704_PMU_OP1(0)},
	{ RF1_20704_PMU_CFG2(0)},
	{ RF1_20704_PMU_CFG3(0)},
	{ RF1_20704_PMU_CFG4(0)},
	{ RF1_20704_LDO1P65_STAT(0)},
	{ RF1_20704_PMU_OVR1(0)},
	{ RF1_20704_IQCAL_CFG1(0)},
	{ RF1_20704_IQCAL_CFG2(0)},
	{ RF1_20704_IQCAL_CFG3(0)},
	{ RF1_20704_IQCAL_IDAC(0)},
	{ RF1_20704_IQCAL_GAIN_RFB(0)},
	{ RF1_20704_IQCAL_GAIN_RIN(0)},
	{ RF1_20704_IQCAL_CFG4(0)},
	{ RF1_20704_IQCAL_CFG5(0)},
	{ RF1_20704_IQCAL_CFG6(0)},
	{ RF1_20704_IQCAL_OVR1(0)},
	{ RF1_20704_RX2G_REG4(0)},
	{ RF1_20704_RX2G_CFG1_OVR(0)},
	{ RF1_20704_RX5G_REG1(0)},
	{ RF1_20704_RX5G_REG2(0)},
	{ RF1_20704_RX5G_WRSSI0(0)},
	{ RF1_20704_RX5G_WRSSI1(0)},
	{ RF1_20704_RX5G_REG4(0)},
	{ RF1_20704_RX5G_REG5(0)},
	{ RF1_20704_RX5G_REG6(0)},
	{ RF1_20704_RX5G_WRSSI(0)},
	{ RF1_20704_RXDB_CFG1_OVR(0)},
	{ RF1_20704_TIA_REG1(0)},
	{ RF1_20704_TIA_REG2(0)},
	{ RF1_20704_TIA_REG3(0)},
	{ RF1_20704_TIA_REG4(0)},
	{ RF1_20704_TIA_REG5(0)},
	{ RF1_20704_TIA_REG6(0)},
	{ RF1_20704_TIA_REG7(0)},
	{ RF1_20704_TIA_REG8(0)},
	{ RF1_20704_TIA_DCDAC_REG1(0)},
	{ RF1_20704_TIA_DCDAC_REG2(0)},
	{ RF1_20704_TIA_NBRSSI_REG1(0)},
	{ RF1_20704_TIA_NBRSSI_REG2(0)},
	{ RF1_20704_TIA_NBRSSI_REG3(0)},
	{ RF1_20704_TIA_GMULT_BQ1(0)},
	{ RF1_20704_TIA_CFG1_OVR(0)},
	{ RF1_20704_AFEDIV_CFG1_OVR(0)},
	{ RF1_20704_WLLDO1P8_OVR(0)},
	{ RF1_20704_AFEDIV_REG2(0)},
	{ RF1_20704_AFEDIV_REG1(0)},
	{ RF1_20704_VBAT_CFG(0)},
	{ RF1_20704_GPAIO_SEL3(0)},
	{ RF1_20704_AFEBIAS_REG0(0)},
	{ RF1_20704_AFEBIAS_REG1(0)},
	{ RF1_20704_TXDAC_REG0(0)},
	{ RF1_20704_TXDAC_REG1(0)},
	{ RF1_20704_TXDAC_REG2(0)},
	{ RF1_20704_RXADC_CFG0(0)},
	{ RF1_20704_RXADC_CFG1(0)},
	{ RF1_20704_RXADC_CFG2(0)},
	{ RF1_20704_RXADC_CFG3(0)},
	{ RF1_20704_RXADC_CFG5(0)},
	{ RF1_20704_RXADC_CFG6(0)},
	{ RF1_20704_RXADC_CFG8(0)},
	{ RF1_20704_RXADC_CFG9(0)},
	{ RF1_20704_RXADC_REG0(0)},
	{ RF1_20704_RXADC_REG1(0)},
	{ RF1_20704_RXADC_REG2(0)},
	{ RF1_20704_RXADC_REG3(0)},
	{ RF1_20704_RXADC_REG4(0)},
	{ RF1_20704_RXADC_REG5(0)},
	{ RF1_20704_RXADC_CAL_STATUS(0)},
	{ RF1_20704_AFE_CFG1_OVR1(0)},
	{ RF1_20704_AFE_CFG1_OVR2(0)},
	{ RF1_20704_SPARE_CFG0(0)},
	{ RF1_20704_SPARE_CFG1(0)},
	{ RF1_20704_SPARE_CFG2(0)},
	{ RF1_20704_SPARE_CFG3(0)},
	{ RF1_20704_SPARE_CFG4(0)},
	{ RF1_20704_SPARE_CFG5(0)},
	{ RF1_20704_SPARE_CFG6(0)},
	{ RF1_20704_SPARE_CFG7(0)},
	{ RF1_20704_SPARE_CFG8(0)},
	{ RF1_20704_SPARE_CFG9(0)},
	{ RF1_20704_SPARE_CFG10(0)},
	{ RF1_20704_SPARE_CFG11(0)},
	{ RF1_20704_SPARE_CFG12(0)},
	{ RF1_20704_GPAIO_SEL2(0)},
	{ RF1_20704_GPAIO_SEL1(0)},
	{ RF1_20704_GPAIO_SEL0(0)},
	{ RF1_20704_TEMPSENSE_OVR1(0)},
	{ RF1_20704_TEMPSENSE_CFG(0)},
	{ RF1_20704_VBAT_OVR1(0)},
	{ RF1_20704_VCCIO_OVR1(0)},
	{ RF1_20704_VCCIO_CFG(0)},
	{ RF1_20704_RCCAL_CFG2(0)},
	{ RF1_20704_RCCAL_CFG3(0)},
	{ RF1_20704_RCCAL_CFG0(0)},
	{ RF1_20704_RCCAL_CFG1(0)},
	{ RF1_20704_RCCAL_CFG6(0)},
	{ RF1_20704_RCCAL_CFG4(0)},
	{ RF1_20704_RCCAL_CFG5(0)},
	{ RF1_20704_SPARE_CFG13(0)},
	{ RF1_20704_BG_REG13(0)},
	{ RF1_20704_BG_REG14(0)},
	{ RF1_20704_TX2G_PAD_REG1(0)},
	{ RF1_20704_TX2G_MIX_REG2(0)},
	{ RF1_20704_TX2G_PAD_REG2(0)},
	{ RF1_20704_TXDB_PAD_REG3(0)},
	{ RF1_20704_TX2G_PAD_REG0(0)},
	{ RF1_20704_RXADC_CAP1_STAT(0)},
	{ RF1_20704_LOGEN_CORE_REG4(0)},
	{ RF1_20704_RCCAL_CFG7(0)},
	{ RF1_20704_RXADC_CONV_STAT_I(0)},
	{ RF1_20704_TX2G_MISC_CFG3(0)},
	{ RF1_20704_LPF_REG13(0)},
	{ RF1_20704_TIA_REG9(0)},
	{ RF1_20704_TX5G_MISC_CFG5(0)},
	{ RF1_20704_TX5G_MISC_CFG3(0)},
	{ RF1_20704_TX5G_MISC_CFG4(0)},
	{ RF1_20704_RXADC_CAP0_STAT(0)},
	{ RF1_20704_TX2G_PAD_GC_REG(0)},
	{ RF1_20704_RXADC_CAP2_STAT(0)},
	{ RF1_20704_TX2G_BIAS_REG0(0)},
	{ RF1_20704_TX2G_MIX_REG1(0)},
	{ RF1_20704_TX2G_MIX_REG0(0)},
	{ RF1_20704_TX2G_MIX_REG3(0)},
	{ RF1_20704_TX5G_MISC_CFG6(0)},
	{ RF1_20704_GPAIO_SEL8(0)},
	{ RF1_20704_TX2G_MISC_CFG2(0)},
	{ RF1_20704_TX5G_MISC_CFG2(0)},
	{ RF1_20704_TX2G_MISC_CFG4(0)},
	{ RF1_20704_TX2G_MISC_CFG5(0)},
	{ RF1_20704_TX2G_MISC_CFG6(0)},
	{ RF1_20704_LOGEN_CORE_REG0(0)},
	{ RF1_20704_LOGEN_CORE_REG1(0)},
	{ RF1_20704_LOGEN_CORE_REG2(0)},
	{ RF1_20704_LOGEN_CORE_REG3(0)},
	{ RF1_20704_AFEDIV_REG0(0)},
	{ RF1_20704_LOGEN_CORE_OVR0(0)},
	{ RF1_20704_RXADC_CONV_STAT_Q(0)},
	{ RF1_20704_BG_OVR2(0)},
	{ RF1_20704_TX2G_MIX_GC_REG(0)},
	{ RF1_20704_TXDAC_REG3(0)},
	{ RF1_20704_TX5G_MIX_REG0(0)},
	{ RF1_20704_TX2G_BIAS_REG1(0)},
	{ RF1_20704_RCCAL_OVR0(0)},
	{ RFP0_20704_REV_ID(0)},
	{ RFP0_20704_DEV_ID(0)},
	{ RFP0_20704_READOVERRIDES(0)},
	{ RFP0_20704_CORE_INFO(0)},
	{ RFP0_20704_CONFIG_CORE01(0)},
	{ RFP0_20704_CONFIG_CORE23(0)},
	{ RFP0_20704_CONFIG_CORE45(0)},
	{ RFP0_20704_CONFIG_CORE67(0)},
	{ RFP0_20704_CONFIG_INFO_PLL(0)},
	{ RFP0_20704_CONFIG_RXDIV0(0)},
	{ RFP0_20704_CONFIG_RXDIV1(0)},
	{ RFP0_20704_CONFIG_RXDIV2(0)},
	{ RFP0_20704_CONFIG_RXDIV3(0)},
	{ RFP0_20704_XTAL1(0)},
	{ RFP0_20704_XTAL0(0)},
	{ RFP0_20704_XTAL2(0)},
	{ RFP0_20704_XTAL0_OVR(0)},
	{ RFP0_20704_BG_REG12(0)},
	{ RFP0_20704_BG_REG2(0)},
	{ RFP0_20704_BG_REG3(0)},
	{ RFP0_20704_BG_REG6(0)},
	{ RFP0_20704_BG_OVR1(0)},
	{ RFP0_20704_BG_REG7(0)},
	{ RFP0_20704_BG_REG5(0)},
	{ RFP0_20704_PLL_CP1(0)},
	{ RFP0_20704_PLL_CP2(0)},
	{ RFP0_20704_PLL_CP3(0)},
	{ RFP0_20704_PLL_CP4(0)},
	{ RFP0_20704_PLL_CP5(0)},
	{ RFP0_20704_PLL_FRCT1(0)},
	{ RFP0_20704_PLL_FRCT2(0)},
	{ RFP0_20704_PLL_FRCT3(0)},
	{ RFP0_20704_PLL_LF1(0)},
	{ RFP0_20704_PLL_LF2(0)},
	{ RFP0_20704_PLL_LF3(0)},
	{ RFP0_20704_PLL_LF4(0)},
	{ RFP0_20704_PLL_LF5(0)},
	{ RFP0_20704_PLL_LF6(0)},
	{ RFP0_20704_PLL_LF7(0)},
	{ RFP0_20704_PLL_MMD1(0)},
	{ RFP0_20704_PLL_MONITOR1(0)},
	{ RFP0_20704_PLL_CFG1(0)},
	{ RFP0_20704_PLL_CFG2(0)},
	{ RFP0_20704_PLL_CFG3(0)},
	{ RFP0_20704_PLL_CFG4(0)},
	{ RFP0_20704_BG_REG4(0)},
	{ RFP0_20704_PLL_VCO2(0)},
	{ RFP0_20704_PLL_VCO3(0)},
	{ RFP0_20704_PLL_VCO4(0)},
	{ RFP0_20704_PLL_VCO5(0)},
	{ RFP0_20704_PLL_VCO6(0)},
	{ RFP0_20704_PLL_VCO7(0)},
	{ RFP0_20704_PLL_VCO8(0)},
	{ RFP0_20704_PLL_CFGR1(0)},
	{ RFP0_20704_PLL_CFGR2(0)},
	{ RFP0_20704_PLL_HVLDO1(0)},
	{ RFP0_20704_PLL_HVLDO2(0)},
	{ RFP0_20704_PLL_HVLDO3(0)},
	{ RFP0_20704_PLL_HVLDO4(0)},
	{ RFP0_20704_PLL_LVLDO1(0)},
	{ RFP0_20704_BG_REG8(0)},
	{ RFP0_20704_BG_REG1(0)},
	{ RFP0_20704_PLL_OVR1(0)},
	{ RFP0_20704_PLL_STATUS2(0)},
	{ RFP0_20704_PLL_STATUS1(0)},
	{ RFP0_20704_PLL_VCOCAL1(0)},
	{ RFP0_20704_PLL_VCOCAL2(0)},
	{ RFP0_20704_PLL_VCOCAL3(0)},
	{ RFP0_20704_PLL_VCOCAL4(0)},
	{ RFP0_20704_PLL_VCOCAL5(0)},
	{ RFP0_20704_PLL_VCOCAL6(0)},
	{ RFP0_20704_PLL_VCOCAL7(0)},
	{ RFP0_20704_PLL_VCOCAL8(0)},
	{ RFP0_20704_PLL_VCOCAL9(0)},
	{ RFP0_20704_PLL_VCOCAL10(0)},
	{ RFP0_20704_PLL_VCOCAL11(0)},
	{ RFP0_20704_PLL_VCOCAL12(0)},
	{ RFP0_20704_PLL_VCOCAL13(0)},
	{ RFP0_20704_PLL_VCOCAL14(0)},
	{ RFP0_20704_PLL_VCOCAL15(0)},
	{ RFP0_20704_PLL_VCOCAL16(0)},
	{ RFP0_20704_PLL_VCOCAL17(0)},
	{ RFP0_20704_PLL_VCOCAL18(0)},
	{ RFP0_20704_PLL_VCOCAL19(0)},
	{ RFP0_20704_PLL_VCOCAL20(0)},
	{ RFP0_20704_PLL_VCOCAL21(0)},
	{ RFP0_20704_PLL_VCOCAL22(0)},
	{ RFP0_20704_PLL_VCOCAL23(0)},
	{ RFP0_20704_PLL_VCOCAL24(0)},
	{ RFP0_20704_PLL_VCOCAL25(0)},
	{ RFP0_20704_PLL_VCOCAL26(0)},
	{ RFP0_20704_PLL_VCOCAL27(0)},
	{ RFP0_20704_PLL_VCOCAL_OVR1(0)},
	{ RFP0_20704_PLL_XTAL_CNT1(0)},
	{ RFP0_20704_PLL_XTAL_CNT2(0)},
	{ RFP0_20704_PLL_DELTAPLLVAL1(0)},
	{ RFP0_20704_PLL_DELTAPLLVAL2(0)},
	{ RFP0_20704_PLL_TARGET_COUNT0(0)},
	{ RFP0_20704_PLL_TARGET_COUNT1(0)},
	{ RFP0_20704_PLL_TARGET_COUNT2(0)},
	{ RFP0_20704_PLL_TARGET_COUNT3(0)},
	{ RFP0_20704_PLL_NORM_COUNT_L0(0)},
	{ RFP0_20704_PLL_NORM_COUNT_L1(0)},
	{ RFP0_20704_PLL_NORM_COUNT_L2(0)},
	{ RFP0_20704_PLL_NORM_COUNT_L3(0)},
	{ RFP0_20704_PLL_NORM_COUNT_R0(0)},
	{ RFP0_20704_PLL_NORM_COUNT_R1(0)},
	{ RFP0_20704_PLL_NORM_COUNT_R2(0)},
	{ RFP0_20704_PLL_NORM_COUNT_R3(0)},
	{ RFP0_20704_PLL_INIT_CAPA0(0)},
	{ RFP0_20704_PLL_INIT_CAPA1(0)},
	{ RFP0_20704_PLL_INIT_CAPA2(0)},
	{ RFP0_20704_PLL_INIT_CAPA3(0)},
	{ RFP0_20704_PLL_INIT_CAPB0(0)},
	{ RFP0_20704_PLL_INIT_CAPB1(0)},
	{ RFP0_20704_PLL_INIT_CAPB2(0)},
	{ RFP0_20704_PLL_INIT_CAPB3(0)},
	{ RFP0_20704_PLL_ERRTHRES0(0)},
	{ RFP0_20704_PLL_ERRTHRES1(0)},
	{ RFP0_20704_PLL_ERRTHRES2(0)},
	{ RFP0_20704_PLL_ERRTHRES3(0)},
	{ RFP0_20704_PLL_MUXSELECT_LINE(0)},
	{ RFP0_20704_BG_REG9(0)},
	{ RFP0_20704_BG_REG10(0)},
	{ RFP0_20704_RCAL_CFG_NORTH(0)},
	{ RFP0_20704_RCAL_CFG_EAST(0)},
	{ RFP0_20704_GPAIO_SEL4(0)},
	{ RFP0_20704_GPAIO_SEL5(0)},
	{ RFP0_20704_GPAIO_SEL7(0)},
	{ RFP0_20704_GPAIO_SEL6(0)},
	{ RFP0_20704_BG_REG11(0)},
	{ RFP0_20704_PLL_REFDOUBLER4(0)},
	{ RFP0_20704_PLL_REFDOUBLER5(0)},
	{ RFP0_20704_PLL_REFDOUBLER6(0)},
	{ RFP0_20704_PLL_REFDOUBLER_OUT1(0)},
	{ RFP0_20704_FRONTLDO_REG1(0)},
	{ RFP0_20704_FRONTLDO_REG2(0)},
	{ RFP0_20704_WLLDO1P8_OVR(0)},
	{ RFP0_20704_LOGEN_CORE_REG6(0)},
	{ RFP0_20704_FRONTLDO_REG3(0)},
	{ RFP0_20704_LOGEN_REG2(0)},
	{ RFP0_20704_XTAL3(0)},
	{ RFP0_20704_LOGEN_REG1(0)},
	{ RFP0_20704_LOGEN_REG0(0)},
	{ RFP0_20704_PLL_REFDOUBLER3(0)},
	{ RFP0_20704_PLL_REFDOUBLER2(0)},
	{ RFP0_20704_PLL_REFDOUBLER1(0)},
	{ 0xFFFF,               }
};

#endif // endif

const radio_20xx_prefregs_t prefregs_20704_rev0[] = {
	// copied from 20704_rev0_regs.txt r740985
	{ RF0_20704_TX2G_PA_REG0(0),      0x1cc3},
	{ RF0_20704_TX2G_PA_REG1(0),      0x1dff},
	{ RF0_20704_TX2G_PA_REG2(0),       0x1cd},
	{ RF0_20704_PMU_CFG1(0),       0x800},
	{ RF0_20704_RX2G_REG4(0),        0x80},
	{ RF0_20704_TX2G_PAD_REG0(0),      0x2000},
	{ RF1_20704_TX2G_PA_REG0(0),      0x1cc3},
	{ RF1_20704_TX2G_PA_REG1(0),      0x1dff},
	{ RF1_20704_TX2G_PA_REG2(0),       0x1cd},
	{ RF1_20704_PMU_CFG1(0),       0x800},
	{ RF1_20704_RX2G_REG4(0),        0x80},
	{ RF1_20704_TX2G_PAD_REG0(0),      0x2000},
	{ RFP0_20704_PLL_CFG2(0),           0},
	{ RFP0_20704_PLL_VCO6(0),      0x14c0},
	{ RFP0_20704_PLL_VCO7(0),       0x80c},
	{ RFP0_20704_PLL_VCOCAL1(0),      0x5f41},
	{ RFP0_20704_PLL_VCOCAL5(0),       0x98a},
	{ RFP0_20704_PLL_VCOCAL7(0),      0x3048},
	{ RFP0_20704_PLL_VCOCAL9(0),       0x98a},
	{ RFP0_20704_PLL_VCOCAL10(0),       0x3d9},
	{ RFP0_20704_PLL_VCOCAL11(0),        0x27},
	{ RFP0_20704_PLL_VCOCAL12(0),       0x600},
	{ RFP0_20704_PLL_VCOCAL13(0),       0x700},
	{ RFP0_20704_PLL_VCOCAL20(0),         0x3},
	{ RFP0_20704_PLL_VCOCAL24(0),       0x1b3},
	{ RFP0_20704_PLL_VCOCAL26(0),       0x646},
	{ 0xFFFF,                           0}
};

/* 63178FIXME: 20704_rev0_tuning.tcl not yet available; replaced by stub */
/* 20704_rev0_tuning.tcl r?????? */
CONST chan_info_radio20704_rffe_t chan_tune_20704_rev0[] = {
	{ 184, 4920, { {
	0x00 } } },
	{ 185, 4925, { {
	0x00 } } },
	{ 187, 4935, { {
	0x00 } } },
	{ 188, 4940, { {
	0x00 } } },
	{ 189, 4945, { {
	0x00 } } },
	{ 192, 4960, { {
	0x00 } } },
	{ 196, 4980, { {
	0x00 } } },
	{ 207, 5035, { {
	0x00 } } },
	{ 208, 5040, { {
	0x00 } } },
	{ 209, 5045, { {
	0x00 } } },
	{ 210, 5050, { {
	0x00 } } },
	{ 212, 5060, { {
	0x00 } } },
	{ 216, 5080, { {
	0x00 } } },
	{ 34, 5170, { {
	0x00 } } },
	{ 36, 5180, { {
	0x00 } } },
	{ 38, 5190, { {
	0x00 } } },
	{ 40, 5200, { {
	0x00 } } },
	{ 42, 5210, { {
	0x00 } } },
	{ 44, 5220, { {
	0x00 } } },
	{ 46, 5230, { {
	0x00 } } },
	{ 48, 5240, { {
	0x00 } } },
	{ 50, 5250, { {
	0x00 } } },
	{ 52, 5260, { {
	0x00 } } },
	{ 54, 5270, { {
	0x00 } } },
	{ 56, 5280, { {
	0x00 } } },
	{ 58, 5290, { {
	0x00 } } },
	{ 60, 5300, { {
	0x00 } } },
	{ 62, 5310, { {
	0x00 } } },
	{ 64, 5320, { {
	0x00 } } },
	{ 100, 5500, { {
	0x00 } } },
	{ 102, 5510, { {
	0x00 } } },
	{ 104, 5520, { {
	0x00 } } },
	{ 106, 5530, { {
	0x00 } } },
	{ 108, 5540, { {
	0x00 } } },
	{ 110, 5550, { {
	0x00 } } },
	{ 112, 5560, { {
	0x00 } } },
	{ 114, 5570, { {
	0x00 } } },
	{ 116, 5580, { {
	0x00 } } },
	{ 118, 5590, { {
	0x00 } } },
	{ 120, 5600, { {
	0x00 } } },
	{ 122, 5610, { {
	0x00 } } },
	{ 124, 5620, { {
	0x00 } } },
	{ 126, 5630, { {
	0x00 } } },
	{ 128, 5640, { {
	0x00 } } },
	{ 130, 5650, { {
	0x00 } } },
	{ 132, 5660, { {
	0x00 } } },
	{ 134, 5670, { {
	0x00 } } },
	{ 136, 5680, { {
	0x00 } } },
	{ 138, 5690, { {
	0x00 } } },
	{ 140, 5700, { {
	0x00 } } },
	{ 142, 5710, { {
	0x00 } } },
	{ 144, 5720, { {
	0x00 } } },
	{ 145, 5725, { {
	0x00 } } },
	{ 146, 5730, { {
	0x00 } } },
	{ 147, 5735, { {
	0x00 } } },
	{ 148, 5740, { {
	0x00 } } },
	{ 149, 5745, { {
	0x00 } } },
	{ 151, 5755, { {
	0x00 } } },
	{ 153, 5765, { {
	0x00 } } },
	{ 155, 5775, { {
	0x00 } } },
	{ 157, 5785, { {
	0x00 } } },
	{ 159, 5795, { {
	0x00 } } },
	{ 161, 5805, { {
	0x00 } } },
	{ 163, 5815, { {
	0x00 } } },
	{ 165, 5825, { {
	0x00 } } },
	{ 1, 2412, { {
	0x00 } } },
	{ 2, 2417, { {
	0x00 } } },
	{ 3, 2422, { {
	0x00 } } },
	{ 4, 2427, { {
	0x00 } } },
	{ 5, 2432, { {
	0x00 } } },
	{ 6, 2437, { {
	0x00 } } },
	{ 7, 2442, { {
	0x00 } } },
	{ 8, 2447, { {
	0x00 } } },
	{ 9, 2452, { {
	0x00 } } },
	{ 10, 2457, { {
	0x00 } } },
	{ 11, 2462, { {
	0x00 } } },
	{ 12, 2467, { {
	0x00 } } },
	{ 13, 2472, { {
	0x00 } } },
	{ 14, 2484, { {
	0x00 } } },
};

const uint16 chan_tune_20704_rev0_length = ARRAYSIZE(chan_tune_20704_rev0);

/* 2G LNA1 and Gm Gain dB table for 63178 */
int8 BCMATTACHDATA(lna12_gain_tbl_2g_20704rX)[2][N_LNA12_GAINS] = {
	{ -7, -2, 5, 11, 17, 17}, /* LNA1 Table */
	{  0,  0, 0,  0}          /* Gm Table */
};

/* 2G LNA1 and Gm Gain bits table for 63178 */
int8 BCMATTACHDATA(lna12_gainbits_tbl_2g_20704rX)[2][N_LNA12_GAINS] = {
	{0, 1, 2, 3, 4, 4, 6}, /* LNA1 Table */
	{3, 3, 3, 3}           /* Gm Table */
};

/* 5G LNA1 and Gm Gain dB table for 63178 */
int8 BCMATTACHDATA(lna12_gain_tbl_5g_20704rX)[2][N_LNA12_GAINS] = {
	{-8, -3, 3, 9, 14, 14}, /* LNA1 Table */
	{ 4,  4, 4, 4}          /* Gm Table */
};

/* 5G LNA1 and Gm Gain bits table for 63178 */
int8 BCMATTACHDATA(lna12_gainbits_tbl_5g_20704rX)[2][N_LNA12_GAINS] = {
	{0, 1, 2, 3, 4, 4, 6}, /* LNA1 Table */
	{3, 3, 3, 3}           /* Gm Table */
};

/* TIA Gain table for 63178
 * Note: last entry is repeated to index 12-15
 * in wlc_phy_rxgainctrl_set_gaintbls_acphy_28nm()
 */
int8 BCMATTACHDATA(tia_gain_tbl_20704rX)[N_TIA_GAINS] =
	{10, 13, 16, 19, 22, 25, 28, 28, 28, 28, 28, 28};

/* TIA GainBits table for 63178
 * Note: last entry is repeated to index 12-15
 * in wlc_phy_rxgainctrl_set_gaintbls_acphy_28nm()
 */
int8 BCMATTACHDATA(tia_gainbits_tbl_20704rX)[N_TIA_GAINS] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 15};

/* LPF Gain table for 63178 */
int8 BCMATTACHDATA(biq01_gain_tbl_20704rX)[2][N_BIQ01_GAINS] = {
	{0, 3, 6, 9, 9, 9}, /* BIQ0 is LPF */
	{0, 0, 0, 0, 0, 0}  /* BIQ1 does not exist */
};

/* LPF GainBits table for 63178 */
int8 BCMATTACHDATA(biq01_gainbits_tbl_20704rX)[2][N_BIQ01_GAINS] = {
	{0, 1, 2, 3, 3, 3}, /* BIQ0 is LPF */
	{0, 0, 0, 0, 0, 0}  /* BIQ1 does not exist */
};

/* LNA1 gm and rout mapping table for 63178 */
uint8 BCMATTACHDATA(lna1_rout_map_2g_20704rX)[N_LNA12_GAINS] = { 10, 10,  9, 10, 7, 7};
uint8 BCMATTACHDATA(lna1_gain_map_2g_20704rX)[N_LNA12_GAINS] = {  2,  3,  4,  5, 5, 5};
uint8 BCMATTACHDATA(lna1_rout_map_5g_20704rX)[N_LNA12_GAINS] = { 10, 10,  9, 10, 7, 7};
uint8 BCMATTACHDATA(lna1_gain_map_5g_20704rX)[N_LNA12_GAINS] = {  4,  5,  6,  7, 7, 7};

/* Gain limit table for 63178
 * Note: last entry is repeated to index 12-15
 * in wlc_phy_rxgainctrl_set_gaintbls_acphy_28nm()
 */
int8 BCMATTACHDATA(gainlimit_tbl_20704rX)[RXGAIN_CONF_ELEMENTS][MAX_RX_GAINS_PER_ELEM] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* LNA1 Table */
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* Gm Table */
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127}, /* TIA Table */
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* LPF Table */
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

/* Napping related tables */
uint16 BCMATTACHDATA(nap_lo_th_adj_maj51)[5] = {10, 10, 10, 10, 10};
uint16 BCMATTACHDATA(nap_hi_th_adj_maj51)[5] = {50, 50, 50, 50, 50};
