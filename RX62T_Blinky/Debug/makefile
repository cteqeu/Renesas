################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf *.lst *.lis *.lpp *.map *.x *.lbp src/*.src src/*.p src/*.pp *.bls *.libelf *.lbk *.abs

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_UPPER_DEPS)),)
-include $(C++_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(O_DEPS)),)
-include $(O_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(ABS_DEPS)),)
-include $(ABS_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(CP_DEPS)),)
-include $(CP_DEPS)
endif
ifneq ($(strip $(CPP_UPPER_DEPS)),)
-include $(CPP_UPPER_DEPS)
endif
ifneq ($(strip $(OBJ_DEPS)),)
-include $(OBJ_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CP_UPPER_DEPS)),)
-include $(CP_UPPER_DEPS)
endif
ifneq ($(strip $(CC_UPPER_DEPS)),)
-include $(CC_UPPER_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_UPPER_DEPS)),)
-include $(CXX_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LINKER_OUTPUT_OUTPUTS += \
RX62T_Blinky.abs \

LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \
RX62T_Blinky.lib \


# All Target
all: RX62T_Blinky.mot
	@echo 'Build complete.'

# Tool invocations
RX62T_Blinky.mot: $(LINKER_OUTPUT_OUTPUTS)
	@echo 'Invoking: Converter'
	optlnk   "C:\Users\20002890\My Documents\e2studio\workspace\RX62T_Blinky\Debug\RX62T_Blinky.abs" -form=stype  -output="C:\Users\20002890\My Documents\e2studio\workspace\RX62T_Blinky\Debug\RX62T_Blinky.mot"
	@echo 'Finished building target:'
	@echo.
	$(MAKE) --no-print-directory post-build

RX62T_Blinky.abs: $(OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS)
	@echo 'Invoking: Linker'
	@echo 'Building target:'
	optlnk  $(USER_OBJS) $(LIBS) -library="C:\Users\20002890\MYDOCU~1\e2studio\WORKSP~1\RX62T_~1\Debug\RX62T_Blinky.lib"   -noprelink -list="RX62T_Blinky.map" -nooptimize -start=B_1,R_1,B_2,R_2,B,R,SU,SI/01000,PResetPRG/0FFFF8000,C_1,C_2,C,C"$$"*,D*,P,PIntPRG,W*/0FFFF8100,FIXEDVECT/0FFFFFFD0 -nologo -nomessage -rom=D=R,D_1=R_1,D_2=R_2 -output="C:\Users\20002890\My Documents\e2studio\workspace\RX62T_Blinky\Debug\RX62T_Blinky.abs" -subcommand="C:/Users/20002890/My Documents/e2studio/workspace/RX62T_Blinky\Debug\LinkerSubCommand.tmp"
	@echo 'Finished building:'
	@echo.

RX62T_Blinky.lib:  
	@echo 'Invoking: Standard Library'
	lbgrx -head=runtime,math,stdio,stdlib,string,new -section=L=C -cpu=rx600 -endian=big -output="RX62T_Blinky.lib"
	@echo 'Finished building:'
	@echo.

# Other Targets
clean:
	-$(RM) $(C++_UPPER_DEPS)$(OBJS)$(C_DEPS)$(O_DEPS)$(S_DEPS)$(ABS_DEPS)$(CONVERTOR_OUTPUT_OUTPUTS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(SRC_DEPS)$(CC_DEPS)$(LINKER_OUTPUT_OUTPUTS)$(SRC_UPPER_DEPS)$(CP_DEPS)$(CPP_UPPER_DEPS)$(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS)$(OBJ_DEPS)$(CPP_DEPS)$(CP_UPPER_DEPS)$(CC_UPPER_DEPS)$(C_UPPER_DEPS)$(CXX_UPPER_DEPS) RX62T_Blinky.mot
	@echo.
	@echo 'Clean complete.'

post-build:
	@echo.
	-C:\Renesas\e2studio\DEBUGC~1\RX\RX_CON~1.EXE RX62T_Blinky.abs RX62T_Blinky.x
	@echo.
	@echo.

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
