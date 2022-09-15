PROG = main
CC = gcc
LIBS = -lcurl -ljson-c


${PROG}: ${PROG}.c data.c
	${CC} -o ${PROG} ${PROG}.c data.c ${LIBS}

clean: 
	rm ${PROG}