CC = g++
CXXFLAGS += -O2 -Wall -g
TARGETS = main

run: main
	./main

main: main.o
	$(CC) -o $@ $< $(CXXFLAGS)

clean:
	rm -f a.out $(TARGETS)

.PHONY: clean run
