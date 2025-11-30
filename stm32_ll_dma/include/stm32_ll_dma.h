#ifndef STM32_LL_DRIVERS_H
#define STM32_LL_DRIVERS_H

#include <stm32l433xx.h>
#define DMA_CCR_ADDRESS(CHANNELNUM)         (DMA1_BASE + 0x08 + (0x14*(CHANNELNUM-1)))
#define DMA_CNDTRX_ADDRESS(CHANNELNUM)      (DMA1_BASE + 0x0C  + (0x14*(CHANNELNUM-1)))
#define DMA_CPARX_ADDRESS(CHANNELNUM)       (DMA1_BASE + 0x10  + (0x14*(CHANNELNUM-1)))
#define DMA_CMARX_ADDRESS(CHANNELNUM)       (DMA1_BASE + 0x14  + (0x14*(CHANNELNUM-1)))

typedef struct dma_isr_
{
    uint32_t gif1 : 1;
    uint32_t tcif1 : 1;
    uint32_t htif1 : 1;
    uint32_t teif1 : 1;
    uint32_t gif2 : 1;
    uint32_t tcif2 : 1;
    uint32_t htif2 : 1;
    uint32_t teif2 : 1;
    uint32_t gif3 : 1;
    uint32_t tcif3 : 1;
    uint32_t htif3 : 1;
    uint32_t teif3 : 1;
    uint32_t gif4 : 1;
    uint32_t tcif4 : 1;
    uint32_t htif4 : 1;
    uint32_t teif4 : 1;
    uint32_t gif5 : 1;
    uint32_t tcif5 : 1;
    uint32_t htif5 : 1;
    uint32_t teif5 : 1;
    uint32_t gif6 : 1;
    uint32_t tcif6 : 1;
    uint32_t htif6 : 1;
    uint32_t teif6 : 1;
    uint32_t gif7 : 1;
    uint32_t tcif7 : 1;
    uint32_t htif7 : 1;
    uint32_t teif7 : 1;
    uint32_t res   : 4;
}dma_isr_b;

typedef union dma_isr_reg_
{
    dma_isr_b B;
    uint32_t  U;
    int32_t   S;
}dma_isr_reg_t;

typedef struct dma_ifcr_
{
    uint32_t cgif1 : 1;
    uint32_t ctcif1 : 1;
    uint32_t chtif1 : 1;
    uint32_t cteif1 : 1;
    uint32_t cgif2 : 1;
    uint32_t ctcif2 : 1;
    uint32_t chtif2 : 1;
    uint32_t cteif2 : 1;
    uint32_t cgif3 : 1;
    uint32_t ctcif3 : 1;
    uint32_t chtif3 : 1;
    uint32_t cteif3 : 1;
    uint32_t cgif4 : 1;
    uint32_t ctcif4 : 1;
    uint32_t chtif4 : 1;
    uint32_t cteif4 : 1;
    uint32_t cgif5 : 1;
    uint32_t ctcif5 : 1;
    uint32_t chtif5 : 1;
    uint32_t cteif5 : 1;
    uint32_t cgif6 : 1;
    uint32_t ctcif6 : 1;
    uint32_t chtif6 : 1;
    uint32_t cteif6 : 1;
    uint32_t cgif7 : 1;
    uint32_t ctcif7 : 1;
    uint32_t chtif7 : 1;
    uint32_t cteif7 : 1;
    uint32_t res   : 4;
}dma_ifcr_b;

typedef union dma_ifcr_reg_
{
    dma_isr_b B;
    uint32_t  U;
    int32_t   S;
}dma_ifcr_reg_t;


typedef struct dma_ccrx_
{
      uint32_t en:1;
      uint32_t tcie : 1;
      uint32_t htie : 1;
      uint32_t teie : 1;
      uint32_t dir : 1;
      uint32_t circ : 1;
      uint32_t pinc : 1;
      uint32_t minc : 1;
      uint32_t psize : 2;
      uint32_t msize : 2;
      uint32_t pl : 2;
      uint32_t mem2mem : 1;
      uint32_t res : 17;

}dma_ccrx_b;

typedef union dma_ccrx_reg_
{
    dma_ccrx_b B;
    uint32_t U;
    int32_t S;
}dma_ccrx_reg_t;

typedef struct dma_cndtrx_
{
    uint32_t ndt : 16;
    uint32_t res : 16;
}dma_cndtrx_b;

typedef union dma_cndtrx_reg_
{
    dma_cndtrx_b B;
    uint32_t U;
    int32_t S;
}dma_cndtrx_reg_t;

typedef struct dma_cparx_
{
    uint32_t pa : 32;
}dma_cparx_b;

typedef union dma_cparx_reg_
{
    dma_cparx_b B;
    uint32_t U;
    int32_t S;
}dma_cparx_reg_t;


typedef struct dma_cmarx_
{
    uint32_t pa : 32;
}dma_cmarx_b;

typedef union dma_cmarx_reg_
{
    dma_cmarx_b B;
    uint32_t U;
    int32_t S;
}dma_cmarx_reg_t;


typedef struct dma_cselr_
{
    uint32_t c1s : 4;
    uint32_t c2s : 4;
    uint32_t c3s : 4;
    uint32_t c4s : 4;
    uint32_t c5s : 4;
    uint32_t c6s : 4;
    uint32_t c7s : 4;
    uint32_t res : 4;

}dma_cselr_b;

typedef union dma_cselr_reg_
{
    dma_cselr_b B;
    uint32_t U;
    int32_t S;
}dma_cselr_reg_t;

typedef enum 
{
    DVERY_HIGH,
    DHIGH,
    DMEDIUM,
    DLOW
}prio_t;

typedef enum 
{
    BYTE,
    HALFWORD,
    WORD
}packet_t;

typedef enum 
{
    MEM_TO_PERIPH,
    PERIPH_TO_MEM,
    PERIPH_TO_PERIPH,
}transfermode_t;

typedef enum 
{
    FULL_TX,
    HALF_TX,
    ERROR_TX,
}dmaisr_t;

typedef enum
{
    fail,
    ok,
}ErrDma_t;

ErrDma_t DmaInit(uint8_t dmachannelnumer,uint32_t *src , uint32_t *dest);
ErrDma_t DmaSetPrio(uint8_t chIdx , prio_t prio);
ErrDma_t DmaSetPcktSize(uint8_t chIdx,packet_t pckt);
ErrDma_t DmaSetDataSize(uint8_t chIdx,uint16_t size);
ErrDma_t DmaSetTransferMode(uint8_t chIdx,transfermode_t mode);
ErrDma_t DmaSetInterrupt(uint8_t chIdx,dmaisr_t isrtype);


#endif
