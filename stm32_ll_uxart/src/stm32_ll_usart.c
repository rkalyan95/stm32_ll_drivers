#include "stm32_ll_usart.h"


  volatile  stm32_ll_usart_cr1_t *usart_cr1 =  ((volatile stm32_ll_usart_cr1_t *) (USART1_BASE + 0x00));
  volatile  stm32_ll_usart_cr2_t *usart_cr2 =  ((volatile stm32_ll_usart_cr2_t *) (USART1_BASE + 0x04));
  volatile  stm32_ll_usart_cr3_t *usart_cr3 =  ((volatile stm32_ll_usart_cr3_t *) (USART1_BASE + 0x08));

  volatile  stm32_ll_usart_brr_t *usart_brr =  ((volatile stm32_ll_usart_brr_t *) (USART1_BASE + 0x0C));
  volatile  stm32_ll_usart_gtpr_t *usart_gtpr =  ((volatile stm32_ll_usart_gtpr_t *) (USART1_BASE + 0x10));
  volatile  stm32_ll_usart_rtor_t *usart_rtor =  ((volatile stm32_ll_usart_rtor_t *) (USART1_BASE + 0x14));
  volatile  stm32_ll_usart_rqr_t *usart_rqr =  ((volatile stm32_ll_usart_rqr_t *) (USART1_BASE + 0x18));
  volatile  stm32_ll_usart_isr_t *usart_isr =  ((volatile stm32_ll_usart_isr_t *) (USART1_BASE + 0x1C));
  volatile  stm32_ll_usart_icr_t *usart_icr =  ((volatile stm32_ll_usart_icr_t *) (USART1_BASE + 0x20));
  volatile  stm32_ll_usart_rdr_t *usart_rdr =  ((volatile stm32_ll_usart_rdr_t *) (USART1_BASE + 0x24));
  volatile  stm32_ll_usart_tdr_t *usart_tdr =  ((volatile stm32_ll_usart_tdr_t *) (USART1_BASE + 0x28));

const uint8_t bootMsg[] = "Starting up.....Welcome to Bitwise\r\n";

typedef struct
{
  uint8_t *txbuffer;
  uint8_t *rxbuffer;
  uint32_t txlen;
  uint32_t rxlen;
}stm32_ll_usart_buffer_t;

void init_usart(void)
{

  usart_cr1->B.TE = 1;
  usart_cr1->B.RE = 1;
  usart_cr1->B.UE = 0;
  usart_cr3->B.WUS1 = 1;
  usart_brr->B.BRR = 0x09C4;  //9600baud
  usart_cr1->B.UE = 1;

}

void printWelcomeMessage(void)
{
  
  int i =0;
  while(bootMsg[i]!=0)
  {
    usart_tdr->B.TDR = bootMsg[i];
    while(usart_isr->B.TC != 1);
    usart_isr->U = 0;
    i++;
  }

}




void deinit_usart(void)
{

}
