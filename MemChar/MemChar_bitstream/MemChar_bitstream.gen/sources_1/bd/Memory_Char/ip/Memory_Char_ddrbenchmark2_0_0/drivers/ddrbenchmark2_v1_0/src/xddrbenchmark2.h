// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XDDRBENCHMARK2_H
#define XDDRBENCHMARK2_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xddrbenchmark2_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
} XDdrbenchmark2_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XDdrbenchmark2;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XDdrbenchmark2_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XDdrbenchmark2_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XDdrbenchmark2_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XDdrbenchmark2_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XDdrbenchmark2_Initialize(XDdrbenchmark2 *InstancePtr, u16 DeviceId);
XDdrbenchmark2_Config* XDdrbenchmark2_LookupConfig(u16 DeviceId);
int XDdrbenchmark2_CfgInitialize(XDdrbenchmark2 *InstancePtr, XDdrbenchmark2_Config *ConfigPtr);
#else
int XDdrbenchmark2_Initialize(XDdrbenchmark2 *InstancePtr, const char* InstanceName);
int XDdrbenchmark2_Release(XDdrbenchmark2 *InstancePtr);
#endif

void XDdrbenchmark2_Start(XDdrbenchmark2 *InstancePtr);
u32 XDdrbenchmark2_IsDone(XDdrbenchmark2 *InstancePtr);
u32 XDdrbenchmark2_IsIdle(XDdrbenchmark2 *InstancePtr);
u32 XDdrbenchmark2_IsReady(XDdrbenchmark2 *InstancePtr);
void XDdrbenchmark2_EnableAutoRestart(XDdrbenchmark2 *InstancePtr);
void XDdrbenchmark2_DisableAutoRestart(XDdrbenchmark2 *InstancePtr);

void XDdrbenchmark2_Set_input_r(XDdrbenchmark2 *InstancePtr, u64 Data);
u64 XDdrbenchmark2_Get_input_r(XDdrbenchmark2 *InstancePtr);
void XDdrbenchmark2_Set_output_r(XDdrbenchmark2 *InstancePtr, u64 Data);
u64 XDdrbenchmark2_Get_output_r(XDdrbenchmark2 *InstancePtr);

void XDdrbenchmark2_InterruptGlobalEnable(XDdrbenchmark2 *InstancePtr);
void XDdrbenchmark2_InterruptGlobalDisable(XDdrbenchmark2 *InstancePtr);
void XDdrbenchmark2_InterruptEnable(XDdrbenchmark2 *InstancePtr, u32 Mask);
void XDdrbenchmark2_InterruptDisable(XDdrbenchmark2 *InstancePtr, u32 Mask);
void XDdrbenchmark2_InterruptClear(XDdrbenchmark2 *InstancePtr, u32 Mask);
u32 XDdrbenchmark2_InterruptGetEnabled(XDdrbenchmark2 *InstancePtr);
u32 XDdrbenchmark2_InterruptGetStatus(XDdrbenchmark2 *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
