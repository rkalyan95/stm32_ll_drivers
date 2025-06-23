::arm-none-eabi-gcc -I Device/ARM/ARMCM4/Include -I CMSIS/Core/Include -I include/stm32l433 -I stm32_ll_rcc/include -I stm32_ll_rcc/src  -g -gdwarf-4 -O0 -O0 main.c startup.c  -T linker_script.ld -o blink.elf -mcpu=cortex-m4 -mthumb -nostdlib -std=gnu99
arm-none-eabi-gcc ^
-I Device/ARM/ARMCM4/Include ^
-I CMSIS/Core/Include ^
-I include/stm32l433 ^
-I stm32_ll_rcc/include ^
-I stm32_ll_rcc/src ^
-g -gdwarf-4 -O0 ^
main.c ^
startup.c ^
stm32_ll_rcc/src/stm32l433_ll_rcc_cfg.c ^
stm32_ll_rcc/src/stm32l433_ll_rcc.c ^
-T linker_script.ld ^
-o blink.elf ^
-mcpu=cortex-m4 -mthumb -nostdlib -std=gnu99
openocd -f interface/stlink.cfg -f target/stm32l4x.cfg -c "program blink.elf verify reset"