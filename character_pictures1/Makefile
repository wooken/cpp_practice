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

tags:
	ctags -R --c++-kinds=+p --fields=+iaS --extras=+q --language-force=C++ /usr/include/c++/7.2.1

clean:
	rm -f a.out *.o $(TARGETS)

.PHONY: clean run
