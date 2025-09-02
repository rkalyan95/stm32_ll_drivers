CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc


COMMON_INCLUDES := -I ../CMSIS/Core/Include/ \
				   -I ../Device/ARM/ARMCM4/Include/ \
				   -I ../include/stm32l433/ \
				   -I ./include \
				   -I ../os/include\
				   -I ./src \

CFLAGS:= -g $(COMMON_INCLUDES) -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -std=gnu99 -O0 -g -gdwarf-4

CSOURCES := src/stm32l433_ll_rcc.c  \
			src/stm32l433_ll_rcc_cfg.c

OBJS := $(CSOURCES:.c=.o)

# Inside each submodule Makefile (e.g., stm32_ll_gpio/Makefile)
all: $(OBJS)
	@echo $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)