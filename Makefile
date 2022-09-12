PROG = main
CC = gcc
LIBS = -lcurl 


${PROG}: ${PROG}.c	
	${CC} -o ${PROG} ${PROG}.c ${LIBS}

clean: 
	rm ${PROG}