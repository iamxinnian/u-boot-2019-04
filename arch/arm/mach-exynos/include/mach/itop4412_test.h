#ifndef _ITOP4412_TEST_H_
#define _ITOP4412_TEST_H_

/************代码优化定义******************/
#define optimize(grade)	__attribute__((__optimize__("O"#grade)))
#define optimize0	optimize(0)
#define optimize1	optimize(1)
#define optimize2	optimize(2)
#define optimize3	optimize(3)

/***********点灯测试********************/
void led2on(void);
void led2off(void);
optimize0 void blink_led2(unsigned int Times,unsigned int DelayTime);
optimize0 char mem_write(unsigned int *addr,unsigned int data);
optimize0 char mem_read(unsigned int *addr,unsigned int *data);
optimize0 char mem_test(unsigned int *start_addr1,unsigned int *start_addr2,unsigned size1,unsigned size2);
#endif

