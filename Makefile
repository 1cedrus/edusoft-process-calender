PROG = main
CC = gcc
LIBS = -lcurl -ljson-c


${PROG}: ${PROG}.c data.c parser.c
	${CC} -o ${PROG} ${PROG}.c data.c parser.c ${LIBS}

clean: 
	rm ${PROG}