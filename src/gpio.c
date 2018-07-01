
#include "project.h"

void pin_init(void)
{
    unsigned int tempreg;

    /* set mode led ld3 */
    tempreg = read_reg(GPIOC_MODER, ~(0x03 << 18));
    tempreg |= (GPIO_MODER_OUTPUT << 18);
    write_reg(GPIOC_MODER, tempreg);


    /* set mode led ld4 */
    tempreg = read_reg(GPIOC_MODER, ~(0x03 << 16));
    tempreg |= (GPIO_MODER_OUTPUT << 16);
    write_reg(GPIOC_MODER, tempreg);


    /* set mode user button */
    tempreg = read_reg(GPIOA_MODER, ~(0x03 << 0));
    tempreg |= (GPIO_MODER_INPUT << 0);
    write_reg(GPIOA_MODER, tempreg);

}

void led_on(unsigned char pin_number)
{
    write_reg(GPIOC_BSRR, 1u << pin_number);
}

void led_off(unsigned char pin_number)
{
    write_reg(GPIOC_BSRR, 1u << (pin_number + 16u));
}

