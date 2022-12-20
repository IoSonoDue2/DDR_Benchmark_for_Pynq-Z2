#ifndef DDRBENCHMARK_HPP
#define DDRBENCHMARK_HPP
#include "string.h"
#include <stdlib.h>
#include "ap_int.h"

#define INPUT_BIWIDTH 512
#define DATA_ARRAY_SIZE 1000

const unsigned int data_array_size_depth = DATA_ARRAY_SIZE;

extern void  drambenchmark_top(ap_uint<INPUT_BIWIDTH> * in1, ap_uint<INPUT_BIWIDTH> * out);



#endif //DDRBENCHMARK_HPP
