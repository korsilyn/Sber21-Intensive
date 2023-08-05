C=gcc
CFLAGS=-Wall -Werror -Wextra
BUILD_PATH=../build/

all: graph.o

graph.o: graph.c calculate.o draw.o dynamic.o parse.o
	$(C) $(CFLAGS) graph.c calculate.o draw.o dynamic.o parse.o -o $(BUILD_PATH)graph

calculate.o: calculate.c calculate.h
	$(C) $(CFLAGS) -c calculate.c

draw.o: draw.c draw.h
	$(C) $(CFLAGS) -c draw.c

dynamic.o: dynamic.c dynamic.h
	$(C) $(CFLAGS) -c dynamic.c

parse.o: parse.c parse.h
	$(C) $(CFLAGS) -c parse.c

rebuild: clean all

clean:
	rm -f *.o *.a *.gch *.so