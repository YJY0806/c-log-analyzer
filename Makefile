analyzer: main.o analyzer.o
	gcc main.o analyzer.o -o analyzer

main.o: main.c
	gcc -c main.c -o main.o

analyzer.o: analyzer.c
	gcc -c analyzer.c -o analyzer.o

clean:
	rm -f main.o analyzer.o analyzer