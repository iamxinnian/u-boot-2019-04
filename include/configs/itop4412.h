/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011 Samsung Electronics
 *
 * Configuration settings for the SAMSUNG ITOP4412 (EXYNOS4412) board.
 */

#ifndef __CONFIG_ITOP4412_H
#define __CONFIG_ITOP4412_H

#include <configs/exynos4-common.h>

/* High Level Configuration Options */
#define CONFIG_EXYNOS4412		1	/* which is a EXYNOS44120 SoC */
#define CONFIG_ITOP4412			1	/* working with itop4412*/
#define CONFIG_SUPPORT_EMMC_BOOT	1

/* ITOP4412 has 4 bank of DRAM */
#define CONFIG_NR_DRAM_BANKS		4
#define CONFIG_SYS_SDRAM_BASE		0x40000000
#define PHYS_SDRAM_1			CONFIG_SYS_SDRAM_BASE
#define CONFIG_SDRAM_SCP_SIZE_2G

#ifdef CONFIG_SDRAM_SCP_SIZE_1G
#define SDRAM_BANK_SIZE			(256 << 20)	/* 256 MB */
#endif

#ifdef CONFIG_SDRAM_SCP_SIZE_2G
#define SDRAM_BANK_SIZE			(512 << 20)	/* 512 MB */
#endif

/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x6000000)
#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_SDRAM_BASE + 0x3E00000)

#define CONFIG_MACH_TYPE		MACH_TYPE_ITOP4412

/* select serial console configuration */

/* Console configuration */
#define CONFIG_DEFAULT_CONSOLE		"console=ttySAC1,115200n8\0"

#define CONFIG_SYS_MEM_TOP_HIDE	(1 << 20)	/* ram console */

//#define CONFIG_SYS_MONITOR_BASE	0x00000000

/* Power Down Modes */
#define S5P_CHECK_SLEEP			0x00000BAD
#define S5P_CHECK_DIDLE			0xBAD00000
#define S5P_CHECK_LPA			0xABAD0000

/* MMC SPL */
#define CONFIG_SPL_TEXT_BASE	0x02023400
#define CONFIG_EXTRA_ENV_SETTINGS \
	"loadaddr=0x40007000\0" \
	"rdaddr=0x48000000\0" \
	"kerneladdr=0x40007000\0" \
	"ramdiskaddr=0x48000000\0" \
	"console=ttySAC2,115200n8\0" \
	"mmcdev=0\0" \
	"bootenv=uEnv.txt\0" \
	"dtb_addr=0x41000000\0" \
	"dtb_name=exynos4412-itop-elite.dtb\0" \
	"loadbootenv=load mmc ${mmcdev} ${loadaddr} ${bootenv}\0" \
	"bootargs=root=/dev/mmcblk1p2 rw console=ttySAC2,115200 init=/linuxrc earlyprintk\0" \
	"importbootenv=echo Importing environment from mmc ...; " \
	"env import -t $loadaddr $filesize\0" \
    "loadbootscript=load mmc ${mmcdev} ${loadaddr} boot.scr\0" \
    "bootscript=echo Running bootscript from mmc${mmcdev} ...; " \
    "source ${loadaddr}\0"
#define CONFIG_BOOTCOMMAND \
	"if mmc rescan; then " \
		"echo SD/MMC found on device ${mmcdev};" \
		"if run loadbootenv; then " \
			"echo Loaded environment from ${bootenv};" \
			"run importbootenv;" \
		"fi;" \
		"if test -n $uenvcmd; then " \
			"echo Running uenvcmd ...;" \
			"run uenvcmd;" \
		"fi;" \
		"if run loadbootscript; then " \
			"run bootscript; " \
		"fi; " \
	"fi;" \
	"mmc read ${loadaddr} 0x460 0x5000; mmc read ${dtb_addr} 0x5460 0xa0; bootm ${loadaddr} - ${dtb_addr}" \
	"load mmc ${mmcdev} ${loadaddr} uImage; load mmc ${mmcdev} ${dtb_addr} ${dtb_name}; bootm ${loadaddr} - ${dtb_addr}"

#define CONFIG_CLK_1000_400_200

/* MIU (Memory Interleaving Unit) */

#define CONFIG_SYS_MMC_ENV_DEV		(0)
#define CONFIG_ENV_SIZE			(8 << 10)	/* 16 KB */
#define RESERVE_BLOCK_SIZE		(512)
#define BL1_SIZE			(8 << 10) /*8 K reserved for BL1*/
#define BL2_SIZE			(16 << 10) /*16 K reserved for BL1*/
#define CONFIG_ENV_OFFSET		(RESERVE_BLOCK_SIZE + BL1_SIZE + BL2_SIZE +COPY_BL2_SIZE)

#define CONFIG_SPL_MAX_FOOTPRINT	(14 * 1024)
#define UBOOT_SIZE		(2<< 20)
#define CONFIG_SYS_INIT_SP_ADDR		0x02040000
/* U-Boot copy size from boot Media to DRAM.*/
#define COPY_BL2_SIZE		0x80000
#define BL2_START_OFFSET	((RESERVE_BLOCK_SIZE + BL1_SIZE + BL2_SIZE)/512)
#define BL2_SIZE_BLOC_COUNT	(COPY_BL2_SIZE/512)
/* USB */
#define CONFIG_USB_EHCI_EXYNOS

#endif	/* __CONFIG_H */
