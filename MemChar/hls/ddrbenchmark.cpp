#include "ddrbenchmark.hpp"


void drambenchmark_top(ap_uint<INPUT_BIWIDTH> * in1, ap_uint<INPUT_BIWIDTH> * out){

#pragma HLS INTERFACE m_axi port=in1 depth=data_array_size_depth offset=slave bundle=gmem //master axi per l'input
#pragma HLS INTERFACE m_axi port=out depth=data_array_size_depth offset=slave bundle=gmem //master axi per l'output
#pragma HLS INTERFACE s_axilite register port=in1 bundle=control
#pragma HLS INTERFACE s_axilite register port=out bundle=control  //slave credo per il segnale di migrazione dell'input ed output
#pragma HLS INTERFACE s_axilite register port=return bundle=control

ap_uint<INPUT_BIWIDTH> in1_local[DATA_ARRAY_SIZE];

writing:	for(int i=0; i < DATA_ARRAY_SIZE; i++){
				#pragma HLS PIPELINE
				in1_local[i] = *(in1+i);//scrive l'input in memoria
			}

reading: 	for(int i=0; i < DATA_ARRAY_SIZE; i++){
				#pragma HLS PIPELINE
				out[i] = in1_local[i]; //legge dalla memoria e scrive nel buffer di output
			}

return;

}

