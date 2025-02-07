################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/ssp/src/driver/r_elc/r_elc.c 

C_DEPS += \
./synergy/ssp/src/driver/r_elc/r_elc.d 

OBJS += \
./synergy/ssp/src/driver/r_elc/r_elc.o 

SREC += \
LCD_Display.srec 

MAP += \
LCD_Display.map 


# Each subdirectory must supply rules for building sources it contributes
synergy/ssp/src/driver/r_elc/%.o: ../synergy/ssp/src/driver/r_elc/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -gdwarf-4 -D_RENESAS_SYNERGY_ -I"F:/Advanced Engineering/Programming/e2_studio/LCD_Display/synergy_cfg/ssp_cfg/bsp" -I"F:/Advanced Engineering/Programming/e2_studio/LCD_Display/synergy_cfg/ssp_cfg/driver" -I"F:/Advanced Engineering/Programming/e2_studio/LCD_Display/synergy/ssp/inc" -I"F:/Advanced Engineering/Programming/e2_studio/LCD_Display/synergy/ssp/inc/bsp" -I"F:/Advanced Engineering/Programming/e2_studio/LCD_Display/synergy/ssp/inc/bsp/cmsis/Include" -I"F:/Advanced Engineering/Programming/e2_studio/LCD_Display/synergy/ssp/inc/driver/api" -I"F:/Advanced Engineering/Programming/e2_studio/LCD_Display/synergy/ssp/inc/driver/instances" -I"F:/Advanced Engineering/Programming/e2_studio/LCD_Display/src" -I"F:/Advanced Engineering/Programming/e2_studio/LCD_Display/src/synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

