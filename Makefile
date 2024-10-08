CC = gcc
OPT = -O0
CFLAGS = -std=gnu99 -g -Wall -Wextra -pedantic $(OPT) -lm
#CFLAGS = -std=gnu99 -g -Wall -Wextra -pedantic $(OPT) -fsanitize=address -fno-omit-frame-pointer


INCLUDES= -I./include 

SRC_DIR := ./src
BUILD_DIR := ./build
BIN_DIR := ./bin

CFILES := $(shell find $(SRC_DIR) -name '*.c')
OBJECTS := $(CFILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
EXEC := ${BIN_DIR}/testplot

${EXEC}: ${OBJECTS} ${LIBHHL} 
	mkdir -p $(dir $@)
	$(CC) ${CFLAGS} ${INCLUDES} ${OBJECTS} -o $@ 

${BUILD_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) ${CFLAGS} ${INCLUDES} -c $< -o $@ 

clean:
	rm -rf ${BUILD_DIR} 
	rm -rf ${BIN_DIR} 

cleandb:
	rm -rf ./databases

run: ${EXEC}
	$^ 

debug: ${EXEC}
	cgdb --args $^ 
