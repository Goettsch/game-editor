CFLAGS=`pkg-config libgvc --cflags` -Wall -g -O2
LDFLAGS=-Wl,--rpath -Wl,`pkg-config libgvc --variable=libdir` `pkg-config libgvc --libs`

all: dot demo simple example

dot: dot.o
demo: demo.o
simple: simple.o
example: example.o

clean:
	rm -rf *.o dot demo simple example *.png
