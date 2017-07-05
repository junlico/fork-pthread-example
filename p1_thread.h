#ifndef __P1_THREADS
#define __P1_THREADS
#include "p1_type.h"
#include <math.h>
bool custom_sort(const Student& s1, const Student& s2);

void* get_median_wrapper(void* input);
void* get_avg_wrapper(void* input);
void* get_std_dev_wrapper(void* input);


void get_median(float& median, std::vector<Student> students);
float get_avg(struct ClassData* data);
float get_std_dev(struct ClassData* data);
#endif
