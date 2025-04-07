COMPILER=gcc

all: build run clean

build: main.c
	$(COMPILER) $< -o main

run: build
	./main

clean:
	rm -f main

.PHONY: all build run clean