//@inproceedings{iron2021,
//author = {Conficconi, Davide and D'Arnese, Eleonora and Del Sozzo, Emanuele, and Sciuto, Donatella, and Santambrogio, Marco D.},
//title = {A Framework for Customizable FPGA-based Image Registration Accelerators},
//booktitle = {The 2021 ACM/SIGDA International Symposium on Field-Programmable Gate Arrays},
//series = {FPGA '21},
//year = {2021}
//}
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>
#include <stdio.h>
#include <chrono>
#include <fstream>
#include <string>
#include <cstring>


#include "ddrbenchmark.hpp"


#define MAGIC_NUMBER 1000

#define BANDWIDTH 512
#define HOST_DATA_BITWIDTH 32
#define AP_UINT_FACTOR BANDWIDTH / HOST_DATA_BITWIDTH
#define ARRAY_TEST_DIM MAGIC_NUMBER * AP_UINT_FACTOR
#define RANGE_UPPER_BOUND 255

#define REPETITIONS 100


// perform a test with random images
void random_test();

// // exec effectively the test
// void hw_test(int * ref, bool res);
// execute a single test and display results and time
void execTest(int * ref);

// execute the test in order to get avg execution times

void testCheck(ap_uint<512> *ref, ap_uint<512> *out,bool *result){
	for(int i=0;i<ARRAY_TEST_DIM;i++){
		if(*(ref+i) != *(out+i))
			*result = false;
	}
	*result=true;
}


void execTest(ap_uint<512> * ref, ap_uint<512> * out){

   bool result=true;

   drambenchmark_top(ref, out);

   //read back result
   testCheck(ref,out, &result);
   //
   printf("%d\n", result);
   std::cout << "result hw " << result << std::endl;

}

void execTestMultiple(ap_uint<512> * ref, ap_uint<512> * out){
  double tot_time_sw = 0.0;
  double tot_time_hw = 0.0;
  double sw_avg = 0.0;
  double hw_avg = 0.0;
  bool result=true;
  int rep=0;

  for (int i = 0; i < REPETITIONS;i++)
  {

    drambenchmark_top(ref, out);
   //read back result
   testCheck(ref,out,&result);
   //
   std::cout << "result hw " << i << result << std::endl;
   rep++;
   result = true;
  }
  rep=0;
}


void random_test(){
   std::cout << "************************" << std::endl;
   std::cout  << std::endl;
   std::cout << "Random input test" << std::endl;
   std::cout  << std::endl;
   std::cout << "************************" << std::endl;

   ap_uint<512> ref[ARRAY_TEST_DIM];
   ap_uint<512> out[ARRAY_TEST_DIM];

   int myseed = 1234;

   std::default_random_engine rng(myseed);
   std::uniform_int_distribution<int> rng_dist(0, RANGE_UPPER_BOUND);

   for(int i=0;i<ARRAY_TEST_DIM;i++){
         ref[i]=static_cast<int>(rng_dist(rng));
         out[i]=0;
   }

   std::string s = "Rand";
   execTest(ref,out);
    #ifdef AVERAGE_REPS
      execTestMultiple(ref,out);
    #endif
}




int main(int argc, char * argv[]){
   
   random_test();
   std::cout  << std::endl;
   std::cout  << std::endl;
   std::cout << "************************" << std::endl;
   std::cout  << std::endl;
   std::cout << "End of Random input test" << std::endl;
   std::cout  << std::endl;
   std::cout << "************************" << std::endl;

   return 0;
}


