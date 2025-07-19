@echo off
REM This script automates starting OpenOCD as a GDB server and then
REM launching arm-none-eabi-gdb to connect to your STM32L433.

REM This script should be placed in your project directory: D:\Rajat\proj_stmlowlevel_drivers

REM --- Configuration Section ---
REM IMPORTANT: Adjust these paths and filenames to match your setup!

REM Full path to your OpenOCD executable
set OPENOCD_EXEC=D:\Rajat\openocd\bin\openocd.exe

REM Full path to your OpenOCD 'scripts' folder
set OPENOCD_SCRIPTS_PATH="D:\Rajat\openocd\share\openocd\scripts"

REM GDB server port. Default for OpenOCD is 3333.
set GDB_PORT=3333

REM Name of your compiled ELF file (e.g., your_project.elf)
set ELF_FILE_NAME=stm32_ll_nucleo.elf 

REM Path to your ARM GDB executable.
set GDB_EXEC=arm-none-eabi-gdb.exe

REM --- OpenOCD Configuration Files ---
set INTERFACE_CFG=interface/stlink-v2-1.cfg
set TARGET_CFG=target/stm32l4x.cfg

REM --- Script Logic ---

REM Change directory to where this script is located (your project root)
cd /d "%~dp0"

REM Get the current directory (which is now the project root)
set CURRENT_DIR=%CD%

REM Construct the full path to the ELF file
set FULL_ELF_PATH="%CURRENT_DIR%\%ELF_FILE_NAME%"

REM --- Start OpenOCD GDB Server ---
echo Starting OpenOCD GDB Server...
start "OpenOCD Server" cmd /k "%OPENOCD_EXEC% -s %OPENOCD_SCRIPTS_PATH% -f %INTERFACE_CFG% -f %TARGET_CFG% -c ^"gdb_port %GDB_PORT%; telnet_port 4444; tcl_port 6666^""

REM Give OpenOCD a moment to start up and connect to the hardware
timeout /t 5 /nobreak > nul

REM --- Start GDB Client ---
echo Starting GDB client...
REM FIX: Removed -x .gdbinit and will try to connect manually after launch.
REM This simplifies the GDB launch to just loading the ELF.
start "GDB Debugger" cmd /k "%GDB_EXEC% %FULL_ELF_PATH%"

echo.
echo Debugging session initiated.
echo Two new command prompt windows should have appeared: "OpenOCD Server" and "GDB Debugger".
echo.
echo IMPORTANT: In the 'GDB Debugger' window, you will need to manually type:
echo target extended-remote localhost:%GDB_PORT%
echo monitor reset halt
echo load
echo break main
echo continue
echo.
pause
