TARGET=chip8
OBJ_TARGET=
CC=gcc
C_FLAGS=-Wall -Iheaders
L_FLAGS=-L/usr/local/lib -lSDL3
BUILD_DIR=build

SOURCE=src/*.c

MKDIR_P=mkdir -p

all: 
	${MKDIR_P} ${@D}/${BUILD_DIR}
	${CC} ${C_FLAGS} ${L_FLAGS} ${SOURCE} -o ${BUILD_DIR}/${TARGET}
obj: 
	${MKDIR_P} ${@D}/${BUILD_DIR}
	${CC} ${C_FLAGS} -c ${SOURCE} -o ${BUILD_DIR}/${TARGET}.o
clean:
	rm -rf ${@D}/${BUILD_DIR}/*.o ${@D}/${BUILD_DIR}/${TARGET}
