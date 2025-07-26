CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc


COMMON_INCLUDES := -I ../CMSIS/Core/Include/ \
				   -I ../Device/ARM/ARMCM4/Include/ \
				   -I ../include/stm32l433/ \
				   -I ../stm32_ll_gpio/include \
				   -I ../stm32_ll_rcc/include \
				   -I ../stm32_ll_syscfg/include \
				   -I ../stm32_ll_exti/include \
				   -I ../stm32_ll_flash/include \
				   -I ./include \
				   -I ./src \

CFLAGS=-o0 -g $(COMMON_INCLUDES) -mcpu=cortex-m4 -mthumb -nostdlib -std=gnu99 

CSOURCES := src/main.c  \
			src/startup.c\
			src/System_Fsm.c\

OBJS := $(CSOURCES:.c=.o)

# Inside each submodule Makefile (e.g., stm32_ll_gpio/Makefile)
all: $(OBJS)
	@echo $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
