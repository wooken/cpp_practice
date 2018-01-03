CC = g++
CXXFLAGS += -O0 -Wall -g
TARGETS = main proto

run: main
	./main

main: main.o
	$(CC) -o $@ $< $(CXXFLAGS)

proto: proto.o
	$(CC) -o $@ $< $(CXXFLAGS)
	./proto

clean:
	rm -f a.out *.o $(TARGETS)

.PHONY: clean run
