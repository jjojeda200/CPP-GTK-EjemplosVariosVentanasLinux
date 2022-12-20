# Comentarios
PROG   = 00IntroGTK
PROG1  = GTK-Practica01
CC     = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS   = `pkg-config --libs gtk+-3.0`

${PROG}: ${PROG}.cpp
	${CC} ${CFLAGS} -o ${PROG} ${PROG}.cpp ${LIBS}

pro1:
	${CC} ${CFLAGS} -o ${PROG1} ${PROG1}.cpp ${LIBS}

clean:
	rm ${PROG}
	rm ${PROG1}
