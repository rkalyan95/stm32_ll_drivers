

#define VECTOR_ISR_SIZE_IN_WORDS  (101)
#include <stdint.h>
#include <stm32l433xx.h>
extern uint32_t _estack;
extern uint32_t _etext; 
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void main(void);
void reset_handler(void);
void default_handler(void);
void nmi_handler(void);
void mem_manage_handler(void);
void hardfault_handler(void);
void bus_fault_handler(void);
void usage_fault_handler(void);
void svcall_handler(void);
void debug_monitor_handler(void);
void pendSv_handler(void) ;
void systick_handler(void);
void __isr_wwdg(void)__attribute__((weak, alias("default_handler")));
void __isr_pvdpvm(void)__attribute__((weak, alias("default_handler")));
void __isr_rtctamper_tstamp_csslse(void)__attribute__((weak, alias("default_handler")));
void __isr_rtcwkup(void)__attribute__((weak, alias("default_handler")));
void __isr_flash(void)__attribute__((weak, alias("default_handler")));
void __isr_rcc(void)__attribute__((weak, alias("default_handler")));
void __isr_exti0(void)__attribute__((weak, alias("default_handler")));
void __isr_exti1(void)__attribute__((weak, alias("default_handler")));
void __isr_exti2(void)__attribute__((weak, alias("default_handler")));
void __isr_exti3(void)__attribute__((weak, alias("default_handler")));
void __isr_exti4(void)__attribute__((weak, alias("default_handler")));
void __isr_dma1ch1(void)__attribute__((weak, alias("default_handler")));
void __isr_dma1ch2(void)__attribute__((weak, alias("default_handler")));
void __isr_dma1ch3(void)__attribute__((weak, alias("default_handler")));
void __isr_dma1ch4(void)__attribute__((weak, alias("default_handler")));
void __isr_dma1ch5(void)__attribute__((weak, alias("default_handler")));
void __isr_dma1ch6(void)__attribute__((weak, alias("default_handler")));
void __isr_dma1ch7(void)__attribute__((weak, alias("default_handler")));
void __isr_adc1_2(void)__attribute__((weak, alias("default_handler")));
void __isr_can1tx(void)__attribute__((weak, alias("default_handler")));
void __isr_can1rx0(void)__attribute__((weak, alias("default_handler")));
void __isr_can1rx1(void)__attribute__((weak, alias("default_handler")));
void __isr_sce(void)__attribute__((weak, alias("default_handler")));
void __isr_exti9_5(void)__attribute__((weak, alias("default_handler")));
void __isr_tim1brk_tim15(void)__attribute__((weak, alias("default_handler")));
void __isr_tim1up_tim16(void)__attribute__((weak, alias("default_handler")));
void __isr_tim1trg_commu(void)__attribute__((weak, alias("default_handler")));
void __isr_tim1_cc(void)__attribute__((weak, alias("default_handler")));
void __isr_tim2(void)__attribute__((weak, alias("default_handler")));
void __isr_tim3(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved30(void)__attribute__((weak, alias("default_handler")));
void __isr_i2c1_evt(void)__attribute__((weak, alias("default_handler")));
void __isr_i2c1_err(void)__attribute__((weak, alias("default_handler")));
void __isr_i2c2_evt(void)__attribute__((weak, alias("default_handler")));
void __isr_i2c2_err(void)__attribute__((weak, alias("default_handler")));
void __isr_spi1(void)__attribute__((weak, alias("default_handler")));
void __isr_spi2(void)__attribute__((weak, alias("default_handler")));
void __isr_usart1(void)__attribute__((weak, alias("default_handler")));
void __isr_usart2(void)__attribute__((weak, alias("default_handler")));
void __isr_usart3(void)__attribute__((weak, alias("default_handler")));
void __isr_exti15_10(void)__attribute__((weak, alias("default_handler")));
void __isr_rtc_alarm(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved42(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved43(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved44(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved45(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved46(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved47(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved48(void)__attribute__((weak, alias("default_handler")));
void __isr_sdmmc(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved50(void)__attribute__((weak, alias("default_handler")));
void __isr_spi3(void)__attribute__((weak, alias("default_handler")));
void __isr_uart4(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved53(void)__attribute__((weak, alias("default_handler")));
void __isr_tim6_dacunderrun(void)__attribute__((weak, alias("default_handler")));
void __isr_tim7(void)__attribute__((weak, alias("default_handler")));
void __isr_dma2ch1(void)__attribute__((weak, alias("default_handler")));
void __isr_dma2ch2(void)__attribute__((weak, alias("default_handler")));
void __isr_dma2ch3(void)__attribute__((weak, alias("default_handler")));
void __isr_dma2ch4(void)__attribute__((weak, alias("default_handler")));
void __isr_dma2ch5(void)__attribute__((weak, alias("default_handler")));
void __isr_dfsdm_flt0(void)__attribute__((weak, alias("default_handler")));
void __isr_dfsdm_flt1(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved63(void)__attribute__((weak, alias("default_handler")));
void __isr_comp1_2(void)__attribute__((weak, alias("default_handler")));
void __isr_lptim1(void)__attribute__((weak, alias("default_handler")));
void __isr_lptim2(void)__attribute__((weak, alias("default_handler")));
void __isr_usbfs(void)__attribute__((weak, alias("default_handler")));
void __isr_dma2_ch6(void)__attribute__((weak, alias("default_handler")));
void __isr_dma2_ch7(void)__attribute__((weak, alias("default_handler")));
void __isr_lpuar1(void)__attribute__((weak, alias("default_handler")));
void __isr_qspi(void)__attribute__((weak, alias("default_handler")));
void __isr_i2c3_evt(void)__attribute__((weak, alias("default_handler")));
void __isr_sai1(void)__attribute__((weak, alias("default_handler")));
void __isr_reserved75(void)__attribute__((weak, alias("default_handler")));
void __isr_swpmi(void)__attribute__((weak, alias("default_handler")));
void __isr_tsc(void)__attribute__((weak, alias("default_handler")));
void __isr_lcd(void)__attribute__((weak, alias("default_handler")));
void __isr_aes(void)__attribute__((weak, alias("default_handler")));
void __isr_rng(void)__attribute__((weak, alias("default_handler")));
void __isr_fpu(void)__attribute__((weak, alias("default_handler")));
void __isr_crs(void)__attribute__((weak, alias("default_handler")));
void __isr_i2c4_evt(void)__attribute__((weak, alias("default_handler")));
void __isr_i2c4_err(void)__attribute__((weak, alias("default_handler")));


uint32_t isr_vector[VECTOR_ISR_SIZE_IN_WORDS] __attribute__((section(".isr_vector"))) = {
    (uint32_t)&_estack,
    (uint32_t)&reset_handler,
    (uint32_t)&nmi_handler,
    (uint32_t)&hardfault_handler,
    (uint32_t)&mem_manage_handler,
    (uint32_t)&bus_fault_handler,
    (uint32_t)&usage_fault_handler,
    0,
    0,
    0,
    0,
    (uint32_t)&svcall_handler,
    (uint32_t)&debug_monitor_handler,
    0,
    (uint32_t)&pendSv_handler,
    (uint32_t)&systick_handler,
//Add more below if wish to
    (uint32_t)&__isr_wwdg,
    (uint32_t)&__isr_pvdpvm,
    (uint32_t)&__isr_rtctamper_tstamp_csslse,
    (uint32_t)&__isr_rtcwkup,
    (uint32_t)&__isr_flash,
    (uint32_t)&__isr_rcc,
    (uint32_t)&__isr_exti0,
    (uint32_t)&__isr_exti1,
    (uint32_t)&__isr_exti2,
    (uint32_t)&__isr_exti3,
    (uint32_t)&__isr_exti4,
    (uint32_t)&__isr_dma1ch1,
    (uint32_t)&__isr_dma1ch2,
    (uint32_t)&__isr_dma1ch3,
    (uint32_t)&__isr_dma1ch4,
    (uint32_t)&__isr_dma1ch5,
    (uint32_t)&__isr_dma1ch6,
    (uint32_t)&__isr_dma1ch7,
    (uint32_t)&__isr_adc1_2,
    (uint32_t)&__isr_can1tx,
    (uint32_t)&__isr_can1rx0,
    (uint32_t)&__isr_can1rx1,
    (uint32_t)&__isr_sce,
    (uint32_t)&__isr_exti9_5,
    (uint32_t)&__isr_tim1brk_tim15,
    (uint32_t)&__isr_tim1up_tim16,
    (uint32_t)&__isr_tim1trg_commu,
    (uint32_t)&__isr_tim1_cc,
    (uint32_t)&__isr_tim2,
    (uint32_t)&__isr_tim3,
    0,
    (uint32_t)&__isr_i2c1_evt,
    (uint32_t)&__isr_i2c1_err,
    (uint32_t)&__isr_i2c2_evt,
    (uint32_t)&__isr_i2c2_err,
    (uint32_t)&__isr_spi1,
    (uint32_t)&__isr_spi2,
    (uint32_t)&__isr_usart1,
    (uint32_t)&__isr_usart2,
    (uint32_t)&__isr_usart3,
    (uint32_t)&__isr_exti15_10,
    (uint32_t)&__isr_rtc_alarm,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t)&__isr_sdmmc,
    0,
    (uint32_t)&__isr_spi3,
    (uint32_t)&__isr_uart4,
    0,
    (uint32_t)&__isr_tim6_dacunderrun,
    (uint32_t)&__isr_tim7,
    (uint32_t)&__isr_dma2ch1,
    (uint32_t)&__isr_dma2ch2,
    (uint32_t)&__isr_dma2ch3,
    (uint32_t)&__isr_dma2ch4,
    (uint32_t)&__isr_dma2ch5,
    (uint32_t)&__isr_dfsdm_flt0,
    (uint32_t)&__isr_dfsdm_flt1,
    0,
    (uint32_t)&__isr_comp1_2,
    (uint32_t)&__isr_lptim1,
    (uint32_t)&__isr_lptim2,
    (uint32_t)&__isr_usbfs,
    (uint32_t)&__isr_dma2_ch6,
    (uint32_t)&__isr_dma2_ch7,
    (uint32_t)&__isr_lpuar1,
    (uint32_t)&__isr_qspi,
    (uint32_t)&__isr_i2c3_evt,
    (uint32_t)&__isr_sai1,
    0,
    (uint32_t)&__isr_swpmi,
    (uint32_t)&__isr_tsc,
    (uint32_t)&__isr_lcd,
    (uint32_t)&__isr_aes,
    (uint32_t)&__isr_rng,
    (uint32_t)&__isr_fpu,
    (uint32_t)&__isr_crs,
    (uint32_t)&__isr_i2c4_evt,
    (uint32_t)&__isr_i2c4_err,

};

void default_handler(void)
{
    while(1);
}

void nmi_handler(void)
{
  while(1);
}
void mem_manage_handler(void)
{
  while(1);
}
void hardfault_handler(void)
{
  while(1);
}
void bus_fault_handler(void)
{
  while(1);
}
void usage_fault_handler(void)
{
  while(1);
}
void svcall_handler(void)
{
  while(1);
}
void debug_monitor_handler(void)
{
  while(1);
}
void pendSv_handler(void) 
{
  while(1);
}
void systick_handler(void)
{
  while(1);
}


void FPU_Enable(void) {
    // CPACR register: enable CP10 and CP11 full access
    SCB->CPACR |= (0xF << 20);
    __DSB();
    __ISB();
}


void reset_handler(void)
{
    uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint8_t *flash_data = (uint8_t*)&_etext;
    uint8_t *sram_data = (uint8_t *)&_sdata;
    SCB->VTOR = (uint32_t)0x08000000U; // Point VTOR to the start of Flash
for (uint32_t i = 0; i < data_size; i++)
  {
    sram_data[i] = flash_data[i];
  }

  // Zero-fill .bss section in SRAM
  uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  uint32_t *bss = (uint32_t*) &_sbss;

  for (uint32_t i = 0; i < bss_size; i++)
  {
    bss[i] = 0;
  }
  FPU_Enable();
  main();
}