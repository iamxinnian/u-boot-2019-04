#include <asm/arch/itop4412_test.h>
#include <asm/io.h>
/*
	__asm__ ( \
		"ldr r0, =0x11000100\n" \
		"ldr r1, =0x1\n" \
		"str r1, [r0]\n" \
		"ldr r0, =0x11000104\n" \
		"str r1, [r0]\n" \
		"b	.\n" \
		);
	*/
void led2on(void)
{
	unsigned int *led2_con_addr=(unsigned int *)0x11000100;
	unsigned int *led2_data_addr=(unsigned int *)0x11000104;
	unsigned int value=readl(led2_con_addr);
	value |=0x1;
	writel(value,led2_con_addr);

	value=readl(led2_data_addr);
	value |=0x1;
	writel(value,led2_data_addr);

	return;
}

void led2off(void)
{
	unsigned int *led2_con_addr=(unsigned int *)0x11000100;
	unsigned int *led2_data_addr=(unsigned int *)0x11000104;
	unsigned int value=readl(led2_con_addr);
	value |=0x1;
	writel(value,led2_con_addr);

	value=readl(led2_data_addr);
	value &=0xfffffffe;
	writel(value,led2_data_addr);

	return;
}

optimize0 void delay(unsigned int n)
{
	unsigned int i=0;
	while(n--)
	{
		for(i=0;i<0xfff;i++);
	}
}

optimize0 void blink_led2(unsigned int Times,unsigned int DelayTime)
{
	unsigned int t=0;
	for(t=0;t<Times;t++)
	{
		led2on();
		delay(DelayTime);
		led2off();
		delay(DelayTime);
	}
	return;
}
