#ifndef DDRBENCHMARK2_HPP
#define DDRBENCHMARK2_HPP

#include "string.h"
#include <stdlib.h>
#include <ap_int.h>
#include <iostream>

auto constexpr DATA_WIDTH = 512;

using TYPE = ap_uint<DATA_WIDTH>;

extern void  ddrbenchmark2(TYPE * in1, TYPE * out, int64_t buf_size);



#endif //DDRBENCHMARK2_HPP
