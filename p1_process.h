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
void get_statistics(std::string class_name[], int num_class, int num_process);

struct StudentData read_file(std::string filename);
#endif
