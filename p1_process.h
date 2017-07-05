#ifndef __P1_PROCESS
#define __P1_PROCESS

#include <stdio.h>
#include <stdlib.h>			//exit(),  sizeof()
#include <unistd.h>			//getpid()
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <sys/wait.h>		//wait()
#include <sys/types.h>
#include <pthread.h>
#include <algorithm>		//std::sort
#include <iomanip>			//std::setprecision
void get_statistics(std::string class_name[], int num_class, int num_process);

struct ClassData read_file(std::string filename);
void write_file(std::string filename, struct ClassData data);
#endif
