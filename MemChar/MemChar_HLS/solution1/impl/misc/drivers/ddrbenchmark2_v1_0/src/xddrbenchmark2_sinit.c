// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xddrbenchmark2.h"

extern XDdrbenchmark2_Config XDdrbenchmark2_ConfigTable[];

XDdrbenchmark2_Config *XDdrbenchmark2_LookupConfig(u16 DeviceId) {
	XDdrbenchmark2_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XDDRBENCHMARK2_NUM_INSTANCES; Index++) {
		if (XDdrbenchmark2_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XDdrbenchmark2_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XDdrbenchmark2_Initialize(XDdrbenchmark2 *InstancePtr, u16 DeviceId) {
	XDdrbenchmark2_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XDdrbenchmark2_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XDdrbenchmark2_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

