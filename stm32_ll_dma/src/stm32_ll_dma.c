#include "stm32_ll_dma.h"
#include <stdint.h>
#include <stddef.h>


volatile dma_isr_reg_t *dma1_isr_reg = (volatile dma_isr_reg_t *)(DMA1_BASE + 0x00);
volatile dma_ifcr_reg_t *dma1_ifcr_reg = (volatile dma_ifcr_reg_t *)(DMA1_BASE + 0x04);
volatile dma_ccrx_reg_t *dma1_ccrx_reg[7] = { 
                                                (volatile dma_ccrx_reg_t *)(DMA_CCR_ADDRESS(1)), 
                                                (volatile dma_ccrx_reg_t *)(DMA_CCR_ADDRESS(2)), 
                                                (volatile dma_ccrx_reg_t *)(DMA_CCR_ADDRESS(3)), 
                                                (volatile dma_ccrx_reg_t *)(DMA_CCR_ADDRESS(4)), 
                                                (volatile dma_ccrx_reg_t *)(DMA_CCR_ADDRESS(5)), 
                                                (volatile dma_ccrx_reg_t *)(DMA_CCR_ADDRESS(6)), 
                                                (volatile dma_ccrx_reg_t *)(DMA_CCR_ADDRESS(7)) 
                                            };
volatile dma_cndtrx_reg_t *dma1_cndtrx_reg[7] = { 
                                                (volatile dma_cndtrx_reg_t *)(DMA_CNDTRX_ADDRESS(1)), 
                                                (volatile dma_cndtrx_reg_t *)(DMA_CNDTRX_ADDRESS(2)), 
                                                (volatile dma_cndtrx_reg_t *)(DMA_CNDTRX_ADDRESS(3)), 
                                                (volatile dma_cndtrx_reg_t *)(DMA_CNDTRX_ADDRESS(4)), 
                                                (volatile dma_cndtrx_reg_t *)(DMA_CNDTRX_ADDRESS(5)), 
                                                (volatile dma_cndtrx_reg_t *)(DMA_CNDTRX_ADDRESS(6)), 
                                                (volatile dma_cndtrx_reg_t *)(DMA_CNDTRX_ADDRESS(7)) 
                                            };
volatile dma_cparx_reg_t *dma1_cparx_reg[7] = { 
                                                (volatile dma_cparx_reg_t *)(DMA_CPARX_ADDRESS(1)) , 
                                                (volatile dma_cparx_reg_t *)(DMA_CPARX_ADDRESS(2)) , 
                                                (volatile dma_cparx_reg_t *)(DMA_CPARX_ADDRESS(3)) , 
                                                (volatile dma_cparx_reg_t *)(DMA_CPARX_ADDRESS(4)) , 
                                                (volatile dma_cparx_reg_t *)(DMA_CPARX_ADDRESS(5)) , 
                                                (volatile dma_cparx_reg_t *)(DMA_CPARX_ADDRESS(6)) , 
                                                (volatile dma_cparx_reg_t *)(DMA_CPARX_ADDRESS(7))  
                                            };
volatile dma_cmarx_reg_t *dma1_cmarx_reg[7] = { 
                                                (volatile dma_cmarx_reg_t *)(DMA_CMARX_ADDRESS(1)) , 
                                                (volatile dma_cmarx_reg_t *)(DMA_CMARX_ADDRESS(2)) , 
                                                (volatile dma_cmarx_reg_t *)(DMA_CMARX_ADDRESS(3)) , 
                                                (volatile dma_cmarx_reg_t *)(DMA_CMARX_ADDRESS(4)) , 
                                                (volatile dma_cmarx_reg_t *)(DMA_CMARX_ADDRESS(5)) , 
                                                (volatile dma_cmarx_reg_t *)(DMA_CMARX_ADDRESS(6)) , 
                                                (volatile dma_cmarx_reg_t *)(DMA_CMARX_ADDRESS(7))  
                                            };
volatile dma_cselr_reg_t *dma1_cselr_reg = (volatile dma_cselr_reg_t *)(DMA1_BASE + 0xA8);


ErrDma_t DmaInit(uint8_t dmachannelnumer,uint32_t *src , uint32_t *dest)
{
    ErrDma_t ErrDma;

    ErrDma = ((src==NULL || dest==NULL)?(fail):(ok));
    if(ErrDma==ok)
    {
        dma1_ccrx_reg[dmachannelnumer-1]->B.en = 1;
    }
    else
    {
        return ErrDma;
    }

    
}
ErrDma_t DmaSetPrio(uint8_t chIdx , prio_t prio)
{

}
ErrDma_t DmaSetPcktSize(uint8_t chIdx,packet_t pckt)
{

}
ErrDma_t DmaSetDataSize(uint8_t chIdx,uint16_t size)
{

}
ErrDma_t DmaSetTransferMode(uint8_t chIdx,transfermode_t mode)
{

}
ErrDma_t DmaSetInterrupt(uint8_t chIdx,dmaisr_t isrtype)
{

}

