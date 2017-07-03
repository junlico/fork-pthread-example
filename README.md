# fork-pthread-example
1. ./data/: This directory includes csv files for input data
2. ./output/: This directory is for output data
3. main.cpp: This is a top file for this project
4. p1_process.h: This is a header file to handle processes
5. p1_process.cpp: This is a file to handle processes
6. p1_threads.h: This is a header file to handle threads
7. p1_threads.cpp: This is a file to handle threads
8. Makefile: This is a compilation script

Use 2 input arguments: the number of processes and the number of threads.
Print error message and usage example if you didn’t provide those arguments. This is an example for the error message.
```
[ERROR] Expecting 2 argument, but got (X).
[USAGE] a1_exec <number of processes> <number of threads>
```
Besides, 2 arguments for the executable, some additional descriptions for program are as follows:
* For each input file, you need to generate: Average, Median, Standard Deviation, Top 3 students,
Middle 3 students, and Lowest 3 students. Calculate the result rounded up to the three digits after
the decimal point.
* Each input file has the following data: 1 line for class code (6 digits) and the rest of the lines for
student id (10 digits) and grade.
* Your program needs to create multiple processes to handle multiple files in parallel. Each child
process handles at least one file. In other words, one child process may handle multiple files.
* Only child process should create multiple threads to perform the calculation. So, process hierarchy
will be the following: Main process -> Child processes -> Threads
* You must not waste any resource, thus you should not create any non-working process or thread.
* The result needs to be saved to output directory with the following filename: <input
filename>-stats.csv (i.e. os-stats.csv).
* When a process is created, and terminated, you have to print the message with process id to indicate
the process is created/terminated (you don’t need to do this for threads).
* Main process must complete its behavior after its child processes

Example command line output is as follows:
```
./p1_exec 2 4
Main process is created. (pid: 8456)
Child process has been created. (pid: 3992)
Child process is created. (pid: 4692)
...
Child process is terminated. (pid: 3992)
Child process is terminated. (pid: 4692)
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
