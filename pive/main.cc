#include <iostream>
#include <fstream> 
#include <cmath>
#include <cstdio> 
#include <cstdlib> 
#include <ctime>   
#include <string>
#include <new>
#include <algorithm>
#include <cassert>
#include <omp.h>
using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 3) {
    printf("Usage: main.out <thread_count> <input_size> \n");
    exit(1);
  }
  int thread_count = atoi(argv[1]);
  assert(thread_count > 0);
  long input_size = atol(argv[2]);
  assert(input_size > 0);
  omp_set_num_threads(thread_count);
  double radius = 1;
  double side = radius*2;
  unsigned count = 0;
  long satisfied_sample = 0;
  double time1 = omp_get_wtime();
#pragma omp parallel shared(thread_count, side, input_size) private(count) reduction(+:satisfied_sample)
  {
    int granted_thread_count=omp_get_num_threads();
    assert(thread_count==granted_thread_count);
    unsigned rank = omp_get_thread_num();
#pragma omp for schedule (static)
    for(count = 0; count < input_size; count++)
      {
	double x1
	  =static_cast<double>(rand_r(&rank))/static_cast<double>(RAND_MAX)*side;
	double y1
	  =static_cast<double>(rand_r(&rank))/static_cast<double>(RAND_MAX)*side;
	// printf ("cordinates = (%f, %f) \n", x1, y1);
	if (pow(x1-1,2)+pow(y1-1,2)<1)
	  {
	    satisfied_sample += 1;
	  }
      }
#pragma omp single
    {
    }
  }
      double pi = static_cast<double>(satisfied_sample)/input_size*4;
      pi = static_cast<double>(satisfied_sample)/input_size*4;
      double time2 = omp_get_wtime();
      double time = time2-time1;
      printf("%16d,%16ld,%16f,%16f \n", thread_count, input_size, time, pi);
  return 0;
}
