#include "p1_thread.h"
#include "p1_process.h"

bool custom_sort(const Student& s1, const Student& s2) {
	return s1.grade > s2.grade;
}
void* get_avg_wrapper(void* input) {
	struct StudentData* data = (struct StudentData*) input;
}

void get_avg(int num_of_data, float* data) {
}
