
#ifndef MU_BLDC_TI
#define MU_BLDC_TI

#include <stdint.h>
#include "hardware.h"
int  TI_I2C_bus_write( uint16_t reg_addr, uint32_t data);
void ti_init(void);

// First the COMMON once same for MCT and MCF
// 8.7.1 Algorithm_Configuration Registers
#define TI_MCx8316A_ISD_CONFIG               0x80
//8.8.1 Fault_Status Registers
#define TI_MCx8316A_GATE_DRIVER_FAULT_STATUS 0xE0
#define TI_MCx8316A_CONTROLLER_FAULT_STATUS  0xE2
// 8.8.2 System_Status Registers
//  System Status Register1 Section 8.8.2.1  
#define TI_MCx8316A_SYS_STATUS1             0xE4
#define TI_MCx8316A_SYS_STATUS2             0xEA
#define TI_MCx8316A_SYS_STATUS3             0xEC
//8.8.3 Algo_Control Registers
#define TI_MCx8316A_ALGO_CTRL1              0xE6
//8.8.4 Device_Control Registers
#define TI_MCx8316A_DEVICE_CTRL             0xE8

// 8.7.4 Gate_Driver_Configuration Registers  
#define TI_MCx8316A_GD_CONFIG1   0xAC
#define TI_MCx8316A_GD_CONFIG2   0xAE





#ifdef TI_TRAPEZUID

#define TI_MCT8316A_MOTOR_STARTUP1           0x82
#define TI_MCT8316A_MOTOR_STARTUP2           0x84
#define TI_MCT8316A_CLOSED_LOOP1             0x86 
#define TI_MCT8316A_CLOSED_LOOP2             0x88
#define TI_MCT8316A_CLOSED_LOOP3             0x8A
#define TI_MCT8316A_CLOSED_LOOP4             0x8C
#define TI_MCT8316A_CONST_SPEED              0x8E
#define TI_MCT8316A_CONST_PWR                0x90
#define TI_MCT8316A_150_DEG_TWO_PH_PROFILE   0x96
#define TI_MCT8316A_150_DEG_THREE_PH_PROFILE 0x98
#define TI_MCT8316A_TRAP_CONFIG1             0x9A
#define TI_MCT8316A_TRAP_CONFIG2             0x9C

//8.7.2 Fault_Configuration Registers
#define TI_MCT8316A_FAULT_CONFIG1   0x92
#define TI_MCT8316A_FAULT_CONFIG2   0x94
//8.7.3 Hardware_Configuration Registers
#define TI_MCT8316A_PIN_CONFIG1   0xA4
#define TI_MCT8316A_PIN_CONFIG2   0xA6
#define TI_MCT8316A_DEVICE_CONFIG   0xA8
#define TI_MCT8316A_PERIPH_CONFIG 0xAA

#else 


#define TI_MCF8316A_ALGO_CTRL1   0x0EC

#define TI_MCF8316A_ISD_CONFIG                   0x80
#define TI_MCF8316A_REV_DRIVE_CONFIG             0x82
#define TI_MCF8316A_MOTOR_STARTUP1               0x84
#define TI_MCF8316A_MOTOR_STARTUP2               0x86
#define TI_MCF8316A_CLOSED_LOOP1                 0x88
#define TI_MCF8316A_CLOSED_LOOP2                 0x8A
#define TI_MCF8316A_CLOSED_LOOP3                 0x8C
#define TI_MCF8316A_CLOSED_LOOP4                 0x8E
#define TI_MCF8316A_SPEED_PROFILES1              0x94
#define TI_MCF8316A_SPEED_PROFILES2              0x96
#define TI_MCF8316A_SPEED_PROFILES3              0x98
#define TI_MCF8316A_SPEED_PROFILES4              0x9A
#define TI_MCF8316A_SPEED_PROFILES5              0x9C
#define TI_MCF8316A_SPEED_PROFILES6              0x9E

#define TI_MCF8316A_FAULT_CONFIG1                0x90
#define TI_MCF8316A_FAULT_CONFIG2                0x92

#define TI_MCF8316A_PIN_CONFIG                   0xA4
#define TI_MCF8316A_DEVICE_CONFIG1               0xA6
#define TI_MCF8316A_DEVICE_CONFIG2               0xA8
#define TI_MCF8316A_PERI_CONFIG1                 0xAA
#define TI_MCF8316A_GD_CONFIG1                   0xAC
#define TI_MCF8316A_GD_CONFIG2                   0xAE

#define TI_MCF8316A_ALGORITHM_STATE             0x210
#define TI_MCF8316A_FG_SPEED_FDBK               0x216
#define TI_MCF8316A_BUS_CURRENT                 0x410
#define TI_MCF8316A_PHASE_CURRENT_A             0x43E
#define TI_MCF8316A_PHASE_CURRENT_B             0x440
#define TI_MCF8316A_PHASE_CURRENT_C             0x442
#define TI_MCF8316A_CSA_GAIN_FEEDBACK           0x466
#define TI_MCF8316A_VOLTAGE_GAIN_FEEDBACK       0x476
#define TI_MCF8316A_VM_VOLTAGE                  0x478
#define TI_MCF8316A_PHASE_VOLTAGE_VA            0x47E
#define TI_MCF8316A_PHASE_VOLTAGE_VB            0x480
#define TI_MCF8316A_PHASE_VOLTAGE_VC            0x482
#define TI_MCF8316A_SIN_COMMUTATION_ANGLE       0x4BA
#define TI_MCF8316A_COS_COMMUTATION_ANGLE       0x4BC
#define TI_MCF8316A_IALPHA                      0x4D4
#define TI_MCF8316A_IBETA                       0x4D6
#define TI_MCF8316A_VALPHA                      0x4D8
#define TI_MCF8316A_VBETA                       0x4DA
#define TI_MCF8316A_ID                          0x4E4
#define TI_MCF8316A_IQ                          0x4E6
#define TI_MCF8316A_VD                          0x4E8
#define TI_MCF8316A_VQ                          0x4EA
#define TI_MCF8316A_IQ_REF_ROTOR_ALIGN          0x524
#define TI_MCF8316A_SPEED_REF_OPEN_LOOP         0x53A
#define TI_MCF8316A_IQ_REF_OPEN_LOOP            0x548
#define TI_MCF8316A_SPEED_REF_CLOSED_LOOP       0x5CC
#define TI_MCF8316A_ID_REF_CLOSED_LOOP          0x5FC
#define TI_MCF8316A_IQ_REF_CLOSED_LOOP          0x5FE
#define TI_MCF8316A_ISD_STATE                   0x67A
#define TI_MCF8316A_ISD_SPEED                   0x684
#define TI_MCF8316A_IPD_STATE                   0x6B8
#define TI_MCF8316A_IPD_ANGLE                   0x6FC
#define TI_MCF8316A_ED                          0x742
#define TI_MCF8316A_EQ                          0x744
#define TI_MCF8316A_SPEED_FDBK                  0x752
#define TI_MCF8316A_THETA_EST                   0x756

//#define TI_MCF8316A_ALGO_CTRL1                   0xEC
#define TI_MCF8316A_ALGO_CTRL2                   0xEE
#define TI_MCF8316A_CURRENT_PI                   0xF0
#define TI_MCF8316A_SPEED_PI                     0xF2
//#define TI_MCF8316A_
        
#define TI_MCF8316A_INT_ALGO_1   0x0A0
#define TI_MCF8316A_INT_ALGO_2   0x0A2
#define TI_MCF8316A_DEV_CTRL     0xEA
    
#endif


#endif
