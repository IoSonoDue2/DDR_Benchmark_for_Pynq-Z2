#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>
#include <stdio.h>
#include <chrono>
#include <fstream>
#include <string>
#include <cstring>


#include "ddrbenchmark2.hpp"

#define BANDWIDTH 512
#define HOST_DATA_BITWIDTH 32
#define AP_UINT_FACTOR BANDWIDTH / HOST_DATA_BITWIDTH
#define RANGE_UPPER_BOUND 255
#define REPETITIONS 100
#define AVERAGE_REPS 100

void testCheck(TYPE *ref, TYPE *out,bool *result){
	
   for(int i=0;i<ARRAY_SIZE;i++){
		if(*(ref+i) != *(out+i))
			*result = false;
	}
	*result=true;
}



void execTest(TYPE * ref, TYPE * out){

   bool result=true;

   auto start = std::chrono::high_resolution_clock::now();



   ddrbenchmark2(ref, out);



   auto end = std::chrono::high_resolution_clock::now();

   double duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();


   //read back result
   testCheck(ref,out, &result);
   //printf("%d\n", result);
   std::cout << "result:" << result << std::endl;
   std::cout  << std::endl;
   std::cout << "time:" << duration << std::endl;

}

void execTestMultiple(TYPE * ref, TYPE * out){
  double tot_duration=0.0;
  double duration=0.0;
  double avg = 0.0;

  bool result=true;
  int rep=0;

  for (int i = 0; i < REPETITIONS;i++){

	  auto start = std::chrono::high_resolution_clock::now();

	  ddrbenchmark2(ref, out);

	  auto end = std::chrono::high_resolution_clock::now();

	  duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	  tot_duration += duration;

	  testCheck(ref,out,&result);

	  std::cout << "result: " << i << " :"<< result << std::endl;
	  std::cout  << std::endl;
	  std::cout << "time:" << duration << std::endl;
	  std::cout  <<"********************"<< std::endl;
	  rep++;
	  result = true;
  }
  std::cout << "average:" << tot_duration/rep << std::endl;
  rep=0;
}


void random_test(){
   std::cout << "************************" << std::endl;
   std::cout  << std::endl;
   std::cout << "Random input test" << std::endl;
   std::cout  << std::endl;
   std::cout << "************************" << std::endl;




   //int64_t array_dim = buffer_size * AP_UINT_FACTOR  //non mi interessa fare conversioni tanto sono interi 512!

   TYPE ref[ARRAY_SIZE];
   TYPE out[ARRAY_SIZE];


   int seed = 3456;


   std::default_random_engine rng(seed);
   std::uniform_int_distribution<int> rng_dist(0, RANGE_UPPER_BOUND);

   for(int i=0;i<ARRAY_SIZE;i++){
         ref[i]=static_cast<TYPE>(rng_dist(rng));
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
