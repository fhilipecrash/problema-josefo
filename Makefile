COMPILER=gcc

all: josefo.c
	$(COMPILER) $?

run:
	./a.out

clean:
	rm *.out