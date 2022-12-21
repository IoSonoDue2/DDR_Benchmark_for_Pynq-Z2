#include "ddrbenchmark2.hpp"


void ddrbenchmark2(TYPE* input, TYPE* output, int64_t buf_size) {
#pragma HLS INTERFACE m_axi port = input offset = slave bundle = gmem 
#pragma HLS INTERFACE m_axi port = output offset = slave bundle = gmem 
#pragma HLS INTERFACE s_axilite port = input bundle=control
#pragma HLS INTERFACE s_axilite port = output bundle=control
#pragma HLS INTERFACE s_axilite port = buf_size bundle=control
#pragma HLS INTERFACE s_axilite port = return bundle=control

    TYPE in1_local[buf_size];

writing:	for(int i=0; i < buf_size; i++){
				#pragma HLS PIPELINE
				in1_local[i] = *(input+i);//scrive l'input in memoria
			}

reading: 	for(int i=0; i < buf_size; i++){
				#pragma HLS PIPELINE
				output[i] = in1_local[i]; //legge dalla memoria e scrive nel buffer di output
			}

return;
}
