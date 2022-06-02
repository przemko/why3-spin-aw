all: sat

sat.o: sat.cpp
	clang++ -c sat.cpp

sat: sat.o
	clang++ -o sat sat.o -lz3

clean:
	rm -f sat *.o *~
