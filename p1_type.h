#ifndef __P1_TYPE_H
#define __P1_TYPE_H
#include <stdio.h>
struct Student {
	std::string id;
	float grade;
};

struct StudentData {
	int size;
	float median;
	float avg;
	float std_dev;
	struct Student* students;
};
#endif
