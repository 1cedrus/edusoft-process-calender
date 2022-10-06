PROG = main
CC = gcc
LIBS = -lcurl -ljson-c


${PROG}: ${PROG}.c data.c auth.c calendar.c
	${CC} -o ${PROG} ${PROG}.c data.c auth.c calendar.c ${LIBS}

clean: 
	rm ${PROG}