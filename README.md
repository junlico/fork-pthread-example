# fork-pthread-example
1. ./input/: This directory includes csv files for input data
2. ./output/: This directory is for output data
3. Makefile: This is a compilation script
4. README.md: ReadMe 
5. main.cpp: This is a top file for this project
6. p1_process.cpp: This is a file to handle processes
7. p1_process.h: This is a header file to handle processes
8. p1_thread.cpp: This is a file to handle threads
9. p1_thread.h: This is a header file to handle threads
10. p1_type.h: This is a header file to handle data struct


Use 1 input argument: the number of processes.
Print error message and usage example if you didn’t provide those arguments. This is an example for the error message.
```
[ERROR] Expecting 1 argument, but got (X).
[USAGE] p1_exec <number of processes>
```
Besides, 1 argument for the executable, some additional descriptions for program are as follows:
* For each input file, you need to generate: Average, Median, Standard Deviation, Top 3 students,
Middle 3 students, and Lowest 3 students. Calculate the result rounded up to the three digits after
the decimal point.
* Each input file has the following data: 1 line for class code (6 digits) and the rest of the lines for student id (10 digits) and grade.
* Program needs to create multiple processes to handle multiple files in parallel. Each child
process handles at least one file. In other words, one child process may handle multiple files.
* Only child process should create multiple threads to perform the calculation. So, process hierarchy
will be the following: Main process -> Child processes -> Threads
* You must not waste any resource, thus you should not create any non-working process or thread.
* The result needs to be saved to output directory with the following filename: <input
filename>-stats.csv (i.e. os-stats.csv).
* When a process is created, and terminated, you have to print the message with process id to indicate the process is created/terminated (you don’t need to do this for threads).
* Main process must complete its behavior after its child processes

Example command line output is as follows:
```
./p1_exec 2
Main process is created. (pid: 8456)
Child process is created. (pid: 8457)
Child process is created. (pid: 8458)
...
Child process is terminated. (pid: 8457)
Child process is terminated. (pid: 8458)
Main process is created. (pid: 8456)
```

Example output file should look like as given below:
```
Class code: 199405
Average: XX.XXX
Median: XX.XXX
Std. Dev: XX.XXX

Top 3 students:
Rank Student id Grade
XX XXXXXXXXXX XX.XXX
XX XXXXXXXXXX XX.XXX
XX XXXXXXXXXX XX.XXX

Middle 3 students:
Rank Student id Grade
XX XXXXXXXXXX XX.XXX
XX XXXXXXXXXX XX.XXX
XX XXXXXXXXXX XX.XXX

Lowest 3 students:
Rank Student id Grade
XX XXXXXXXXXX XX.XXX
XX XXXXXXXXXX XX.XXX
XX XXXXXXXXXX XX.XXX
```
