EXEC=test
CC=g++
CFLAGS=-g -I.

%.o: %.cpp
	$(CC) -c $< $(CFLAGS)

${EXEC}: main.o p1_process.o p1_thread.o
	g++ -o ${EXEC} main.o p1_process.o p1_thread.o -I. -lpthread 

clean:
	rm -rf ./${EXEC}
	rm -rf ./*.o
