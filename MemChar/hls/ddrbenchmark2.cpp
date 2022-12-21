#include "ddrbenchmark2.hpp"


void ddrbenchmark2(TYPE* input, TYPE* output) {

#pragma HLS INTERFACE m_axi port = input depth=arr_depth offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = output depth=arr_depth offset = slave bundle = gmem
#pragma HLS INTERFACE s_axilite port = input bundle=control
#pragma HLS INTERFACE s_axilite port = output bundle=control
#pragma HLS INTERFACE s_axilite port = return bundle=control

	TYPE temp = 0;


access:	for(int i=0; i < ARRAY_SIZE; i++){
				#pragma HLS PIPELINE
				temp = *(input+i);//scrive l'input in memoria
				*(output+i) =temp;//legge dalla memoria

			}




return;
}
