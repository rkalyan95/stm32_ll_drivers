#include "stm32_ll_usart.h"
#include "stm32l433_ll_gpio.h"
#include "stm32l433_ll_gpio_cfg.h"
#include <stddef.h>

#define MAX_RETRY   3U

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


uart_ll_config_t uart_ll_config = {
    .baudrate = 9600,
    .datalen = datalen_8, //8 bits data 1 bit parity as per datasheet
    .datadirection = lsb_first,
    .duplexity = full_duplex,
    .stopbits = one_stop_bit,
    .parity = none_parity,
    .dmatxenable = dma_txdisable,
    .dmarxenable = dma_rxdisable
};



static err_t Uart_ll_SetBaudRate(baudrate_t baudrate)
{
  err_t err_st=error_ok;
  usart_brr->B.BRR = 0x09C4;  //9600baud
  while(usart_brr->B.BRR != 0x09C4);
  return err_st;
}

static err_t Uart_ll_SetDataLen(datalen_t datalen)
{
  err_t err_st=error_ok;
  switch(datalen)
  {
    case datalen_7:
      usart_cr1->B.M1 = 1;
      usart_cr1->B.M0 = 0;
      break;
    case datalen_8:
      usart_cr1->B.M1 = 0;
      usart_cr1->B.M0 = 0;
      break;
    case datalen_9:
      usart_cr1->B.M1 = 0;
      usart_cr1->B.M0 = 1;
      break;
    default:
      err_st = error_invalid_parameter;
      break;
  }
  return err_st;
}

static err_t Uart_ll_SetParity(parity_t parity)
{
  err_t err_st=error_ok;
  uint8_t retry_count = 0;
  if(parity != none_parity)
  {
    usart_cr1->B.PCE = 1;
    usart_cr1->B.PS = parity;
    while(usart_cr1->B.PCE != 1 && usart_cr1->B.PS != parity && retry_count < MAX_RETRY);
    {
      retry_count++;
    }
  }
  else
  {
    usart_cr1->B.PCE = 0;
  }

  if(retry_count == MAX_RETRY)
  {
    err_st = error_timeout;
  }
  return err_st;
}

static err_t Uart_ll_SetStopbits(stopbits_t stopbits)
{
  uint8_t retry_count = 0;
  err_t err_st=error_ok;
  if(stopbits!=invalid_stopbit)
  {
    usart_cr2->B.STOP = stopbits;
    while(usart_cr2->B.STOP != stopbits && retry_count < MAX_RETRY);
    {
      retry_count++;
    }
  }
  else
  {
    err_st = error_invalid_parameter;
  }

  if(retry_count == MAX_RETRY)
  {
    err_st = error_timeout;
  }
  return err_st;
}

static err_t Uart_ll_EnableDma(dmarxenable_t dmarxen,dmatxenable_t dmatxen)
{
  err_t err_st=error_ok;
  return err_st;
}

static err_t Uart_ll_SetDataDir(datadirection_t datadir)
{
  uint8_t retry_count = 0;
  err_t err_st=error_ok;
  if(datadir!=dir_invalid)
  {
    usart_cr2->B.MSBFIRST = datadir;
    while(usart_cr2->B.MSBFIRST != datadir && retry_count < MAX_RETRY);
    {
      retry_count++;
    }
  }
  else
  {
    err_st = error_invalid_parameter;
  }

  if(retry_count == MAX_RETRY)
  {
    err_st = error_timeout;
  }
 return err_st;
}
 
static err_t Uart_ll_SetDuplex(duplexity_t duplex)
{
  err_t err_st=error_ok;
  uint8_t retry_count = 0;
  if(duplex!=duplex_invalid)
  {
    usart_cr3->B.HDSEL = duplex;
    while(usart_cr3->B.HDSEL != duplex && retry_count < MAX_RETRY);
    {
      retry_count++;
    }

  }
  else
  {
    err_st = error_invalid_parameter;
  }

  if(retry_count == MAX_RETRY)
  {
    err_st = error_timeout;
  }
 return err_st;
}

static err_t Uart_ll_Enable(Uartenable_t enable)
{
  uint8_t retry_count = 0;
 err_t err_st=error_ok;
  usart_cr1->B.TE = enable;
  usart_cr1->B.RE = enable;
  while(usart_cr1->B.TE!=1 && usart_cr1->B.RE!=1 && retry_count < MAX_RETRY);
  {
    retry_count++;
  }

 if(retry_count == MAX_RETRY)
 {
   err_st = error_timeout;
 }

 usart_cr1->B.UE = enable;
 retry_count = 0;
 while(usart_cr1->B.UE != enable && retry_count < MAX_RETRY);
 {
   retry_count++;
 }

 if(retry_count == MAX_RETRY)
 {
   err_st = error_timeout;
 }
 return err_st;
}


static err_t Uart_ll_WakeupSource(wakeupsource_t wakeup)
{
  uint8_t retry_count = 0;
 err_t err_st=error_ok;
 usart_cr3->B.WUS = wakeup;
 while(usart_cr3->B.WUS != wakeup && retry_count < MAX_RETRY);
 {
   retry_count++;
 }

 if(retry_count == MAX_RETRY)
 {
   err_st = error_timeout;
 }
 return err_st;
}

static err_t Uart_ll_ClearStatus(uarterror_t uarterr)
{
  err_t err_st = error_ok;
 switch(uarterr)
 {
  case uart_parityerror:
    usart_icr->B.PECF = 1;
    break;
  case uart_framingerror:
    usart_icr->B.FECF = 1;
    break;
  case uart_startbitnoise:
    usart_icr->B.NCF = 1;
    break;
  case uart_overrunerror:
    usart_icr->B.ORECF = 1;
    break;
  case uart_rxnotempty:
    usart_rqr->B.RXFRQ = 1;
    break;
  case uart_txempty:
    usart_rqr->B.TXFRQ = 1;
    break;
  default:
    err_st = error_invalid_parameter;
    break;
 }
  return err_st;
}
static err_t Uart_ll_GetUartStatus(uarterror_t uarterr)
{
 err_t err_st = error_ok;
 
 switch(uarterr)
 {
  case uart_parityerror:
    err_st = (usart_isr->B.PE==1)?(error_nok):(error_ok);
    break;
  case uart_framingerror:
    err_st = (usart_isr->B.FE==1)?(error_nok):(error_ok);
    break;
  case uart_startbitnoise:
    err_st = (usart_isr->B.NF==1)?(error_nok):(error_ok);
    break;
  case uart_overrunerror:
    err_st = (usart_isr->B.ORE==1)?(error_nok):(error_ok);
    break;
  case uart_rxnotempty:
    err_st = (usart_isr->B.RXNE==1)?(error_ok):(error_nok);
    break;
  case uart_txempty:
    err_st = (usart_isr->B.TXE==1)?(error_ok):(error_nok);
    break;
  case uart_busy:
    err_st = (usart_isr->B.BUSY==1)?(error_nok):(error_ok);
    break;
  default:
    err_st = error_invalid_parameter;
    break;
 }
 return err_st;
}


err_t Uart_ll_FlushTx(void)
{
  err_t err_st=error_ok;
  return err_st;
}

err_t Uart_ll_FlushRx(void)
{
  err_t err_st=error_ok;
  usart_rqr->B.RXFRQ = 1;
  return err_st;
}

err_t Uart_ll_SendByte(uint8_t byte)
{
  uint8_t retry_count = 0;
  err_t err_st=error_ok;

 if(Uart_ll_GetUartStatus(uart_txempty)==error_ok)
    {
      Uart_ll_ClearStatus(uart_txempty);
    }
  else
  {
    return error_txfailed;
  }

 usart_tdr->B.TDR = byte;
 while(usart_isr->B.TC != 1 && retry_count < MAX_RETRY);
 {
   retry_count++;
 }

 if(retry_count == MAX_RETRY)
 {
   return error_timeout;
 }
 usart_isr->B.TC = 0;

 return err_st;
}

err_t Uart_ll_ReceiveByte(uint8_t *byte)
{
 err_t err_st=error_nok;
 if(usart_isr->B.BUSY!=1)
  {
    if(usart_isr->B.RXNE==1)
    {
      *byte = usart_rdr->B.RDR;
      usart_rqr->B.RXFRQ = 1;
       return error_ok;
    }
    else
    {
      return error_nok;
    }
  }
 else
 {
  return error_rxfailed;
 }
 
}




err_t Uart_ll_Init(uart_ll_config_t *uart_ll_config)
{
  err_t err_st=error_ok;
  if(uart_ll_config==NULL)
  {
    return error_nullptr;
  }
  err_st = Uart_ll_SetBaudRate(uart_ll_config->baudrate);
  if(err_st!=error_ok)
  {
    return err_st;
  }
  err_st = Uart_ll_SetDataLen(uart_ll_config->datalen);
    if(err_st!=error_ok)
  {
    return err_st;
  }
  err_st = Uart_ll_SetDataDir(uart_ll_config->datadirection);
  if(err_st!=error_ok)
  {
    return err_st;
  }
  err_st = Uart_ll_SetDuplex(uart_ll_config->duplexity);
  if(err_st!=error_ok)
  {
    return err_st;
  }
  err_st = Uart_ll_SetStopbits(uart_ll_config->stopbits);
  if(err_st!=error_ok)
  {
    return err_st;
  }
  err_st = Uart_ll_SetParity(uart_ll_config->parity);
  if(err_st!=error_ok)
  {
    return err_st;
  }
  err_st = Uart_ll_WakeupSource(wakeup_on_start);
  if(err_st!=error_ok)
  {
    return err_st;
  }
  err_st = Uart_ll_Enable(uart_enable);
  if(err_st!=error_ok)
  {
    return err_st;
  }
  err_st =  Uart_ll_FlushRx();
  return err_st;
}

void init_usart(void)
{
  Uart_ll_Init(&uart_ll_config);
}


void printdebugstring(const uint8_t *debugmessage)
{
  uint32_t bytes = 0;
  uint8_t retrycount=0;
  err_t err_st;
  while(debugmessage[bytes]!=0 && retrycount<MAX_RETRY)
  {
      err_st = Uart_ll_SendByte(debugmessage[bytes]);
      if(err_st==error_ok)
      {
        bytes++;
      }
      else
    {
      retrycount++;
    }
  }

}

err_t readuntillnewline(uint8_t *buffer)
{
  static uint32_t bytes = 0;
  uint8_t  data  = 0;
  err_t err_st=error_nok;

  err_st = Uart_ll_ReceiveByte(&data);
  
  if(err_st==error_ok)
  {
    Uart_ll_SendByte(data);
    if(data == '\r')
    {
      buffer[bytes++] = data;
      buffer[bytes] = 0;
      bytes = 0;
      return error_ok;
    }
    else
    {
      buffer[bytes] = data;
      bytes++;
    }

  }

}
