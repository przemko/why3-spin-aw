all: sat

sat.o: sat.c
	clang -c sat.c

sat: sat.o
	clang -o sat sat.o -lz3

clean:
	rm -f sat *.o *~
