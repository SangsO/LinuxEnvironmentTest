#include <common.h>
#include <command.h>
#include <asm/io.h>

#define IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0 0x020E0340	// GPIO1_IO16
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DATA1 0x020E033C 	// GPIO1_IO17
#define IOMUXC_SW_MUX_CTL_PAD_SD1_CMD	0x020E0348	// GPIO1_IO18
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DATA2 0x020E034C	// GPIO1_IO19
#define GPIO1_DR						0x0209C000
#define GPIO1_GDIR						0x0209C004
#define GPIO1_PSR						0x0209C008

void led_init(void)
{
	unsigned long temp;
	temp = 0x05;									// Select signal GPIO
	writel(temp, IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0);	// GPIO1_16
	writel(temp, IOMUXC_SW_MUX_CTL_PAD_SD1_DATA1);	// GPIO1_17
	writel(temp, IOMUXC_SW_MUX_CTL_PAD_SD1_CMD);	// GPIO1_18
	writel(temp, IOMUXC_SW_MUX_CTL_PAD_SD1_DATA2);	// GPIO1_19

	temp = 0x0f << 16;								// GPIO1_IO16 ~ IO19 Direction : Output
	temp = readl(GPIO1_GDIR) | temp;
	writel(temp, GPIO1_GDIR);

	temp = ~(0x0f << 16);							// LED1~4 : off
	temp = readl(GPIO1_DR) & temp;
	writel(temp, GPIO1_DR);
}

void led_write(unsigned long led_data)
{
	led_data = led_data << 16;
	writel(led_data, GPIO1_DR);
}
// ===================================================
//					read function
// ===================================================
void led_read(unsigned long* led_data)
{
	char print_ox[10] = "";
	int idx;

	puts("1:2:3:4\n");
	/**led_data = 0x0f << 16;
	*led_data = readl(GPIO1_DR) & *led_data;
	*led_data = *led_data >> 16;*/
	*led_data = (readl(GPIO1_DR) >> 16) & 0x0f;
	
	for(idx = 0; idx < 4; idx++) {
		if(*led_data & (0x01 << idx)) {
			if(idx == 3)
				strcat(print_ox, "O\n");
			else
				strcat(print_ox, "O:");
		}
		else {
			if(idx == 3)
				strcat(print_ox, "X\n");
			else
				strcat(print_ox, "X:");
		}
	}
	
	puts(print_ox);
}
// ===================================================
//					read function end
// ===================================================
static int do_KCCI_LED(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	unsigned long led_data;
	if(argc != 2)
	{
		cmd_usage(cmdtp);
		return 1;
	}
	printf("*LED TEST START\n");
	led_init();
	led_data = simple_strtoul(argv[1], NULL, 16);
	led_write(led_data);
	led_read(&led_data);
	printf("*LED TEST END(%s : %#04x)\n\n", argv[0], (unsigned int)led_data);
	return 0;
}

U_BOOT_CMD(
		led,2,0,do_KCCI_LED,
		"led - kcci LED Test.",
		"number - Input argument is only one.led [0x00~0x0f])\n");
