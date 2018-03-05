list: menu.o 
	g++ -o list menu.o

menu.o: menu.cpp DoublyLinkedList.h CyclicLinkedList.h DoubleNode.h SingleNode.h
	g++ -c -std=c++11 menu.cpp