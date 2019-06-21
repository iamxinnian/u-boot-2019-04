// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright 2008 - 2009 Windriver, <www.windriver.com>
 * Author: Tom Rix <Tom.Rix@windriver.com>
 *
 * (C) Copyright 2014 Linaro, Ltd.
 * Rob Herring <robh@kernel.org>
 */
#include <common.h>
#include <command.h>
#include <console.h>
#include <g_dnl.h>
#include <fastboot.h>
#include <net.h>
#include <usb.h>
#include <mmc.h>
#include <fb_mmc.h>
#include <watchdog.h>

static int do_fastboot_udp(int argc, char *const argv[],
			   uintptr_t buf_addr, size_t buf_size)
{
#if CONFIG_IS_ENABLED(UDP_FUNCTION_FASTBOOT)
	int err = net_loop(FASTBOOT);

	if (err < 0) {
		printf("fastboot udp error: %d\n", err);
		return CMD_RET_FAILURE;
	}

	return CMD_RET_SUCCESS;
#else
	pr_err("Fastboot UDP not enabled\n");
	return CMD_RET_FAILURE;
#endif
}

static int do_fastboot_usb(int argc, char *const argv[],
			   uintptr_t buf_addr, size_t buf_size)
{
#if CONFIG_IS_ENABLED(USB_FUNCTION_FASTBOOT)
	int controller_index;
	char *usb_controller;
	char *endp;
	int ret;

	if (argc < 2)
		return CMD_RET_USAGE;

	usb_controller = argv[1];
	controller_index = simple_strtoul(usb_controller, &endp, 0);
	if (*endp != '\0') {
		pr_err("Error: Wrong USB controller index format\n");
		return CMD_RET_FAILURE;
	}

	ret = usb_gadget_initialize(controller_index);
	if (ret) {
		pr_err("USB init failed: %d\n", ret);
		return CMD_RET_FAILURE;
	}

	g_dnl_clear_detach();
	ret = g_dnl_register("usb_dnl_fastboot");
	if (ret)
		return ret;

	if (!g_dnl_board_usb_cable_connected()) {
		puts("\rUSB cable not detected.\n" \
		     "Command exit.\n");
		ret = CMD_RET_FAILURE;
		goto exit;
	}

	while (1) {
		if (g_dnl_detach())
			break;
		if (ctrlc())
			break;
		WATCHDOG_RESET();
		usb_gadget_handle_interrupts(controller_index);
	}

	ret = CMD_RET_SUCCESS;

exit:
	g_dnl_unregister();
	g_dnl_clear_detach();
	usb_gadget_release(controller_index);

	return ret;
#else
	pr_err("Fastboot USB not enabled\n");
	return CMD_RET_FAILURE;
#endif
}

static int do_fastboot(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	uintptr_t buf_addr = (uintptr_t)NULL;
	size_t buf_size = 0;

	if (argc < 2)
		return CMD_RET_USAGE;
	while (argc > 1 && **(argv + 1) == '-') {
		char *arg = *++argv;

		--argc;
		while (*++arg) {
			switch (*arg) {
			case 'l':
				if (--argc <= 0)
					return CMD_RET_USAGE;
				buf_addr = simple_strtoul(*++argv, NULL, 16);
				goto NXTARG;

			case 's':
				if (--argc <= 0)
					return CMD_RET_USAGE;
				buf_size = simple_strtoul(*++argv, NULL, 16);
				goto NXTARG;

			default:
				return CMD_RET_USAGE;
			}
		}
NXTARG:
		;
	}

	/* Handle case when USB controller param is just '-' */
	if (argc == 1) {
		pr_err("Error: Incorrect USB controller index\n");
		return CMD_RET_USAGE;
	}

	fastboot_init((void *)buf_addr, buf_size);

	if (!strcmp(argv[1], "udp"))
		return do_fastboot_udp(argc, argv, buf_addr, buf_size);

	if (!strcmp(argv[1], "usb")) {
		argv++;
		argc--;
	}

	return do_fastboot_usb(argc, argv, buf_addr, buf_size);
}

#ifdef CONFIG_SYS_LONGHELP
static char fastboot_help_text[] =
	"[-l addr] [-s size] usb <controller> | udp\n"
	"\taddr - address of buffer used during data transfers ("
	__stringify(CONFIG_FASTBOOT_BUF_ADDR) ")\n"
	"\tsize - size of buffer used during data transfers ("
	__stringify(CONFIG_FASTBOOT_BUF_SIZE) ")"
	;
#endif

U_BOOT_CMD(
	fastboot, CONFIG_SYS_MAXARGS, 1, do_fastboot,
	"run as a fastboot usb or udp device", fastboot_help_text
);

#define CFG_UPDATE_FILE_SRC_DEV		1 //MJ

/* SD Fusing : read images from FAT partition of SD Card, and write it to boot device.
 *
 * NOTE
 * - sdfuse is not a original code of fastboot
 * - Fusing image from SD Card is not a original part of Fastboot protocol.
 * - This command implemented at this file to re-use an existing code of fastboot */
int do_sdfuse (cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	int ret = 1;
	struct mmc *mmc = NULL;
	char run_cmd[60]={0};
	ulong FileSize=0;
	char response=0;
	mmc = find_mmc_device(CFG_UPDATE_FILE_SRC_DEV);

	if (mmc == NULL) //mj
	{
		printf("*****************************\n");
		printf("NO Updating SD Card!\n");
		printf("*****************************\n");
		return -1;

	}
	else
	{
		ret = mmc_init(mmc);
		if (ret) {
			printf("*****************************\n");
			printf("NO Updating SD Card!\n");
			printf("*****************************\n");
			return ret;
		}

	}
	if (argc < 2)
	{
		return -1;
	}

	if ((argc == 2) && !strcmp(argv[1], "flashall")) //mj
	{
		sprintf(run_cmd,"fatsize mmc 1 u-boot-iTOP-4412.bin");
		ret=run_command(run_cmd,0);
		FileSize=env_get_hex("filesize",0);
		sprintf(run_cmd,"fatload mmc 1 0x50000000 u-boot-iTOP-4412.bin");
		ret |=run_command(run_cmd,0);
		if(FileSize == 0 || ret)
		{
			printf("file:u-boot-iTOP-4412.bin not exist!\n");
			return -1;
		}
		fastboot_mmc_flash_write("bootloader",(void *)0x50000000,FileSize,&response);

		sprintf(run_cmd,"fatsize mmc 1 uImage");
		ret=run_command(run_cmd,0);
		FileSize=env_get_hex("filesize",0);
		sprintf(run_cmd,"fatload mmc 1 0x50000000 uImage");
		ret |=run_command(run_cmd,0);
		if(FileSize == 0 || ret)
		{
			printf("file:uImage not exist!\n");
			return -1;
		}
		fastboot_mmc_flash_write("kernel",(void *)0x50000000,FileSize,&response);

		sprintf(run_cmd,"fatsize mmc 1 exynos4412-itop-elite.dtb");
		ret=run_command(run_cmd,0);
		FileSize=env_get_hex("filesize",0);
		sprintf(run_cmd,"fatload mmc 1 0x50000000 exynos4412-itop-elite.dtb");
		ret |=run_command(run_cmd,0);
		if(FileSize == 0 || ret)
		{
			printf("file:exynos4412-itop-elite.dtb not exist!\n");
			return -1;
		}
		fastboot_mmc_flash_write("dtb",(void *)0x50000000,FileSize,&response);

		sprintf(run_cmd,"fatformat mmc 0:1");
		run_command(run_cmd,0);
		sprintf(run_cmd,"ext4format mmc 0:2");
		run_command(run_cmd,0);
		sprintf(run_cmd,"ext4format mmc 0:3");
		run_command(run_cmd,0);
		sprintf(run_cmd,"ext4format mmc 0:4");
		run_command(run_cmd,0);
		sprintf(run_cmd,"fatsize mmc 1 system.img");
		ret=run_command(run_cmd,0);
		FileSize=env_get_hex("filesize",0);
		sprintf(run_cmd,"fatload mmc 1 0x50000000 system.img");
		ret |=run_command(run_cmd,0);
		if(FileSize == 0 || ret)
		{
			printf("file:system.img not exist!\n");
			return -1;
		}
		fastboot_mmc_flash_write("system",(void *)0x50000000,FileSize,&response);
		return 0;
	}else if ((argc == 4) && !strcmp(argv[1], "flash"))
	{
		if(!strcmp(argv[2], "bootloader"))
		{
			sprintf(run_cmd,"fatsize mmc 1 %s",argv[3]);
			ret=run_command(run_cmd,0);
			FileSize=env_get_hex("filesize",0);
			sprintf(run_cmd,"fatload mmc 1 0x50000000 %s",argv[3]);
			ret |=run_command(run_cmd,0);
			if(FileSize == 0 || ret)
			{
				printf("file:%s not exist!\n",argv[3]);
				return -1;
			}
			fastboot_mmc_flash_write("bootloader",(void *)0x50000000,FileSize,&response);
			return 0;
		}else if(!strcmp(argv[2], "kernel"))
		{
			sprintf(run_cmd,"fatsize mmc 1 %s",argv[3]);
			ret=run_command(run_cmd,0);
			FileSize=env_get_hex("filesize",0);
			sprintf(run_cmd,"fatload mmc 1 0x50000000 %s",argv[3]);
			ret |=run_command(run_cmd,0);
			if(FileSize == 0 || ret)
			{
				printf("file:%s not exist!\n",argv[3]);
				return -1;
			}
			fastboot_mmc_flash_write("kernel",(void *)0x50000000,FileSize,&response);
			return 0;
		}else if(!strcmp(argv[2], "dtb"))
		{
			sprintf(run_cmd,"fatsize mmc 1 %s",argv[3]);
			ret=run_command(run_cmd,0);
			FileSize=env_get_hex("filesize",0);
			sprintf(run_cmd,"fatload mmc 1 0x50000000 %s",argv[3]);
			ret |=run_command(run_cmd,0);
			if(FileSize == 0 || ret)
			{
				printf("file:%s not exist!\n",argv[3]);
				return -1;
			}
			fastboot_mmc_flash_write("dtb",(void *)0x50000000,FileSize,&response);
			return 0;
		}else if(!strcmp(argv[2], "system"))
		{
			sprintf(run_cmd,"fatformat mmc 0:1");
			run_command(run_cmd,0);
			sprintf(run_cmd,"ext4format mmc 0:2");
			run_command(run_cmd,0);
			sprintf(run_cmd,"ext4format mmc 0:3");
			run_command(run_cmd,0);
			sprintf(run_cmd,"ext4format mmc 0:4");
			run_command(run_cmd,0);
			sprintf(run_cmd,"fatsize mmc 1 %s",argv[3]);
			ret=run_command(run_cmd,0);
			FileSize=env_get_hex("filesize",0);
			sprintf(run_cmd,"fatload mmc 1 0x50000000 %s",argv[3]);
			ret |=run_command(run_cmd,0);
			if(FileSize == 0 || ret)
			{
				printf("file:%s not exist!\n",argv[3]);
				return -1;
			}
			fastboot_mmc_flash_write("system",(void *)0x50000000,FileSize,&response);
			return 0;
		}
	}else if ((argc == 3) && !strcmp(argv[1], "erase"))
	{
		if(!strcmp(argv[2], "fat"))
		{
			sprintf(run_cmd,"ext4format mmc 0:1");
			run_command(run_cmd,0);
			return 0;
		}else if(!strcmp(argv[2], "system"))
		{
			sprintf(run_cmd,"ext4format mmc 0:2");
			run_command(run_cmd,0);
			return 0;
		}else if(!strcmp(argv[2], "userdata"))
		{
			sprintf(run_cmd,"ext4format mmc 0:3");
			run_command(run_cmd,0);
			return 0;
		}else if(!strcmp(argv[2], "cache"))
		{
			sprintf(run_cmd,"ext4format mmc 0:4");
			run_command(run_cmd,0);
			return 0;
		}else{
			printf("command error!\n");
			return -1;
		}
	}else{
		printf("command error!\n");
		return -1;
	}
	return 0;
}

U_BOOT_CMD(
	sdfuse,	4,	1,	do_sdfuse,
	"sdfuse  - read images from FAT partition of SD card and write them to booting device.",
	"sdfuse flashall                         - flash boot.img, system.img,\n"
	"                                          erase userdata, cache, and reboot.\n"
	"sdfuse flash <partition> [ <filename> ] - write a file to a partition.\n"
	"sdfuse erase <partition>                - erase (format) a partition."
);

