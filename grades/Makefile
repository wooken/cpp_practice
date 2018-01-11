CC = g++
CXXFLAGS += -O0 -Wall -g
TARGETS = main
OBJS = main.o grade.o Student_info.o median.o analysis.o

run: main
	./main < db.txt

main: $(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS)

tags:
	ctags -R --c++-kinds=+p --fields=+iaS --extras=+q --language-force=C++ /usr/include/c++/7.2.1

clean:
	rm -f a.out *.o $(TARGETS)

.PHONY: clean run
