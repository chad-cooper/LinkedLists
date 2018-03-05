//
//  DoubleNode.h
//  Project 1
//
//  Created by Kin Ng on 5/22/17.
//  Copyright © 2017 Kin Ng. All rights reserved.
//

#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <typename Type>
class DoubleNode
{
private:
    
   	Type value;                          	//To hold data of the node
   	DoubleNode<Type> *next;       	//pointer to next node
   	DoubleNode<Type> *prev;       	//pointer to previous node
    
public:
   	//Contructor Prototype.
   	DoubleNode(Type const&val = (int)NULL, DoubleNode* = nullptr, DoubleNode* = nullptr);
    
   	//Returns the element of the node.
   	Type getData() const {
        return value;
   	}
    
   	//Returns the next pointer.
   	DoubleNode* getNext() const {
        return next;
   	}
    
   	//Returns the previous pointer.
   	DoubleNode* getPrevious() const {
        return prev;
   	}
    
   	//Declare friend class.
   	template <typename T> friend class DoublyLinkedList;
    
};
#endif /* DoubleNode_h */

/*This constructor takes three arguments: a constant reference to an Type (by
 default, an integer) and two pointers to a DoubleNode (each by default nullptr).
 These are assigned to the member variables, respectively.*/
template <typename Type>
DoubleNode<Type>::DoubleNode(Type const&val, DoubleNode<Type>*ptrN, DoubleNode<Type>*ptrP) :
value(val),
next(ptrN),
prev(ptrP) {
}

