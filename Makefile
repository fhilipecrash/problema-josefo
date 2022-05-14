all: josefo

josefo: josefo.c
	gcc -o josefo.o josefo.c

clean:
	rm -rf *.o *~