CC = g++
CXXFLAGS += -O0 -Wall -g
TARGETS = main
OBJS = main.o grade.o Student_info.o median.o

run: main
	./main < db.txt

main: $(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f a.out *.o $(TARGETS)

.PHONY: clean run
