#include "p1_thread.h"
#include "p1_process.h"

bool custom_sort(const Student& s1, const Student& s2) {
	return s1.grade > s2.grade;
}


void* get_median_wrapper(void* input) {
	struct ClassData* data = (struct ClassData*) input;
	get_median(data->median, data->students);
}

void* get_avg_wrapper(void* input) {
	struct ClassData* data = (struct ClassData*) input;
	data->avg = get_avg(data);
}

void* get_std_dev_wrapper(void* input) {
	struct ClassData* data = (struct ClassData*) input;
	data->std_dev = get_std_dev(data);
}


void get_median(float& median, std::vector<Student> students) {
	int size = students.size();
	if (size % 2 == 0) {
		median = (students[size / 2 - 1].grade + students[size / 2].grade) / 2;
	} else {
		median = students[size / 2].grade;
	}
}


float get_avg(struct ClassData* data) {
	if (data->students.size() == 0) {
		return 0;
	} else {
		float total = 0;
		std::vector<Student>::iterator it;
		for (it = data->students.begin(); it != data->students.end(); it++) {
			total += it->grade;			
		}
		float avg = total / data->students.size();
		return avg;
	}
}

float get_std_dev(struct ClassData* data) {
	float avg = get_avg(data);
	float temp = 0;
	int size = data->students.size();
	for (int i = 0; i < size; i++) {
		temp += pow((data->students[i].grade - avg), 2);
	}
	float std_dev = sqrt(temp / size);
	return std_dev;
}

