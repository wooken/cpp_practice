CC = g++
CXXFLAGS += -O0 -Wall -g
TARGETS = main

run: main
	./main < grammar.txt

main: main.o
	$(CC) -o $@ $< $(CXXFLAGS)

clean:
	rm -f a.out *.o $(TARGETS)

.PHONY: clean run
