This is a how to use document
 
Prerequisites : 

>>> STM32L433 Board , 
>>> arm-eabi toolchain 
>>> Make Toolchain
>>> stm32 programmer exe
>>> Any editor of your choice 

How to build 
>>> open command prompt in your cloned directory 
>>> run make
### or optionally 
### run make --clean and then run make


If you face any installation error : https://kleinembedded.com/stm32-without-cubeide-part-1-the-bare-necessities/

Once you get the build working , 
you can use the elf file to flash , you should 
see the built in LED blinking and 
also see the Clock on MCO PA8 pin using logic analyser
