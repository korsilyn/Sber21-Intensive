C=gcc
CFLAGS=-Wall -Wextra -Werror

all: quest3 build_with_static build_with_dynamic

quest3: data_io.o data_process.o data_stat.o decision.o
	$(C) main_executable_module.c data_io.o data_process.o decision.o data_stat.o -o ../../build/Quest_3

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	$(C) $(CFLAGS) -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	$(C) $(CFLAGS) -c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c ../data_module/data_process.h
	$(C) $(CFLAGS) -c ../data_module/data_process.c

decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h
	$(C) $(CFLAGS) -c ../yet_another_decision_module/decision.c

# Quest 5
build_with_static: data_io.o data_process.o data_stat.a decision.o
	$(C) $(CFLAGS) -o ../../build/Quest_5 main_executable_module.c data_io.o data_process.o decision.o -L. data_stat.a

data_stat.a: data_stat.o
	ar rcs data_stat.a data_stat.o

# Quest 6
build_with_dynamic: data_io.o data_process.so decision.o
	$(C) main_executable_module.c data_io.o decision.o -o ../../build/Quest_6 -L. data_process.so

data_process.so: data_process.o data_stat.o
	$(C) $(CFLAGS) -o data_process.so data_process.o data_stat.o -shared

rebuild: clean all

clean:
	rm -f *.o *.a *.gch *.so