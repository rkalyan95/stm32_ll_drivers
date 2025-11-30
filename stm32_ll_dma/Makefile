# stm32_ll_gpio/Makefile (Located in project_root/stm32_ll_gpio/)

# --- Compiler ---
CC := arm-none-eabi-gcc

# --- Common Include Paths (relative to this Makefile's location) ---
COMMON_INCLUDES := \
    -I../CMSIS/Core/Include \
    -I../Device/ARM/ARMCM4/Include \
    -I../include/stm32l433 \
    -I../stm32_ll_gpio/include \
    -I./include \
    -I ../os/include\
    -I./src

# --- Compiler Flags ---
CFLAGS := -g $(COMMON_INCLUDES) -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -std=gnu99 -O0 -g -gdwarf-4 # <--- This line (14) MUST start at column 1, no leading spaces/tabs

# --- Source Files for GPIO module ---
CSOURCES := \
    src/stm32_ll_dma.c \

# --- Object Files for GPIO module (will be in this directory: stm32_ll_gpio/) ---
OBJS := $(CSOURCES:.c=.o)

# --- Phony Targets ---
.PHONY: all clean

# --- Main Build Rule for this module ---
# Inside each submodule Makefile (e.g., stm32_ll_gpio/Makefile)
all: $(OBJS)
	@echo $(OBJS)

# --- Compilation Rule (Generic for all .c to .o in this module) ---
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 
# --- Clean Rule for this module ---
clean:
	rm -f $(OBJS) 