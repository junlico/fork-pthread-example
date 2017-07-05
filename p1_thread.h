#ifndef __P1_THREADS
#define __P1_THREADS
#include "p1_type.h"

bool custom_sort(const Student& s1, const Student& s2);
void* get_avg_wrapper(void* input);
void get_avg(int num_of_data, float* data);
#endif
