all: main

main: main.o ItemType.o SortedLinkedList.o
	g++ main.o ItemType.o SortedLinkedList.o -o main

main.o: main.cpp
	g++ -c main.cpp

ItemType.o: ItemType.cpp
	g++ -c ItemType.cpp

SortedLinkedList.o: SortedLinkedList.cpp
	g++ -c SortedLinkedList.cpp

clean:
	rm ItemType.o main.o SortedLinkedList.o main
