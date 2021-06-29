# hello

# CXX = clang++ \
CXX_FLAGS = -Wall -g \
\
HEADERS = ncurses.h \
CPP_FILES = snake.cpp \
OBJ_FILES = $(CPP_FILES:.cpp=.o) \
\
${OBJ_FILES}: ${CPP_FILES} \
	${CXX} ${CXX_FLAGS} -c -o ${CPP_FILES} ${OBJ_FILES} \
\
${TARGET}: ${OBJ_FILES} \
	${CXX} ${CXX_FLAGS} ${OBJ_FILES} \
\
run: ${TARGET} \
	./${TARGET} \
\
clean: ${TARGET} ${OBJ_FILES} \
	rm ${TARGET} ${OBJ_FILES} \  

#usage \
make run \
make clean \

# the code above didn't work for some reason

CC =  clang++
CFLAGS =  -Wall -g -lncurses

all:  compile 

compile:  main.cpp
	$(CC) $(CFLAGS) main.cpp -o main

run:  
	./result.out

