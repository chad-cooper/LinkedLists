//
//  SingleNode.h
//  Project 1
//
//  Created by Chad Cooper on 5/22/17.
//  Copyright © 2017 Chad Cooper. All rights reserved.
//

#ifndef SingleNode_h
#define SingleNode_h

template <typename Type>
class SingleNode {
    
private:

    Type data;
    SingleNode<Type>* next;

public:
    
    /* This constructor takes two arguments: a constant reference to a Type (by de-
     fault, an integer) and a pointer to a SingleNode (by default nullptr). These are
     assigned to the member variables, respectively. */
    SingleNode(Type const &nodeData = (int)NULL, SingleNode *nextPointer = nullptr){
        data = nodeData;
        next = nextPointer;
    }
    
    // Returns the data element of the node.
    Type getData() const{
        return data;
    }
    
    // Returns the next pointer.
    SingleNode* getNext() const{
        return next;
    }
    
    template <typename T> friend class CyclicLinkedList;
    
};



#endif /* SingleNode_h */
