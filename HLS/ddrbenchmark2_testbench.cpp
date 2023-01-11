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

void testCheck0(TYPE *ref, TYPE *out,bool *result){
	
   for(int i=0;i<ARRAY_SIZE;i++){
		if(*(ref+i) != *(out+i))
			*result = false;
	}
	*result=true;
}
//
//void testCheck1(TYPE *ref, TYPE *out,int* check,bool *result){
//   int goldenSum = 0;
//
//   for(int i=0;i<ARRAY_SIZE;i++){
//		goldenSum += (*(ref +i)).range(1,0);
//	}
//	*result=(goldenSum == *check);
//
//}

void testCheck2(TYPE *ref, TYPE *out,bool *result){

   for(int i=0;i<ARRAY_SIZE;i++){
		if(123 != *(out+i))
			*result = false;
	}
	*result=true;
}

void execTest(TYPE * ref, TYPE * out){

   bool resultb=true;
   bool resultr=true;
   bool resultw=true;


   auto start = std::chrono::high_resolution_clock::now();
   ddrbenchmark2(ref, out,0);
   auto end = std::chrono::high_resolution_clock::now();
   double durationb = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
   testCheck0(ref,out, &resultb);

   std::cout << "bandwdth result:" << resultb << std::endl;
   std::cout  << std::endl;
   std::cout << "time:" << durationb << std::endl;


   start = std::chrono::high_resolution_clock::now();
   ddrbenchmark2(ref, out,1);
   end = std::chrono::high_resolution_clock::now();
   double durationr = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
   //testCheck1(ref,out,check, &resultr);

   std::cout << "read result:" << resultr << std::endl;
   std::cout  << std::endl;
   std::cout << "time:" << durationr << std::endl;



   start = std::chrono::high_resolution_clock::now();
   ddrbenchmark2(ref, out,2);
   end = std::chrono::high_resolution_clock::now();
   double durationw = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
   testCheck2(ref,out, &resultw);

   std::cout << "write result:" << resultw << std::endl;
   std::cout  << std::endl;
   std::cout << "time:" << durationw << std::endl;



}

void execMultiTest(TYPE * ref, TYPE * out){
	double tot_duration=0.0;
	double avg = 0.0;
	int rep = 0;
	bool resultb=true;
	bool resultr=true;
	bool resultw=true;


	std::cout << "ciao guys" << std::endl;

	//simultaneous read and write

	for (int i = 0; i < REPETITIONS;i++){

		auto start = std::chrono::high_resolution_clock::now();
		ddrbenchmark2(ref, out,0);
		auto end = std::chrono::high_resolution_clock::now();
		double durationb = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		testCheck0(ref,out, &resultb);
		tot_duration += durationb;
		std::cout << "RW result: " << i << " :"<< resultb << std::endl;
		std::cout  << std::endl;
		std::cout << "RW time:" << durationb << std::endl;
		std::cout  <<"********************"<< std::endl;
		rep++;
		resultb = true;
	}
	std::cout << "simultaneous RW average:" << tot_duration/rep << std::endl;
	rep=0;
	tot_duration= 0.0;

	//write

	for (int i = 0; i < REPETITIONS;i++){

		auto start = std::chrono::high_resolution_clock::now();
		ddrbenchmark2(ref, out,1);
		auto end = std::chrono::high_resolution_clock::now();
		double durationr = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

		tot_duration += durationr;

		std::cout << "R result: " << i << " :"<< resultr << std::endl;
		std::cout  << std::endl;
		std::cout << "R time:" << durationr << std::endl;
		std::cout  <<"********************"<< std::endl;
		rep++;
		resultr = true;
	}
	std::cout << "R average:" << tot_duration/rep << std::endl;
	rep=0;
	tot_duration= 0.0;


	for (int i = 0; i < REPETITIONS;i++){

		auto start = std::chrono::high_resolution_clock::now();
		ddrbenchmark2(ref, out,2);
		auto end = std::chrono::high_resolution_clock::now();
		double durationw = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		testCheck2(ref,out, &resultw);
		tot_duration += durationw;

		std::cout << "W result: " << i << " :"<< resultw << std::endl;
		std::cout  << std::endl;
		std::cout << "W time:" << durationw << std::endl;
		std::cout  <<"********************"<< std::endl;
		rep++;
		resultw = true;
	}
	std::cout << "W average:" << tot_duration/rep << std::endl;






}

//void execTestMultiple(TYPE * ref, TYPE * out){
//  double tot_duration=0.0;
//  double duration=0.0;
//  double avg = 0.0;
//
//  bool result=true;
//  int rep=0;

//  for (int i = 0; i < REPETITIONS;i++){
//
//	  auto start = std::chrono::high_resolution_clock::now();
//
//	  ddrbenchmark2(ref, out);
//
//	  auto end = std::chrono::high_resolution_clock::now();
//
//	  duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
//	  tot_duration += duration;
//
//	  testCheck(ref,out,&result);
//
//	  std::cout << "result: " << i << " :"<< result << std::endl;
//	  std::cout  << std::endl;
//	  std::cout << "time:" << duration << std::endl;
//	  std::cout  <<"********************"<< std::endl;
//	  rep++;
//	  result = true;
//  }
//  std::cout << "average:" << tot_duration/rep << std::endl;
//  rep=0;
//}


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


   //execTest(ref,out);




   #ifdef AVERAGE_REPS
     execMultiTest(ref,out);
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
