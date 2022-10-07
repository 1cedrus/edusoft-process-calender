PROG = epc
CC = gcc
LIBS = -lcurl -ljson-c


${PROG}: ${PROG}.c  ./data/data.c ./auth/auth.c 
	${CC} -o ${PROG} ${PROG}.c ./data/data.c ./auth/auth.c ${LIBS}

clean: 
	rm ${PROG}