// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xddrbenchmark2.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XDdrbenchmark2_CfgInitialize(XDdrbenchmark2 *InstancePtr, XDdrbenchmark2_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XDdrbenchmark2_Start(XDdrbenchmark2 *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_AP_CTRL) & 0x80;
    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XDdrbenchmark2_IsDone(XDdrbenchmark2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XDdrbenchmark2_IsIdle(XDdrbenchmark2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XDdrbenchmark2_IsReady(XDdrbenchmark2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XDdrbenchmark2_EnableAutoRestart(XDdrbenchmark2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XDdrbenchmark2_DisableAutoRestart(XDdrbenchmark2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_AP_CTRL, 0);
}

void XDdrbenchmark2_Set_input_r(XDdrbenchmark2 *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_INPUT_R_DATA, (u32)(Data));
    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_INPUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XDdrbenchmark2_Get_input_r(XDdrbenchmark2 *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_INPUT_R_DATA);
    Data += (u64)XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_INPUT_R_DATA + 4) << 32;
    return Data;
}

void XDdrbenchmark2_Set_output_r(XDdrbenchmark2 *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_OUTPUT_R_DATA, (u32)(Data));
    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_OUTPUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XDdrbenchmark2_Get_output_r(XDdrbenchmark2 *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_OUTPUT_R_DATA);
    Data += (u64)XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_OUTPUT_R_DATA + 4) << 32;
    return Data;
}

void XDdrbenchmark2_InterruptGlobalEnable(XDdrbenchmark2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_GIE, 1);
}

void XDdrbenchmark2_InterruptGlobalDisable(XDdrbenchmark2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_GIE, 0);
}

void XDdrbenchmark2_InterruptEnable(XDdrbenchmark2 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_IER);
    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_IER, Register | Mask);
}

void XDdrbenchmark2_InterruptDisable(XDdrbenchmark2 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_IER);
    XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_IER, Register & (~Mask));
}

void XDdrbenchmark2_InterruptClear(XDdrbenchmark2 *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    //XDdrbenchmark2_WriteReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_ISR, Mask);
}

u32 XDdrbenchmark2_InterruptGetEnabled(XDdrbenchmark2 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_IER);
}

u32 XDdrbenchmark2_InterruptGetStatus(XDdrbenchmark2 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    // Current Interrupt Clear Behavior is Clear on Read(COR).
    return XDdrbenchmark2_ReadReg(InstancePtr->Control_BaseAddress, XDDRBENCHMARK2_CONTROL_ADDR_ISR);
}

