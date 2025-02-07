################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hal_entry.c 

C_DEPS += \
./src/hal_entry.d 

OBJS += \
./src/hal_entry.o 

SREC += \
S7G2_All_OPERATIONS.srec 

MAP += \
S7G2_All_OPERATIONS.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -gdwarf-4 -D_RENESAS_SYNERGY_ -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/synergy_cfg/ssp_cfg/bsp" -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/synergy_cfg/ssp_cfg/driver" -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/synergy/ssp/inc" -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/synergy/ssp/inc/bsp" -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/synergy/ssp/inc/bsp/cmsis/Include" -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/synergy/ssp/inc/driver/api" -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/synergy/ssp/inc/driver/instances" -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/src" -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/src/synergy_gen" -I"F:/Advanced Engineering/Programming/e2_studio/S7G2_All_OPERATIONS/synergy_cfg/ssp_cfg/framework/el" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

