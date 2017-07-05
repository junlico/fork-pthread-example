#include "p1_process.h"
#include "p1_thread.h"
#include "p1_type.h"
void get_statistics(std::string class_name[], int num_class, int num_process) {
	int base_size = num_class / num_process;
	int remainder = num_class % num_process;
	
	int cnt = 0;
	int size = 0;
	pid_t pid, wpid;
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
			//std::cout << in_file_name << std::endl;
			struct ClassData data = read_file(in_file_name);
			pthread_t threads[3];
			
			pthread_create(&threads[0], NULL, get_avg_wrapper, &data);
			pthread_create(&threads[1], NULL, get_median_wrapper, &data);
			pthread_create(&threads[2], NULL, get_std_dev_wrapper, &data);
			
			for (int j = 0; j < 3; j++) {
				if(pthread_join(threads[j], NULL)) {
					fprintf(stderr, "Error joining thread\n");	
				}
			}
			
			std::string out_file_name = "./output/" + filename[i] + "-stats.csv";
			//std::cout << out_file_name << std::endl;
			write_file(out_file_name, data);
		}
		
		
		printf("Child process is terminated. (pid: %d)\n", getpid());		
		exit(0);
	}
	
	while ((wpid = wait(&status)) > 0);
	printf("Parent process is terminated. (pid: %d)\n", getpid());
		
		
}


struct ClassData read_file(std::string filename){	
	std::ifstream ifs;
	ifs.open(filename.c_str());
	if(!ifs.is_open()) {
		fprintf(stderr, "[ERROR] Can not open file.\n");
		exit(-1);
	}
	struct ClassData data;
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
	ifs.close();
	return data;
}

void write_file(std::string filename, ClassData data) {
	std::ofstream ofs;
	ofs.open(filename.c_str());
	if(!ofs.is_open()) {
		fprintf(stderr, "[ERROR] Can not create file.\n");
		exit(-1);
	}
	int size = data.students.size();
	ofs << data.class_code + "\n" << std::endl;
	ofs << std::fixed;
	ofs << std::setprecision(3);
	ofs << "Average: " << data.avg << std::endl;
	ofs << "Median: " << data.median << std::endl;
	ofs << "Std. Dev : " << data.std_dev << std::endl;
	
	ofs << "\nTop 3 students:" << std::endl;
	ofs << "Rank			Student id			Grade" << std::endl;
	for (int i = 0; i < 3; i++) {
		ofs << i + 1 << "				" << data.students[i].id <<  	"			" << data.students[i].grade << std::endl;
	}

	ofs << "\nMiddle 3 students:" << std::endl;
	ofs << "Rank			Student id			Grade" << std::endl;
	for (int i = size / 2 - 2; i < size / 2 + 1; i++) {
		ofs << i + 1 << "			" << data.students[i].id <<  	"			" << data.students[i].grade << std::endl;
	}

	ofs << "\nLowest 3 students:" << std::endl;
	ofs << "Rank			Student id			Grade" << std::endl;
	for (int i = size - 3; i < size; i++) {
		ofs << i + 1 << "			" << data.students[i].id <<  	"			" << data.students[i].grade << std::endl;
	}
	ofs.close();	
}
