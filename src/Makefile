prefix=/usr/local
exec_prefix=${prefix}
libdir=${exec_prefix}/lib
includedir=${prefix}/include
CFLAGS=gtk4
LIBS=gtk4
CC=clang

CPPFLAGS = ${GTK_CFLAGS}
LDADD = ${GTK_LIBS}

window: window.o
	${CC} `pkg-config --cflags ${CFLAGS}` window.o -o window `pkg-config --libs ${LIBS}`

window.o: window.c
	${CC} `pkg-config --cflags ${CFLAGS}` -c window.c -o window.o `pkg-config --libs ${LIBS}`

clean: window window.o
	rm window window.o
