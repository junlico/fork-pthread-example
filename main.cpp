#include "p1_process.h"
int main(int argc, char** argv) {
	
	if (argc != 2) {
		fprintf(stderr, "[ERROR] Expecting 1 argument, but got (%d) \n", argc - 1);
		fprintf(stderr, "[USAGE] p1_exec <number of processes>\n");
		return -1;
	}

	std::cout << "Beginning of the main() 	(pid: " << getpid() << ")" << std::endl;
	std::string class_name[] = {"os", "architecture", "java", "algorithm", "digital-design"};
	int num_class = sizeof(class_name) / sizeof(class_name[0]);
	int num_process = (atoi(argv[1]) <= num_class) ? atoi(argv[1]) : num_class;
	
	// Call the process
	get_statistics(class_name, num_class, num_process);

	std::cout << "End of the main() 		(pid: " << getpid() << ")" << std::endl;
	return 0;
}
