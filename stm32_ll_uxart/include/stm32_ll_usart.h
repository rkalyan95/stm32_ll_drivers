#ifndef STM32_LL_USART_H
#define STM32_LL_USART_H

/* Prevent double inclusion */

/*lint -save -e40 -e41 */
#include <stm32l433xx.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct 
{
    volatile uint32_t UE      : 1;
    volatile uint32_t UESM    : 1;
    volatile uint32_t RE      : 1;
    volatile uint32_t TE      : 1;
    volatile uint32_t IDLEIE  : 1;
    volatile uint32_t RXNEIE  : 1;
    volatile uint32_t TCIE    : 1;
    volatile uint32_t TXEIE   : 1;
    volatile uint32_t PEIE    : 1;
    volatile uint32_t PS      : 1;
    volatile uint32_t PCE     : 1;
    volatile uint32_t WAKE    : 1;
    volatile uint32_t M0      : 1;
    volatile uint32_t MME     : 1;
    volatile uint32_t CMIE    : 1;
    volatile uint32_t OVR8    : 1;
    volatile uint32_t DEDT    : 5;
    volatile uint32_t DEAT    : 5;
    volatile uint32_t RTOIE   : 1;
    volatile uint32_t EOBIE   : 1;
    volatile uint32_t M1      : 1;
    volatile uint32_t Reserved: 3;

}stm32_ll_usart_cr1_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_cr1_b B;
}stm32_ll_usart_cr1_t;


typedef struct 
{
    volatile uint32_t Res0      : 4;
    volatile uint32_t ADDM7      : 1;
    volatile uint32_t LBDL    : 1;
    volatile uint32_t LBDIE      : 1;
    volatile uint32_t Res1      : 1;
    volatile uint32_t LBCL  : 1;
    volatile uint32_t CPHA  : 1;
    volatile uint32_t CPOL    : 1;
    volatile uint32_t CLKEN   : 1;
    volatile uint32_t STOP    : 2;
    volatile uint32_t LINEN      : 1;
    volatile uint32_t SWAP     : 1;
    volatile uint32_t RXINV    : 1;
    volatile uint32_t TXINV      : 1;
    volatile uint32_t DATAINV     : 1;
    volatile uint32_t MSBFIRST    : 1;
    volatile uint32_t ABREN    : 1;
    volatile uint32_t ABRMOD    : 2;
    volatile uint32_t RTOEN    : 5;
    volatile uint32_t ADD_L   : 4;
    volatile uint32_t ADD_H   : 4;

}stm32_ll_usart_cr2_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_cr2_b B;
}stm32_ll_usart_cr2_t;


typedef struct 
{
    volatile uint32_t EIE      : 1;
    volatile uint32_t IREN      : 1;
    volatile uint32_t IRLP    : 1;
    volatile uint32_t HDSEL      : 1;
    volatile uint32_t NACK      : 1;
    volatile uint32_t SCEN  : 1;
    volatile uint32_t DMAR  : 1;
    volatile uint32_t DMAT    : 1;
    volatile uint32_t RTSE   : 1;
    volatile uint32_t CTSE    : 1;
    volatile uint32_t CTSIE      : 1;
    volatile uint32_t ONEBIT     : 1;
    volatile uint32_t OVRDIS    : 1;
    volatile uint32_t DDRE      : 1;
    volatile uint32_t DEM     : 1;
    volatile uint32_t DEP    : 1;
    volatile uint32_t RES0    : 1;
    volatile uint32_t SCARCNT0    : 1;
    volatile uint32_t SCARCNT1    : 1;
    volatile uint32_t SCARCNT2    : 1;
    volatile uint32_t WUS   : 2;
    volatile uint32_t WUFIE   : 1;
    volatile uint32_t UCESM   : 1;
    volatile uint32_t TCBGTIE   : 1;
    volatile uint32_t  RES1 : 7;
}stm32_ll_usart_cr3_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_cr3_b B;
}stm32_ll_usart_cr3_t;


typedef struct 
{
    volatile uint32_t BRR      : 16;
    volatile uint32_t RES      : 16;

}stm32_ll_usart_brr_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_brr_b B;
}stm32_ll_usart_brr_t;


typedef struct 
{
    volatile uint32_t PSC      : 8;
    volatile uint32_t GT      : 8;
    volatile uint32_t RES      : 16;

}stm32_ll_usart_gtpr_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_gtpr_b B;
}stm32_ll_usart_gtpr_t;


typedef struct 
{
    volatile uint32_t RTO_L      : 16;
    volatile uint32_t RTO_M      : 8;
    volatile uint32_t BLEN      : 8;

}stm32_ll_usart_rtor_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_rtor_b B;
}stm32_ll_usart_rtor_t;


typedef struct 
{
    volatile uint32_t ABRRQ      : 1;
    volatile uint32_t SBKRQ      : 1;
    volatile uint32_t MMRQ      : 1;
    volatile uint32_t RXFRQ      : 1;
    volatile uint32_t TXFRQ      : 1;
    volatile uint32_t RES : 27;

}stm32_ll_usart_rqr_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_rqr_b B;
}stm32_ll_usart_rqr_t;


typedef struct 
{
    volatile uint32_t PE      : 1;
    volatile uint32_t FE      : 1;
    volatile uint32_t NF      : 1;
    volatile uint32_t ORE      : 1;
    volatile uint32_t IDLE      : 1;
    volatile uint32_t RXNE : 1;
    volatile uint32_t TC      : 1;
    volatile uint32_t TXE      : 1;
    volatile uint32_t LBDF      : 1;
    volatile uint32_t CTSIF      : 1;
    volatile uint32_t CTS      : 1;
    volatile uint32_t RTOF : 1;
    volatile uint32_t EOBF      : 1;
    volatile uint32_t RES0      : 1;
    volatile uint32_t ABRE      : 1;
    volatile uint32_t ABRF      : 1;
    volatile uint32_t BUSY      : 1;
    volatile uint32_t CMF : 1;

    volatile uint32_t SBKF : 1;
    volatile uint32_t RWU      : 1;
    volatile uint32_t WUF      : 1;
    volatile uint32_t TEACK      : 1;
    volatile uint32_t REACK      : 1;
    volatile uint32_t RES1      : 2;
    volatile uint32_t TCBGT : 1;
    volatile uint32_t RES2      : 6;
}stm32_ll_usart_isr_b;


typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_isr_b B;
}stm32_ll_usart_isr_t;


typedef struct 
{
    volatile uint32_t PECF      : 1;
    volatile uint32_t FECF      : 1;
    volatile uint32_t NCF      : 1;
    volatile uint32_t ORECF      : 1;
    volatile uint32_t IDLECF      : 1;
    volatile uint32_t RES0 : 1;
    volatile uint32_t TCBGTCF      : 1;
    volatile uint32_t LBDCF      : 1;
    volatile uint32_t CTSCF      : 1;
    volatile uint32_t RES1      : 1;
    volatile uint32_t RTOCF      : 1;
    volatile uint32_t EOBCF : 1;
    volatile uint32_t RES2      : 4;
    volatile uint32_t CMCF      : 1;
    volatile uint32_t RES3      : 2;
    volatile uint32_t WUCF      : 1;
    volatile uint32_t RES4      : 11;
}stm32_ll_usart_icr_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_icr_b B;
}stm32_ll_usart_icr_t;


typedef struct 
{
    volatile uint32_t RDR      : 9;
    volatile uint32_t RES      : 23;

}stm32_ll_usart_rdr_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_rdr_b B;
}stm32_ll_usart_rdr_t;


typedef struct 
{
    volatile uint32_t TDR      : 9;
    volatile uint32_t RES      : 23;

}stm32_ll_usart_tdr_b;

typedef union
{
    uint32_t U;
    int32_t S;
    stm32_ll_usart_tdr_b B;
}stm32_ll_usart_tdr_t;

typedef uint32_t baudrate_t;



typedef enum 
{
    error_ok = 0,
    error_nok = 1,
    error_txfailed = 2,
    error_rxfailed = 3,
    error_timeout = 4,
    error_nullptr = 5,
    error_invalid_parameter = 6,
}err_t;

typedef enum 
{
    uart_noerror,
    uart_parityerror,
    uart_framingerror,
    uart_startbitnoise,
    uart_overrunerror,
    uart_rxnotempty,
    uart_txempty,
    uart_busy,
    uart_invalid_parameter
}uarterror_t;

typedef enum
{
    datalen_7 = 0,
    datalen_8 = 1,
    datalen_9 = 2,
    datalen_invalid=3,
}datalen_t;

typedef enum 
{
    msb_first = 1,
    lsb_first = 0,
    dir_invalid = 2,
}datadirection_t;

typedef enum 
{
    full_duplex = 0,
    half_duplex = 1,
    duplex_invalid = 2,
}duplexity_t;

typedef enum
{
    one_stop_bit = 0,
    half_stop_bit = 1,
    one_halfstop_bit = 2,
    two_stop_bit = 3,
    invalid_stopbit = 4,
}stopbits_t;

typedef enum
{
    odd_parity = 1,
    even_parity = 0,
    none_parity = 2,
}parity_t;

typedef enum
{
    dma_rxenable = 0,
    dma_rxdisable = 1,
}dmarxenable_t;

typedef enum
{
    dma_txenable = 0,
    dma_txdisable = 1,
}dmatxenable_t;

typedef enum
{
    uart_disable = 0,
    uart_enable = 1
}Uartenable_t;

typedef enum
{
    wakeup_on_address = 0,
    wakeup_on_start = 2,
    wakeup_on_rx_not_empty = 3
}wakeupsource_t;

typedef struct uart_ll_config_
{
  baudrate_t  baudrate;
  datalen_t  datalen;
  datadirection_t  datadirection;
  duplexity_t  duplexity;
  stopbits_t  stopbits;
  parity_t  parity;
  dmatxenable_t  dmatxenable;
  dmarxenable_t  dmarxenable ;
}uart_ll_config_t;

typedef void (*sendresponse_t)(const uint8_t *ptr);
typedef void (*callback_t)(void);
typedef struct uartcmddb_
{
    const uint8_t *cmd;
    const uint8_t *response;
    sendresponse_t function;
    callback_t cb;

}uartcmddb_t;


err_t Uart_ll_Init(uart_ll_config_t *uart_ll_config);
err_t Uart_ll_SendByte(uint8_t byte);
err_t Uart_ll_ReceiveByte(uint8_t *byte);
void init_usart(void);
void printdebugstring(const uint8_t *debugmessage);
err_t readuntillnewline(uint8_t *buffer);

void getevent(void);
err_t sendresponse(uint8_t *ptr);
void runfsm(void);

void turnonled(void);
void turnoffled(void);
#endif

