#ifndef __P1_TYPE_H
#define __P1_TYPE_H
#include <stdio.h>
#include <iostream>
#include <vector>
struct Student {
	std::string id;
	float grade;
};

struct StudentData {
	std::string class_code;
	float median;
	float avg;
	float std_dev;
	std::vector<Student> students;
};
#endif
