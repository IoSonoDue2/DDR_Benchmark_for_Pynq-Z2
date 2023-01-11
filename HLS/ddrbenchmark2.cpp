#include "ddrbenchmark2.hpp"


void ddrbenchmark2(TYPE* input, TYPE* output, const int modo) {

#pragma HLS INTERFACE m_axi port = input depth=arr_depth offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = output depth=arr_depth offset = slave bundle = gmem
#pragma HLS INTERFACE s_axilite port = modo bundle=control
#pragma HLS INTERFACE s_axilite port = input bundle=control
#pragma HLS INTERFACE s_axilite port = output bundle=control
#pragma HLS INTERFACE s_axilite port = return bundle=control

	TYPE temp[ARRAY_SIZE];
	TYPE write;
	TYPE outData=123;


if(modo == 0){
	ReadWrite:for(int i=0; i < ARRAY_SIZE; i++){ //lettura e scritttura
				#pragma HLS PIPELINE
				temp[i] = *(input+i);
				*(output+i) =temp[i];

		}
}else if(modo == 1){
	read:for(int i=0; i < ARRAY_SIZE; i++){
				#pragma HLS PIPELINE
				write = *(input+i);//solo lettura


		}


}else{
	write:for(int i=0; i < ARRAY_SIZE; i++){
				#pragma HLS PIPELINE
		        *(output+i) = outData; //solo scrittura

		}

}




return;
}
