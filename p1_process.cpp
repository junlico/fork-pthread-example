#include "p1_process.h"
#include "p1_thread.h"
#include "p1_type.h"
void get_statistics(std::string class_name[], int num_class, int num_process) {
	int base_size = num_class / num_process;
	int remainder = num_class % num_process;
	
	int cnt = 0;
	int size = 0;
	
	std::vector<std::string> filename;
	
	for (int i = 0; i < num_process; i++) {
		// determin number of files that each process handles 
		size = (remainder > 0) ? (base_size + 1) : base_size;
		remainder -= (remainder > 0) ? 1 : 0;
		
		for (int j = 0; j < size; j++) {
			filename.push_back(class_name[cnt++]);
		}
		/*
		for (int k = 0; k < filename.size(); k++) {
   			std::cout << i << ": " << filename[k] << std::endl;
   		}
   		*/
   		
   		
   		filename.clear();
	}
}
