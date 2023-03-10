#ifndef DDRBENCHMARK2_HPP
#define DDRBENCHMARK2_HPP

#include "string.h"
#include <stdlib.h>
#include <ap_int.h>
#include <iostream>

auto constexpr DATA_WIDTH = 64;
#define ARRAY_SIZE 16000
const unsigned int arr_depth = ARRAY_SIZE;

using TYPE = ap_uint<DATA_WIDTH>;

extern void ddrbenchmark2(TYPE* input, TYPE* output, const int mode);



#endif //DDRBENCHMARK2_HPP
