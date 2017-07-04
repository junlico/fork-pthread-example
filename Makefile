EXEC=test
CC=gcc

CC=g++
CFLAGS=-g -I.


%.o: %.cpp
	$(CC) -c $< $(CFLAGS)

${EXEC}: test.o
	g++ -o ${EXEC} test.o -I. -lpthread 



clean:
	rm -rf ./${EXEC}
	rm -rf ./*.o
