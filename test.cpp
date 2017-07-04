#include <stdio.h>
#include <stdlib.h>			//atoi()
#include <iostream>
#include <vector>

//int[] splitIntoParts(int whole, int parts);
int main(int argc, char** argv) {
    
    std::string class_name[] = {"os", "architecture", "java", "algorithm", "digital-design"};
    int class_cnt = sizeof(class_name) / sizeof(class_name[0]);
    int num_process = (atoi(argv[1]) <= class_cnt) ? atoi(argv[1]) : class_cnt;
   	   	
   	int base_size = class_cnt / num_process;
   	
   	int remainder = class_cnt % num_process;
   	
    //printf("%d\n", num_process);
   	//printf("%d\n", remainder);
   	int cnt = 0;
   	int size = 0;
   	std::vector<std::string> filename;
   	for (int i = 0; i < num_process; i++) {
   		size = (remainder > 0) ? (base_size + 1) : base_size;
   		remainder--;
   		//printf("%d : %d\n", i, size);
   		for (int j = 0; j < size; j++) {
   			filename.push_back(class_name[cnt]);
   			cnt++;
   		}
   		/*
   		for (int k = 0; k < filename.size(); k++) {
   			std::cout << i << ": " << filename[k] << std::endl;
   		}
   		*/
   		filename.clear();
   	}
   
   
    
    
    
    
    
    
    
    
    
    
    
    /*
    std::vector<std::string> filename;
    int cnt = 0;
    pid_t pid = 0;
    for (int i = 0; i < num_process; i++) {
        for (int j = 0; j < size; j++) {
            filename.push_back(class_name[cnt]);
            cnt++;
            if (cnt >= file_cnt) { break; }
        }

        // pid = fork();
        // if (pid == 0) { break; }
        for (int k = 0; k < filename.size(); k++){
            std::cout << i << " : " << filename[k] << std::endl;
        }
        filename.clear();
    }
    */

}


