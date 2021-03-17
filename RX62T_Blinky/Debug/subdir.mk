################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\RX62T_Blinky.c \
..\dbsct.c \
..\hwsetup.c \
..\intprg.c \
..\resetprg.c \
..\sbrk.c \
..\vecttbl.c 

OBJS += \
./RX62T_Blinky.obj \
./dbsct.obj \
./hwsetup.obj \
./intprg.obj \
./resetprg.obj \
./sbrk.obj \
./vecttbl.obj 

C_DEPS += \
./RX62T_Blinky.d \
./dbsct.d \
./hwsetup.d \
./intprg.d \
./resetprg.d \
./sbrk.d \
./vecttbl.d 


# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c %.d
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccrx -output=obj=$(dir $@)$(basename $(notdir $@)).obj -include=C:\Renesas\e2studio\Tools\Renesas\RX\1_2_1\include -debug -nologo -section=L=C -cpu=rx600 -endian=big  -lang=c "$<"
	@echo 'Finished building: $<'
	@echo.


# Each subdirectory must supply rules for scanning sources it contributes
%.d: ../%.c
	@echo 'Scanning started: $<'
	scandep1 -MM -MP -MF  "$(@:%.obj=%.d)" -MT  "$(@:%.obj=%.d)"  -IC:\Renesas\e2studio\Tools\Renesas\RX\1_2_1\include -D__RX600=1 -D__BIG=1   -D__FPU=1  -D__RON=1 -D__UCHAR=1 -D__DBL4=1 -D__UBIT=1 -D__BITRIGHT=1 -D__DOFF=1   -D__RENESAS__=1 -D__RENESAS_VERSION__=0x010201 -D__RX=1   -E -quiet -I. -C $<
	@echo 'Finished scanning: $<'
	@echo.

