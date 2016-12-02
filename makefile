udll.o: udll.c udll.h
        gcc -Wall -c udll.c -o udll.o
main.o: main.c
        gcc -Wall -c main.c -o main.o

universalDoubleLinkeList: main.o udll.o
        gcc -Wall -o universalDoubleLinkedList main.o udll.o