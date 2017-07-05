#include "p1_process.h"
#include "p1_thread.h"
#include "p1_type.h"
void get_statistics(std::string class_name[], int num_class, int num_process) {
	int base_size = num_class / num_process;
	int remainder = num_class % num_process;
	
	int cnt = 0;
	int size = 0;
	pid_t pid = 0;
	pid_t wid;
	int status = 0;
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
   		
   		pid = fork();
   		if (pid == 0) { break; } //break if child process.
   		filename.clear();
	}
	
	if (pid == 0) {
		printf("Child process is created. (pid: %d)\n", getpid());
		
		for (int i = 0; i < filename.size(); i++) {
							
			std::string in_file_name = "./input/" + filename[i] + ".csv";
			
			struct StudentData data = read_file(in_file_name);
			pthread_t t;
			
			pthread_create(&t, NULL, get_avg_wrapper, &data);
			
			pthread_join(t, NULL);
			
			std::string out_file_name = "./output/" + class_name[i] + "-stats.csv";
			
		}
		
		
		printf("Child process is terminated. (pid: %d)\n", getpid());		
		exit(0);
	}
	
	
	if (pid > 0) {
		wait(NULL);	
		printf("Parent process is terminated. (pid: %d)\n", getpid());
	}
		
		
}


struct StudentData read_file(std::string filename){	
	std::ifstream ifs;
	ifs.open(filename.c_str());
	if(!ifs.is_open()) {
		fprintf(stderr, "[ERROR] Can not open file.\n");
		exit(-1);
	}
	struct StudentData data;
	std::string line;
	std::getline(ifs, line);
	data.class_code = line;
	
	while (std::getline(ifs, line)) {
		std::string s;
		float g;
		std::istringstream iss(line);
		if (iss >> s >> g) {
			struct Student student;
			student.id = s;
			student.grade = g;
			data.students.push_back(student);
		}
	}
	
	std::sort(data.students.begin(), data.students.end(), custom_sort);
	return data;
}
