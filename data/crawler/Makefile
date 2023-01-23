PROG = crawlData
CC = gcc
LIBS = -lcurl -ljson-c


${PROG}: ${PROG}.c  ../data.c ../../auth/auth.c
	${CC} -o ${PROG} ${PROG}.c ../data.c ../../auth/auth.c ${LIBS}

clean: 
	rm ${PROG}
