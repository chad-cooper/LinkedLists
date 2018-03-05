//
//  DoublyLinkedList.h
//  Project 1
//
//  Created by Kin Ng on 5/22/17.
//  Copyright © 2017 Kin Ng. All rights reserved.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "DoubleNode.h"
#include <stdexcept>
using namespace std;

template <typename Type>
class DoublyLinkedList {
private:
    
   	DoubleNode<Type> *header;     	//Head of the list
   	DoubleNode<Type> *trailer;    	//Tail of the list
   	int n;                               	//Holds the size of the number of elements in the list
    
public:
    
   	/*This constructor sets all member variables to 0 or nullptr,
     as appropriate.*/
   	DoublyLinkedList():
    header(nullptr),
    trailer(nullptr),
    n(0){
   	}
    
   	/*Destructor prototype.*/
   	~DoublyLinkedList();
    
   	/*Accessors prototypes*/
   	int size() const;
   	bool empty() const;
   	Type front() const;
   	Type back() const;
   	DoubleNode<Type>* head() const;
   	DoubleNode<Type>* tail() const;
   	int count(Type const &) const;
    
   	/*Mutators prototypes*/
   	void push_front(Type const &);
   	void push_back(Type const &);
   	Type pop_front();
   	Type pop_back();
   	int erase(Type const &);
    
   	void print();
    
};
#endif

/*Functions Implementation*/

/*Destrutor*/
template <typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList() {
   	while (!empty()) {
        pop_front();
   	}
   	delete header;
   	delete trailer;
}

/*Accessors*/

//Returns the number of items in the list.
template <typename Type>
int DoublyLinkedList<Type>::size() const {
   	return n;
}

//Returns true if the list is empty, false otherwise.
template <typename Type>
bool DoublyLinkedList<Type>::empty() const {
   	return n == 0;
}

/*Retrieves the object stored in the node pointed to
 by the head pointer. This function throws an under
 flow if the list is empty.*/
template <typename Type>
Type DoublyLinkedList<Type>::front() const {
    
   	if (!empty()) {
        return header->value;
   	}
   	else
        throw underflow_error("Empty List");
}

/*Retrieves the object stored in the node pointed to
 by the tail pointer. This function throws an under
 flow if the list is empty.*/
template <typename Type>
Type DoublyLinkedList<Type>::back() const {
   	if (!empty()) {
        return trailer->value;
   	}
   	else
        throw underflow_error("Empty List");
}

//Returns the head pointer.
template <typename Type>
DoubleNode<Type>* DoublyLinkedList<Type>::head() const {
   	return header;
}

//Returns the tail pointer.
template <typename Type>
DoubleNode<Type>* DoublyLinkedList<Type>::tail() const {
   	return trailer;
}

//Returns the number of nodes in the linked list storing a value equal to the argument.
template <typename Type>
int DoublyLinkedList<Type>::count(Type const &element) const {
   	int i = 0;
   	DoubleNode<Type>* temp = new DoubleNode<Type>;
    
   	temp = header;
    
   	while (temp != nullptr) {
        if (temp->value == element) {
            i++;
        }
        temp = temp->next;
   	}
    
   	return i;
}


/*Mutators*/

/*Creates a new DoubleNode< Type > storing the argument,
 the next pointer of which is set to the current head pointer.
 The head pointer is set to this new node. If the list was originally empty, the
 tail pointer is set to point to the new node.*/
template <typename Type>
void DoublyLinkedList<Type>::push_front(Type const& elem) {
    
   	DoubleNode<Type>* newNode = new DoubleNode<Type>;
   	newNode->value = elem;
   	
   	if (empty()) {
        trailer = newNode;
   	}
   	else {
        header->prev = newNode;
   	}
   	newNode->next = header;
   	header = newNode;
   	n++;
}

//Similar to push front, this places a new node at the back of the list.
template <typename Type>
void DoublyLinkedList<Type>::push_back(Type const& elem) {
    
   	DoubleNode<Type>* newNode = new DoubleNode<Type>;
   	newNode->value = elem;
   	
   	if (empty()) {
        header = newNode;
   	}
   	else {
        trailer->next = newNode;
   	}
   	newNode->prev = trailer;
   	trailer = newNode;
   	n++;
}

/*Delete the node at the front of the linked list and, as
 necessary, update the head and tail pointers. Return the object stored in the
 node being popped. Throw an underflow exception if the list is empty.*/
template <typename Type>
Type DoublyLinkedList<Type>::pop_front() {
    
   	if (!empty()) {
        
        Type val = header->value;
        DoubleNode<Type>* temp = new DoubleNode<Type>;
        
        temp = header;
        header = temp->next;
        
        if (header) {                        	//More than one node
            header->prev = nullptr;
        }
        else                                        	//One Node, so header and trailer point to null
            trailer = nullptr;
        
        
        delete temp;
        n--;
        
        return val;
   	}
   	else
        throw underflow_error("Empty List");
}

//Similar to pop front, this deletes the node at the back of the list and returns the object.
template <typename Type>
Type DoublyLinkedList<Type>::pop_back() {
   	if (!empty()) {
        Type val = trailer->value;
        DoubleNode<Type>* temp = new DoubleNode<Type>;
        
        temp = trailer;
        trailer = temp->prev;
        
        if (trailer) {                              	//More than one node
            trailer->next = nullptr;
        }
        else                                        	//One Node, so header and trailer point to null
            header = nullptr;
        
        delete temp;
        n--;
        
        return val;
   	}
   	else
        throw underflow_error("Empty List");
}

/*Delete the node(s) (from the front) in the
 linked list that contains the element equal to the argument.
 Return the number of nodes that were deleted.*/
template <typename Type>
int DoublyLinkedList<Type>::erase(Type const &number) {
   	
   	int counter = count(number);
    
   	DoubleNode<Type>* trackNode = header;
    
   	do {
        
        if (trackNode->value == number) {
            
            DoubleNode<Type>* deleteNode = trackNode;
            if (deleteNode == header) {                        	//If deleteNode is at the head.
                header = header->next;
            }
            else if(deleteNode == trailer) {            		//If deleteNode is at the tail.
                trailer = trailer->prev;
                trailer->next = nullptr;
            }
            else {                                                           	 //Else if deleteNode is at the middle.
                trackNode->next->prev = trackNode->prev;
                trackNode->prev->next = trackNode->next;
            }
            
            trackNode = trackNode->next;
            
            delete deleteNode;
            
            n--;
        }
        else {
            trackNode = trackNode->next;
        }
   	} while (trackNode != nullptr);
    
   	return counter;
   	
}

//Prints the values of the Doubly Linked List
template <typename Type>
void DoublyLinkedList<Type>::print() {

	if (!empty()) {
		DoubleNode<Type>* temp = header;
		cout << "List: ";
		while (temp != nullptr) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
	else {
		throw underflow_error("The list is empty.");
	}
	
}

