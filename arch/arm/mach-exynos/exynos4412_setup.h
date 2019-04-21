/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Machine Specific Values for EXYNOS4012 based board
 *
 * Copyright (C) 2011 Samsung Electronics
 */

#ifndef _ITOP4412_SETUP_H
#define _ITOP4412_SETUP_H

#include <config.h>
#include <asm/arch/cpu.h>

#ifdef CONFIG_CLK_800_330_165
#define DRAM_CLK_330
#endif
#ifdef CONFIG_CLK_1000_200_200
#define DRAM_CLK_200
#endif
#ifdef CONFIG_CLK_1000_330_165
#define DRAM_CLK_330
#endif
#ifdef CONFIG_CLK_1000_400_200
#define DRAM_CLK_400
#endif

/* Bus Configuration Register Address */
#define ASYNC_CONFIG		0x10010350

/* Required period to generate a stable clock output */
/* APLL_LOCK_TIME */
#define APLL_LOCKTIME		0x960

/* MPLL_LOCK_TIME */
#define MPLL_LOCKTIME		0x190

/* EPLL_LOCK_TIME */
#define EPLL_LOCKTIME		0xBB8

/* VPLL_LOCK_TIME */
#define VPLL_LOCKTIME		0x190

/* APLL_CON0 APLL=1GHz=1000MHz*/
#define APLL_MDIV		0x7D
#define APLL_PDIV		0x3
#define APLL_SDIV		0x0
#define APLL_CON0_VAL		SET_PLL(APLL_MDIV, APLL_PDIV, APLL_SDIV)

/* APLL_CON1 I Default */
#define APLL_AFC_ENB		0x0
#define APLL_AFC		0x0
#define APLL_CON1_VAL		0X00803800

/* MPLL_CON0 MPLL=800MHz*/
#define MPLL_MDIV		0x64
#define MPLL_PDIV		0x3
#define MPLL_SDIV		0x0
#define MPLL_CON0_VAL		SET_PLL(MPLL_MDIV, MPLL_PDIV, MPLL_SDIV)

/* MPLL_CON1 I Default */
#define MPLL_AFC_ENB		0x0
#define MPLL_AFC		0x0
#define MPLL_CON1_VAL		0x00803800

/* EPLL_CON0 EPLL=400MHz*/
#define EPLL_MDIV		0x64
#define EPLL_PDIV		0x3
#define EPLL_SDIV		0x1
#define EPLL_CON0_VAL		SET_PLL(EPLL_MDIV, EPLL_PDIV, EPLL_SDIV)

/* EPLL_CON1 I Default */
#define EPLL_K			0x0
#define EPLL_CON1_VAL		0x66010000

/* EPLL_CON2 I Default */
#define EPLL_CON2_VAL		0x00000080

/* VPLL_CON0 VPLL=100MHz */
#define VPLL_MDIV		0x64
#define VPLL_PDIV		0x3
#define VPLL_SDIV		0x3
#define VPLL_CON0_VAL		SET_PLL(VPLL_MDIV, VPLL_PDIV, VPLL_SDIV)

/* VPLL_CON1 I Default */
#define VPLL_SSCG_EN		DISABLE
#define VPLL_SEL_PF_DN_SPREAD	0x3
#define VPLL_MRR		0x6
#define VPLL_MFR		0x1
#define VPLL_K			0x6000
#define VPLL_CON1_VAL		((VPLL_SSCG_EN << 31)\
				| (VPLL_SEL_PF_DN_SPREAD << 29) \
				| (VPLL_MRR << 24) \
				| (VPLL_MFR << 16) \
				| (VPLL_K << 0))

/* VPLL_CON2 I Default */
#define VPLL_CON2_EXTAFC	0x0
#define VPLL_CON2_DCC_ENB	0x1
#define VPLL_CON2_AFC_ENB	0x0
#define VPLL_CON2_SSCG_EN	0x0
#define VPLL_CON2_BYPASS	0x0
#define VPLL_CON2_FVCO_EN	0x0
#define VPLL_CON2_FSEL		0x0
#define VPLL_CON2_ICP_BOOST	0x0

#define VPLL_CON2_VAL	((VPLL_CON2_EXTAFC <<8) \
			| (VPLL_CON2_DCC_ENB <<7) \
			| (VPLL_CON2_AFC_ENB << 6) \
			| (VPLL_CON2_SSCG_EN << 5) \
			| (VPLL_CON2_BYPASS << 4) \
			| (VPLL_CON2_FVCO_EN << 3) \
			| (VPLL_CON2_FSEL << 2) \
			| (VPLL_CON2_ICP_BOOST << 0))	

/* CLK_SRC_CPU */
#define MUX_MPLL_SEL_FILPLL		0x0
#define MUX_MPLL_SEL_FOUTMPLL		0x1
#define MUX_HPM_SEL_MOUTAPLL		0x0
#define MUX_HPM_SEL_SCLKMPLL		0x1
#define MUX_CORE_SEL_MOUTAPLL		0x0
#define MUX_CORE_SEL_SCLKMPLL		0x1
#define MUX_APLL_SEL_FILPLL		0x0
#define MUX_APLL_SEL_MOUTMPLLFOUT	0x1
#define CLK_SRC_CPU_VAL			((MUX_MPLL_SEL_FOUTMPLL << 24) \
					| (MUX_HPM_SEL_MOUTAPLL << 20) \
					| (MUX_CORE_SEL_MOUTAPLL << 16)\
					| (MUX_APLL_SEL_MOUTMPLLFOUT << 0))

/* CLK_SRC_DMC */
#define MUX_G2D_ACP_SEL_MOUTG2D_ACP_0		0x0
#define MUX_G2D_ACP_SEL_MOUTG2D_ACP_1		0x1
#define MUX_G2D_ACP_1_SEL_SCLKEPLL		0x0
#define MUX_G2D_ACP_1_SEL_SCLKVPLL		0x1
#define MUX_G2D_ACP_0_SEL_SCLKMPLL		0x0
#define MUX_G2D_ACP_0_SEL_SCLKAPLL		0x1
#define MUX_PWI_SEL_XXTI			0x0
#define MUX_PWI_SEL_XUSBXTI			0x1
#define MUX_PWI_SEL_SCLK_HDMI24M		0x2
#define MUX_PWI_SEL_SCLK_USBPHY0		0x3
#define MUX_PWI_SEL_SCLK_USBPHY1		0x4
#define MUX_PWI_SEL_SCLK_HDMIPHY		0x5
#define MUX_PWI_SEL_SCLKMPLL			0x6
#define MUX_PWI_SEL_SCLKEPLL			0x7
#define MUX_PWI_SEL_SCLKVPLL			0x8
#define MUX_MPLL_SEL_FINPLL			0x0
#define MUX_MPLL_SEL_MOUTMPLLFOUT		0x1
#define MUX_DPHY_SEL_SCLKMPLL			0x0
#define MUX_DPHY_SEL_SCLKAPLL			0x1
#define MUX_DMC_BUS_SEL_SCLKMPLL		0x0
#define MUX_DMC_BUS_SEL_SCLKAPLL		0x1
#define MUX_C2C_SEL_SCLKMPLL			0x0
#define MUX_C2C_SEL_SCLKAPLL			0x1
#define CLK_SRC_DMC_VAL			((MUX_G2D_ACP_SEL_MOUTG2D_ACP_0 << 28)\
					| (MUX_G2D_ACP_1_SEL_SCLKEPLL << 24) \
					| (MUX_G2D_ACP_0_SEL_SCLKMPLL << 20) \
					| (MUX_PWI_SEL_XUSBXTI << 16) \
					| (MUX_MPLL_SEL_MOUTMPLLFOUT << 12) \
					| (MUX_DPHY_SEL_SCLKMPLL << 8) \
					| (MUX_DMC_BUS_SEL_SCLKMPLL << 4) \
					| (MUX_C2C_SEL_SCLKMPLL << 0))

/* CLK_SRC_TOP0 */
#define MUX_ONENAND_SEL_ACLK_133	0x0
#define MUX_ONENAND_SEL_ACLK_160	0x1
#define MUX_ACLK_133_SEL_SCLKMPLL	0x0
#define MUX_ACLK_133_SEL_SCLKAPLL	0x1
#define MUX_ACLK_160_SEL_SCLKMPLL	0x0
#define MUX_ACLK_160_SEL_SCLKAPLL	0x1
#define MUX_ACLK_100_SEL_SCLKMPLL	0x0
#define MUX_ACLK_100_SEL_SCLKAPLL	0x1
#define MUX_ACLK_200_SEL_SCLKMPLL	0x0
#define MUX_ACLK_200_SEL_SCLKAPLL	0x1
#define MUX_VPLL_SEL_FINPLL		0x0
#define MUX_VPLL_SEL_FOUTVPLL		0x1
#define MUX_EPLL_SEL_FINPLL		0x0
#define MUX_EPLL_SEL_FOUTEPLL		0x1
#define MUX_ONENAND_1_SEL_MOUTONENAND	0x0
#define MUX_ONENAND_1_SEL_SCLKVPLL	0x1
#define CLK_SRC_TOP0_VAL		((MUX_ONENAND_SEL_ACLK_133 << 28) \
					| (MUX_ACLK_133_SEL_SCLKMPLL << 24) \
					| (MUX_ACLK_160_SEL_SCLKMPLL << 20) \
					| (MUX_ACLK_100_SEL_SCLKMPLL << 16) \
					| (MUX_ACLK_200_SEL_SCLKMPLL << 12) \
					| (MUX_VPLL_SEL_FOUTVPLL << 8) \
					| (MUX_EPLL_SEL_FOUTEPLL << 4)\
					| (MUX_ONENAND_1_SEL_MOUTONENAND << 0))

/* CLK_SRC_TOP1 */
#define MUX_ACLK_400_MCUISP_SUB_SEL_FINPLL			0x0
#define MUX_ACLK_400_MCUISP_SUB_SEL_DIVOUT_ACLK_400_MCUISP	0x1
#define MUX_ACLK_200_SUB_SEL_FINPLL				0x0
#define MUX_ACLK_200_SUB_SEL_DIVOUT_ACLK_200			0x1
#define MUX_ACLK_266_GPS_SUB_SEL_FINPLL				0x0
#define MUX_ACLK_266_GPS_SUB_SEL_DIVOUT_ACLK_266_GPS		0x1
#define MUX_MPLL_USER_SEL_T_FINPLL				0x0
#define MUX_MPLL_USER_SEL_T_SCLKMPLL				0x1
#define MUX_ACLK_400_MCUISP_SEL_SCLKMPLL_USER_T			0x0
#define MUX_ACLK_400_MCUISP_SEL_SCLKAPLL			0x1
#define MUX_ACLK_266_GPS_SEL_SCLKMPLL_USER_T			0x0
#define MUX_ACLK_266_GPS_SEL_SCLKAPLL				0x1
#define CLK_SRC_TOP1_VAL	((MUX_ACLK_400_MCUISP_SUB_SEL_DIVOUT_ACLK_400_MCUISP << 24) \
				| (MUX_ACLK_200_SUB_SEL_DIVOUT_ACLK_200 << 20) \
				| (MUX_ACLK_266_GPS_SUB_SEL_DIVOUT_ACLK_266_GPS << 16) \
				| (MUX_MPLL_USER_SEL_T_SCLKMPLL << 12) \
				| (MUX_ACLK_400_MCUISP_SEL_SCLKMPLL_USER_T << 8) \
				| (MUX_ACLK_266_GPS_SEL_SCLKMPLL_USER_T << 4))

/* CLK_SRC_LEFTBUS */
#define MUX_MPLL_USER_SEL_L_FINPLL	0x0
#define MUX_MPLL_USER_SEL_L_FOUTMPLL	0x1
#define MUX_GDL_SEL_SCLKMPLL		0x0
#define MUX_GDL_SEL_SCLKAPLL		0x1
#define CLK_SRC_LEFTBUS_VAL	((MUX_MPLL_USER_SEL_L_FOUTMPLL << 4) | (MUX_GDL_SEL_SCLKMPLL << 0))

/* CLK_SRC_RIGHTBUS */
#define MUX_MPLL_USER_SEL_R_FINPLL	0x0
#define MUX_MPLL_USER_SEL_R_FOUTMPLL	0x1
#define MUX_GDR_SEL_SCLKMPLL		0x0
#define MUX_GDR_SEL_SCLKAPLL		0x1
#define CLK_SRC_RIGHTBUS_VAL	((MUX_MPLL_USER_SEL_R_FOUTMPLL << 4) | (MUX_GDR_SEL_SCLKMPLL << 0))
/* CLK_SRC_FSYS: 6 = SCLKMPLL */
#define MIPIHSI_SEL_SCLKMPLL_USER_T	0
#define MIPIHSI_SEL_SCLKAPLL		1

#define MMC_SEL_XXTI			0
#define MMC_SEL_XUSBXTI			1
#define MMC_SEL_SCLK_HDMI24M		2
#define MMC_SEL_SCLK_USBPHY0		3
#define MMC_SEL_SCLK_USBPHY1		4
#define MMC_SEL_SCLK_HDMIPHY		5
#define MMC_SEL_SCLKMPLL_USER_T		6
#define MMC_SEL_SCLKEPLL		7
#define MMC_SEL_SCLKVPLL		8

#define MMCC0_SEL			MMC_SEL_SCLKMPLL_USER_T
#define MMCC1_SEL			MMC_SEL_SCLKMPLL_USER_T
#define MMCC2_SEL			MMC_SEL_SCLKMPLL_USER_T
#define MMCC3_SEL			MMC_SEL_SCLKMPLL_USER_T
#define MMCC4_SEL			MMC_SEL_SCLKMPLL_USER_T
#define CLK_SRC_FSYS_VAL	((MIPIHSI_SEL_SCLKMPLL_USER_T << 24) \
				| (MMCC4_SEL << 16) \
				| (MMCC3_SEL << 12) \
				| (MMCC2_SEL << 8) \
				| (MMCC1_SEL << 4) \
				| (MMCC0_SEL << 0))

/* CLK_SRC_PERIL0 */
#define UART_SEL_XXTI		0
#define UART_SEL_XUSBXTI	1
#define UART_SEL_SCLK_HDMI24M	2
#define UART_SEL_SCLK_USBPHY0	3
#define UART_SEL_SCLK_USBPHY1	4
#define UART_SEL_SCLK_HDMIPHY	5
#define UART_SEL_SCLKMPLL	6
#define UART_SEL_SCLKEPLL	7
#define UART_SEL_SCLKVPLL	8

#define UART0_SEL		UART_SEL_SCLKMPLL
#define UART1_SEL		UART_SEL_SCLKMPLL
#define UART2_SEL		UART_SEL_SCLKMPLL
#define UART3_SEL		UART_SEL_SCLKMPLL
#define UART4_SEL		UART_SEL_SCLKMPLL
#define CLK_SRC_PERIL0_VAL	((UART4_SEL << 16) \
				| (UART3_SEL << 12) \
				| (UART2_SEL << 8) \
				| (UART1_SEL << 4) \
				| (UART0_SEL << 0))

/* CLK_SRC_PERIL1 */
#define SPI_SEL_XXTI		0
#define SPI_SEL_XUSBXTI		1
#define SPI_SEL_SCLK_HDMI24M	2
#define SPI_SEL_SCLK_USBPHY0	3
#define SPI_SEL_SCLK_USBPHY1	4
#define SPI_SEL_SCLK_HDMIPHY	5
#define SPI_SEL_SCLKMPLL	6
#define SPI_SEL_SCLKEPLL	7
#define SPI_SEL_SCLKVPLL	8

#define SPDIF_SEL_SCLK_AUDIO0	0
#define SPDIF_SEL_SCLK_AUDIO1	1
#define SPDIF_SEL_SCLK_AUDIO2	2
#define SPDIF_SEL_SPDIF_EXTCLK	3

#define AUDIOx_SEL_AUDIOCDCLKx	0
#define AUDIOx_SEL_Reserved	1
#define AUDIOx_SEL_SCLK_HDMI24M	2
#define AUDIOx_SEL_SCLK_USBPHY0 3
#define AUDIOx_SEL_XXTI		4
#define AUDIOx_SEL_XUSBXTI	5
#define AUDIOx_SEL_SCLKMPLL	6
#define AUDIOx_SEL_SCLKEPLL	7
#define AUDIOx_SEL_SCLKVPLL	8


#define AUDIO1_SEL		AUDIOx_SEL_SCLKEPLL
#define AUDIO2_SEL		AUDIOx_SEL_SCLKEPLL
#define SPDIF_SEL		SPDIF_SEL_SCLK_AUDIO0
#define SPI0_SEL		UART_SEL_SCLKMPLL
#define SPI1_SEL		UART_SEL_SCLKMPLL
#define SPI2_SEL		UART_SEL_SCLKMPLL
#define CLK_SRC_PERIL1_VAL	((SPI2_SEL << 24) \
				| (SPI1_SEL << 20) \
				| (SPI0_SEL << 16) \
				| (SPDIF_SEL << 8) \
				| (AUDIO2_SEL << 4) \
				| (AUDIO1_SEL << 0))

/* Clock Source CAM/FIMC */
/* CLK_SRC_CAM0 */

#define CAM0_SEL_XXTI			0x0
#define CAM0_SEL_XUSBXTI		0x1
#define CAM0_SEL_SCLK_HDMI24M		0x2
#define CAM0_SEL_SCLK_USBPHY0		0x3
#define CAM0_SEL_SCLK_USBPHY1		0x4
#define CAM0_SEL_SCLK_HDMIPHY		0x5
#define CAM0_SEL_SCLKMPLL		0x6
#define CAM0_SEL_SCLKEPLL		0x7
#define CAM0_SEL_SCLKVPLL		0x8

#define CSIS1_SEL		CAM0_SEL_SCLKMPLL
#define CSIS0_SEL		CAM0_SEL_SCLKMPLL
#define CAM1_SEL		CAM0_SEL_SCLKMPLL
#define CAM0_SEL		CAM0_SEL_SCLKMPLL
#define FIMC3_LCLK_SEL		CAM0_SEL_SCLKMPLL
#define FIMC2_LCLK_SEL		CAM0_SEL_SCLKMPLL
#define FIMC1_LCLK_SEL		CAM0_SEL_SCLKMPLL
#define FIMC0_LCLK_SEL		CAM0_SEL_SCLKMPLL

#define CLK_SRC_CAM0_VAL	((CSIS1_SEL << 28) \
				| (CSIS0_SEL << 24) \
				| (CAM1_SEL << 20) \
				| (CAM0_SEL << 16) \
				| (FIMC3_LCLK_SEL << 12) \
				| (FIMC2_LCLK_SEL << 8) \
				| (FIMC1_LCLK_SEL << 4) \
				| (FIMC0_LCLK_SEL << 0))
/* CLK_SRC_CAM1 */

#define JPEG_SEL_MOUTJPEG_0	0
#define JPEG_SEL_MOUTJPEG_1	1
#define JPEG_1_SEL_SCLKEPLL	0
#define JPEG_1_SEL_SCLKVPLL	1
#define JPEG_0_SEL_SCLKMPLL	0
#define JPEG_0_SEL_SCLKAPLL	1

#define CLK_SRC_CAM1_VAL ((JPEG_0_SEL_SCLKMPLL << 0) \
			| (JPEG_1_SEL_SCLKEPLL << 4) \
			| (JPEG_SEL_MOUTJPEG_0 << 8))

/* SCLK MFC */
/* CLK_SRC_MFC */
#define MFC_SEL_MPLL		0
#define MFC_SEL_APLL		1
#define MFC_SEL_EPLL		0
#define MFC_SEL_VPLL		1
#define MFC_MOUTMFC_0		0
#define MFC_MOUTMFC_1		1

#define MFC_SEL			MFC_MOUTMFC_0
#define MFC_1_SEL		MFC_SEL_EPLL
#define MFC_0_SEL		MFC_SEL_MPLL
#define CLK_SRC_MFC_VAL		((MFC_SEL << 8) | (MFC_1_SEL <<4) | (MFC_0_SEL))

/* SCLK G3D */
/* CLK_SRC_G3D */
#define G3D_SEL_MPLL		0
#define MOUTG3D_0		0
#define G3D_SEL			MOUTG3D_0
#define G3D_0_SEL		G3D_SEL_MPLL
#define CLK_SRC_G3D_VAL		((G3D_SEL << 8) | (G3D_0_SEL))

/* SCLK LCD */
/* CLK_SRC_LCD */
#define FIMD_SEL_SCLKMPLL	6
#define MDNIE0_SEL_SCLKMPLL	6
#define MDNIE_PWM0_SEL_SCLKMPLL	6
#define MIPI0_SEL_SCLKMPLL	6
#define CLK_SRC_LCD_VAL	((MIPI0_SEL_SCLKMPLL << 12) \
				| (MDNIE_PWM0_SEL_SCLKMPLL << 8) \
				| (MDNIE0_SEL_SCLKMPLL << 4) \
				| (FIMD_SEL_SCLKMPLL << 0))

/* CLK_SRC_TV */
#define HDMI_SEL_SCLK_PIXEL	0x0
#define HDMI_SEL_SCLK_HDMIPHY	0x1
#define CLK_SRC_TV_VAL		(HDMI_SEL_SCLK_PIXEL << 0)

/* CLK_SRC_MAUDIO */
#define AUDIO0_SEL_SCLK_EPLL	0x7
#define CLK_SRC_MAUDIO_VAL	(AUDIO0_SEL_SCLK_EPLL << 0)

/* CLK_SRC_ISP */
#define UART_ISP_SEL_SCLKMPLL	0x6
#define SPI1_ISP_SEL_SCLKMPLL	0x6
#define SPI0_ISP_SEL_SCLKMPLL	0x6
#define PWM_ISP_SEL_SCLKMPLL	0x6
#define CLK_SRC_ISP_VAL		((UART_ISP_SEL_SCLKMPLL << 12) \
				| (SPI1_ISP_SEL_SCLKMPLL << 8) \
				| (SPI0_ISP_SEL_SCLKMPLL << 4) \
				| (PWM_ISP_SEL_SCLKMPLL << 0))

/* CLK_DIV_CPU0 */
#define CORE2_RATIO		0x0
#define APLL_RATIO		0x1
#define PCLK_DBG_RATIO		0x1
#define ATB_RATIO		0x4
#define PERIPH_RATIO		0x3
#define COREM1_RATIO		0x7
#define COREM0_RATIO		0x3
#define CORE_RATIO		0x0
#define CLK_DIV_CPU0_VAL	((CORE2_RATIO << 28) \
				| (APLL_RATIO << 24) \
				| (PCLK_DBG_RATIO << 20) \
				| (ATB_RATIO << 16) \
				| (PERIPH_RATIO << 12) \
				| (COREM1_RATIO << 8) \
				| (COREM0_RATIO << 4) \
				| (CORE_RATIO << 0))

/* CLK_DIV_CPU1 */
#define CORES_RATIO		0x0
#define HPM_RATIO		0x0
#define COPY_RATIO		0x4
#define CLK_DIV_CPU1_VAL	((CORES_RATIO << 8) | (HPM_RATIO << 4) | (COPY_RATIO))

/* CLK_DIV_DMC0 */
#define DMCP_RATIO		0x1
#define DMCD_RATIO		0x1
#define DMC_RATIO		0x1
#define DPHY_RATIO		0x1
#define ACP_PCLK_RATIO		0x1
#define ACP_RATIO		0x3
#define CLK_DIV_DMC0_VAL	((DMCP_RATIO << 20) \
				| (DMCD_RATIO << 16) \
				| (DMC_RATIO << 12) \
				| (DPHY_RATIO << 8) \
				| (ACP_PCLK_RATIO << 4)	\
				| (ACP_RATIO << 0))

/* CLK_DIV_DMC1 */
#define DPM_RATIO		0x1
#define DVSEM_RATIO		0x1
#define C2C_ACLK_RATIO		0x1
#define PWI_RATIO		0x1
#define C2C_RATIO		0x1
#define G2D_ACP_RATIO		0x3
#define CLK_DIV_DMC1_VAL	((DPM_RATIO << 24) \
				| (DVSEM_RATIO << 16) \
				| (C2C_ACLK_RATIO << 12) \
				| (PWI_RATIO << 8) \
				| (C2C_RATIO << 4) \
				| (G2D_ACP_RATIO << 0))

/* CLK_DIV_TOP */
#define ACLK_400_MCUISP_RATIO		0x1
#define ACLK_266_GPS_RATIO		0x2
#define ONENAND_RATIO			0x0
#define ACLK_133_RATIO			0x5
#define ACLK_160_RATIO			0x4
#define ACLK_100_RATIO			0x7
#define ACLK_200_RATIO			0x3
#define CLK_DIV_TOP_VAL		((ACLK_400_MCUISP_RATIO << 24)	\
				| (ACLK_266_GPS_RATIO << 20)\
				| (ONENAND_RATIO << 16)\
				| (ACLK_133_RATIO << 12)\
				| (ACLK_160_RATIO << 8)	\
				| (ACLK_100_RATIO << 4)	\
				| (ACLK_200_RATIO << 0))

/* CLK_DIV_LEFTBUS */
#define GPL_RATIO		0x1
#define GDL_RATIO		0x3
#define CLK_DIV_LEFTBUS_VAL	((GPL_RATIO << 4) | (GDL_RATIO))

/* CLK_DIV_RIGHTBUS */
#define GPR_RATIO		0x1
#define GDR_RATIO		0x3
#define CLK_DIV_RIGHTBUS_VAL	((GPR_RATIO << 4) | (GDR_RATIO))

/* SCLK_MMC[0-4] = MOUTMMC[0-4]/(MMC[0-4]_RATIO + 1)/(MMC[0-4]_PRE_RATIO +1) */
/* CLK_DIV_FSYS0 */
#define MIPIHSI_RATIO		0x3
#define CLK_DIV_FSYS0_VAL	(MIPIHSI_RATIO << 20)

/* CLK_DIV_FSYS1 */
#define MMC0_RATIO		0x0
#define MMC0_PRE_RATIO		0xF
#define MMC1_RATIO		0x0
#define MMC1_PRE_RATIO		0xF
#define CLK_DIV_FSYS1_VAL	((MMC1_PRE_RATIO << 24) \
				| (MMC1_RATIO << 16) \
				| (MMC0_PRE_RATIO << 8) \
				| (MMC0_RATIO << 0))

/* CLK_DIV_FSYS2 */
#define MMC2_RATIO		0x0
#define MMC2_PRE_RATIO		0xF
#define MMC3_RATIO		0x0
#define MMC3_PRE_RATIO		0xF
#define CLK_DIV_FSYS2_VAL	((MMC3_PRE_RATIO << 24) \
				| (MMC3_RATIO << 16) \
				| (MMC2_PRE_RATIO << 8) \
				| (MMC2_RATIO << 0))

/* CLK_DIV_FSYS3 */
#define MMC4_RATIO		0x0
#define MMC4_PRE_RATIO		0xF
#define CLK_DIV_FSYS3_VAL	((MMC4_PRE_RATIO << 8) \
				| (MMC4_RATIO << 0))

/* SCLK_UART[0-4] = MOUTUART[0-4]/(UART[0-4]_RATIO + 1) */
/* CLK_DIV_PERIL0 */
#define UART0_RATIO		3
#define UART1_RATIO		3
#define UART2_RATIO		3
#define UART3_RATIO		3
#define UART4_RATIO		3
#define CLK_DIV_PERIL0_VAL	((UART4_RATIO << 16) \
				| (UART3_RATIO << 12) \
				| (UART2_RATIO << 8) \
				| (UART1_RATIO << 4) \
				| (UART0_RATIO << 0))
/* CLK_DIV_PERIL1 */
#define SPI1_PRE_RATIO		7
#define SPI1_RATIO		0
#define SPI0_PRE_RATIO		7
#define SPI0_RATIO		0
#define CLK_DIV_PERIL1_VAL	((SPI1_PRE_RATIO << 24) \
				| (SPI1_RATIO << 16) \
				| (SPI0_PRE_RATIO << 8) \
				| (SPI0_RATIO << 0))

/* CLK_DIV_PERIL2 */
#define SPI2_PRE_RATIO		7
#define SPI2_RATIO		0
#define CLK_DIV_PERIL2_VAL	((SPI2_PRE_RATIO << 8) | (SPI2_RATIO <<0)) 


/* CLK_DIV_PERIL3 */
#define SLIMBUS_RATIO          0xF
#define CLK_DIV_PERIL3_VAL	(SLIMBUS_RATIO << 4) 

/* CLK_DIV_PERIL4 */
#define PCM2_RATIO		0x13
#define AUDIO2_RATIO		0x3
#define PCM1_RATIO		0x13
#define AUDIO1_RATIO		0x3
#define CLK_DIV_PERIL4_VAL	((SLIMBUS_RATIO << 20) \
	       			| (AUDIO2_RATIO << 16) \
				| (PCM1_RATIO <<4) \
				| (AUDIO1_RATIO <<0))	

/* CLK_DIV_PERIL5 */
#define I2S2_RATIO		0
#define I2S1_RATIO		0
#define CLK_DIV_PERIL5_VAL	((I2S2_RATIO << 8) | (I2S1_RATIO << 0))

/* SCLK CAM */
/* CLK_DIV_CAM0 */
#define CSIS1_RATIO		4
#define CSIS0_RATIO		4
#define CAM1_RATIO		4
#define CAM0_RATIO		4
#define FIMC3_LCLK_RATIO	4
#define FIMC2_LCLK_RATIO	4
#define FIMC1_LCLK_RATIO	4
#define FIMC0_LCLK_RATIO	4
#define CLK_DIV_CAM0_VAL	((CSIS1_RATIO <<28) \
							| (CSIS0_RATIO <<24) \
							| (CAM0_RATIO <<20) \
							| (CAM0_RATIO <<16) \
							| (FIMC3_LCLK_RATIO << 12) \
							| (FIMC2_LCLK_RATIO << 8) \
							| (FIMC1_LCLK_RATIO << 4) \
							| (FIMC0_LCLK_RATIO << 0))
/* CLK_DIV_CAM1 */
#define JPEG_RATIO		0x4
#define CLK_DIV_CAM1_VAL	(JPEG_RATIO << 0)

/* CLK_DIV_MFC */
#define MFC_RATIO		3
#define CLK_DIV_MFC_VAL		(MFC_RATIO)

/* CLK_DIV_G3D */
#define G3D_RATIO		1
#define CLK_DIV_G3D_VAL		(G3D_RATIO)

/* CLK_DIV_LCD */
#define MIPI0_PRE_RATIO		7
#define MIPI0_RATIO		0
#define MDNIEE_PWM0_PRE_RATIO	7
#define MDNIEE_PWM0_RATIO	0
#define MDNIE0_RATIO		7
#define FIMD0_RATIO		7
#define CLK_DIV_LCD_VAL	((MIPI0_PRE_RATIO <<20) \
				| (MIPI0_RATIO << 16) \
				| (MDNIEE_PWM0_PRE_RATIO << 12) \
				| (MDNIEE_PWM0_RATIO << 8) \
				| (MDNIE0_RATIO << 4) \
				| (FIMD0_RATIO << 0))
/* CLK_DIV_TV */
#define TV_BLK_RATIO		0
#define CLK_DIV_TV_VAL		(TV_BLK_RATIO <<0)

/* CLK_DIV_MAUDIO */
#define PCM0_RATIO		0X13
#define AUDIO0_RATIO		0X3
#define CLK_DIV_MAUDIO_VAL	((PCM0_RATIO <<4) | (AUDIO0_RATIO <<0))

/* CLK_DIV_ISP */
#define	UART_ISP_RATIO		0xB
#define SPI1_ISP_PRE_RATIO	0x7	
#define SPI1_ISP_RATIO		0x0
#define	SPI0_ISP_PRE_RATIO	0x7
#define SPI0_ISP_RATIO		0x0
#define	PWM_ISP_RATIO		0xB
#define CLK_DIV_ISP_VAL		((UART_ISP_RATIO << 28) \
				| (SPI1_ISP_PRE_RATIO << 20) \
				| (SPI1_ISP_RATIO << 16) \
				| (SPI0_ISP_PRE_RATIO << 8) \
				| (SPI0_ISP_RATIO << 4 ) \
				| (PWM_ISP_RATIO << 0))


/* CLK_DIV_ISP0 */
#define ISPDIV1_RATIO		0x0
#define	ISPDV0_RATIO		0xB
#define CLK_DIV_ISP0_VAL	((ISPDIV1_RATIO << 4) | (ISPDV0_RATIO <<0))

/* CLK_DIV_ISP1 */
#define MCUISPDIV1_RATIO		0x0
#define MCUISPDIV0_RATIO		0x0
#define	MPWMDIV_RATIO			0x0
#define CLK_DIV_ISP1_VAL	((MCUISPDIV1_RATIO << 8) | (MCUISPDIV0_RATIO <<4) | (MPWMDIV_RATIO << 0))

/* PLL Values */
#define DISABLE			0
#define ENABLE			1
#define SET_PLL(mdiv, pdiv, sdiv)	((ENABLE << 31)\
					| (mdiv << 16) \
					| (pdiv << 8) \
					| (sdiv << 0))

/* DMC */
#define DIRECT_CMD_NOP	0x07000000
#define DIRECT_CMD_ZQ	0x0a000000
#define DIRECT_CMD_CHIP1_SHIFT	(1 << 20)
#define MEM_TIMINGS_MSR_COUNT	4
#define CTRL_START	(1 << 0)
#define CTRL_DLL_ON	(1 << 1)
#define AREF_EN		(1 << 5)
#define DRV_TYPE	(1 << 6)

struct mem_timings {
	unsigned direct_cmd_msr[MEM_TIMINGS_MSR_COUNT];
	unsigned timingref;
	unsigned timingrow;
	unsigned timingdata;
	unsigned timingpower;
	unsigned zqcontrol;
	unsigned control0;
	unsigned control1;
	unsigned control2;
	unsigned concontrol;
	unsigned prechconfig;
	unsigned memcontrol;
	unsigned memconfig0;
	unsigned memconfig1;
	unsigned dll_resync;
	unsigned dll_on;
};

/* MIU */
/* MIU Config Register Offsets*/
#define APB_SFR_INTERLEAVE_CONF_OFFSET	0x400
#define APB_SFR_ARBRITATION_CONF_OFFSET	0xC00
#define ABP_SFR_SLV_ADDRMAP_CONF_OFFSET	0x800
#define ABP_SFR_INTERLEAVE_ADDRMAP_START_OFFSET	0x808
#define ABP_SFR_INTERLEAVE_ADDRMAP_END_OFFSET	0x810
#define ABP_SFR_SLV0_SINGLE_ADDRMAP_START_OFFSET	0x818
#define ABP_SFR_SLV0_SINGLE_ADDRMAP_END_OFFSET	0x820
#define ABP_SFR_SLV1_SINGLE_ADDRMAP_START_OFFSET	0x828
#define ABP_SFR_SLV1_SINGLE_ADDRMAP_END_OFFSET	0x830

#ifdef CONFIG_ITOP4412
/* Interleave: 2Bit, Interleave_bit1: 0x15, Interleave_bit0: 0x7 */
#define APB_SFR_INTERLEAVE_CONF_VAL	0x20001507
#define APB_SFR_ARBRITATION_CONF_VAL	0x00000001
#endif

#define INTERLEAVE_ADDR_MAP_START_ADDR	0x40000000
#define INTERLEAVE_ADDR_MAP_END_ADDR	0xbfffffff
#define INTERLEAVE_ADDR_MAP_EN		0x00000001

#ifdef CONFIG_MIU_1BIT_INTERLEAVED
/* Interleave_bit0: 0xC*/
#define APB_SFR_INTERLEAVE_CONF_VAL	0x0000000c
#endif
#ifdef CONFIG_MIU_2BIT_INTERLEAVED
/* Interleave: 2Bit, Interleave_bit1: 0x15, Interleave_bit0: 0xc */
#define APB_SFR_INTERLEAVE_CONF_VAL	0x2000150c
#endif
#define SLAVE0_SINGLE_ADDR_MAP_START_ADDR	0x40000000
#define SLAVE0_SINGLE_ADDR_MAP_END_ADDR		0x7fffffff
#define SLAVE1_SINGLE_ADDR_MAP_START_ADDR	0x80000000
#define SLAVE1_SINGLE_ADDR_MAP_END_ADDR		0xbfffffff
/* Enable SME0 and SME1*/
#define APB_SFR_SLV_ADDR_MAP_CONF_VAL		0x00000006

#define FORCE_DLL_RESYNC	3
#define DLL_CONTROL_ON		1

#define DIRECT_CMD1	0x00020000
#define DIRECT_CMD2	0x00030000
#define DIRECT_CMD3	0x00010002
#define DIRECT_CMD4	0x00000328

#define CTRL_ZQ_MODE_NOTERM	(0x1 << 0)
#define CTRL_ZQ_START		(0x1 << 1)
#define CTRL_ZQ_DIV		(0 << 4)
#define CTRL_ZQ_MODE_DDS	(0x7 << 8)
#define CTRL_ZQ_MODE_TERM	(0x2 << 11)
#define CTRL_ZQ_FORCE_IMPN	(0x5 << 14)
#define CTRL_ZQ_FORCE_IMPP	(0x6 << 17)
#define CTRL_DCC		(0xE38 << 20)
#define ZQ_CONTROL_VAL		(CTRL_ZQ_MODE_NOTERM | CTRL_ZQ_START\
				| CTRL_ZQ_DIV | CTRL_ZQ_MODE_DDS\
				| CTRL_ZQ_MODE_TERM | CTRL_ZQ_FORCE_IMPN\
				| CTRL_ZQ_FORCE_IMPP | CTRL_DCC)

#define ASYNC			(0 << 0)
#define CLK_RATIO		(1 << 1)
#define DIV_PIPE		(1 << 3)
#define AWR_ON			(1 << 4)
#define AREF_DISABLE		(0 << 5)
#define DRV_TYPE_DISABLE	(0 << 6)
#define CHIP0_NOT_EMPTY		(0 << 8)
#define CHIP1_NOT_EMPTY		(0 << 9)
#define DQ_SWAP_DISABLE		(0 << 10)
#define QOS_FAST_DISABLE	(0 << 11)
#define RD_FETCH		(0x3 << 12)
#define TIMEOUT_LEVEL0		(0xFFF << 16)
#define CONCONTROL_VAL		(ASYNC | CLK_RATIO | DIV_PIPE | AWR_ON\
				| AREF_DISABLE | DRV_TYPE_DISABLE\
				| CHIP0_NOT_EMPTY | CHIP1_NOT_EMPTY\
				| DQ_SWAP_DISABLE | QOS_FAST_DISABLE\
				| RD_FETCH | TIMEOUT_LEVEL0)

#define CLK_STOP_DISABLE	(0 << 1)
#define DPWRDN_DISABLE		(0 << 2)
#define DPWRDN_TYPE		(0 << 3)
#define TP_DISABLE		(0 << 4)
#define DSREF_DIABLE		(0 << 5)
#define ADD_LAT_PALL		(1 << 6)
#define MEM_TYPE_DDR3		(0x6 << 8)
#define MEM_WIDTH_32		(0x2 << 12)
#define NUM_CHIP_2		(1 << 16)
#define BL_8			(0x3 << 20)
#define MEMCONTROL_VAL		(CLK_STOP_DISABLE | DPWRDN_DISABLE\
				| DPWRDN_TYPE | TP_DISABLE | DSREF_DIABLE\
				| ADD_LAT_PALL | MEM_TYPE_DDR3 | MEM_WIDTH_32\
				| NUM_CHIP_2 | BL_8)


#define CHIP_BANK_8		(0x3 << 0)
#define CHIP_ROW_14		(0x2 << 4)
#define CHIP_COL_10		(0x3 << 8)
#define CHIP_MAP_INTERLEAVED	(1 << 12)
#define CHIP_MASK		(0xe0 << 16)
#ifdef CONFIG_MIU_LINEAR
#define CHIP0_BASE		(0x40 << 24)
#define CHIP1_BASE		(0x60 << 24)
#else
#define CHIP0_BASE		(0x20 << 24)
#define CHIP1_BASE		(0x40 << 24)
#endif
#define MEMCONFIG0_VAL		(CHIP_BANK_8 | CHIP_ROW_14 | CHIP_COL_10\
				| CHIP_MAP_INTERLEAVED | CHIP_MASK | CHIP0_BASE)
#define MEMCONFIG1_VAL		(CHIP_BANK_8 | CHIP_ROW_14 | CHIP_COL_10\
				| CHIP_MAP_INTERLEAVED | CHIP_MASK | CHIP1_BASE)

#define TP_CNT			(0xff << 24)
#define PRECHCONFIG		TP_CNT

#define CTRL_OFF		(0 << 0)
#define CTRL_DLL_OFF		(0 << 1)
#define CTRL_HALF		(0 << 2)
#define CTRL_DFDQS		(1 << 3)
#define DQS_DELAY		(0 << 4)
#define CTRL_START_POINT	(0x10 << 8)
#define CTRL_INC		(0x10 << 16)
#define CTRL_FORCE		(0x71 << 24)
#define CONTROL0_VAL		(CTRL_OFF | CTRL_DLL_OFF | CTRL_HALF\
				| CTRL_DFDQS | DQS_DELAY | CTRL_START_POINT\
				| CTRL_INC | CTRL_FORCE)

#define CTRL_SHIFTC		(0x6 << 0)
#define CTRL_REF		(8 << 4)
#define CTRL_SHGATE		(1 << 29)
#define TERM_READ_EN		(1 << 30)
#define TERM_WRITE_EN		(1 << 31)
#define CONTROL1_VAL		(CTRL_SHIFTC | CTRL_REF | CTRL_SHGATE\
				| TERM_READ_EN | TERM_WRITE_EN)

#define CONTROL2_VAL		0x00000000

#ifdef CONFIG_ITOP4412
#define TIMINGREF_VAL		0x000000BB
#define TIMINGROW_VAL		0x4046654f
#define	TIMINGDATA_VAL		0x46400506
#define	TIMINGPOWER_VAL		0x52000A3C
#else
#define TIMINGREF_VAL		0x000000BC
#ifdef DRAM_CLK_330
#define TIMINGROW_VAL		0x3545548d
#define	TIMINGDATA_VAL		0x45430506
#define	TIMINGPOWER_VAL		0x4439033c
#endif
#ifdef DRAM_CLK_400
#define TIMINGROW_VAL		0x45430506
#define	TIMINGDATA_VAL		0x56500506
#define	TIMINGPOWER_VAL		0x5444033d
#endif
#endif
#endif
