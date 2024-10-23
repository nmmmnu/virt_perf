MYCC = gcc

CC   = $(MYCC) -c -std=c++17 -Wall -Wextra -Wpedantic -Wdeprecated -Wconversion -O3
LINK = $(MYCC) -o $@ $^ -lstdc++

all: main

clean:
	rm -f *.o

reducer_more.o: reducer.h reducer_more.h reducer_more.cc
	$(CC) reducer_more.cc

map.o: reducer.h map.cc
	$(CC) map.cc

main.o: reducer.h reducer_more.h perf.h main.cc
	$(CC) main.cc

main: main.o reducer_more.o map.o
	$(LINK)


