//
//  CyclicLinkedList.h
//  Project 1
//
//  Created by Chad Cooper on 5/22/17.
//  Copyright © 2017 Chad Cooper. All rights reserved.
//

#ifndef CyclicLinkedList_h
#define CyclicLinkedList_h

#include "SingleNode.h"
#include <stdexcept>
using namespace std;

template <typename Type>
class CyclicLinkedList {
private:
    
    SingleNode<Type>* mHead;
    SingleNode<Type>* mTail;
    int mSize;
    
public:
    // Sets all member variables to 0 or nullptr, as appropriate.
    CyclicLinkedList(){
        mHead = nullptr;
        mTail = nullptr;
        mSize = 0;
    }
    
    
    
    
    
     //Deletes each of the nodes in the linked list.
    ~CyclicLinkedList(){
        
        while(!empty()) {
            pop_front();
        }
        
        delete mHead;
        delete mTail;
        
    }
    
    
    
    
    
    // Returns the number of items in the list.
    int size() const {
        return mSize;
    }
    
    
    
    
    
    // Returns true if the list is empty, false otherwise.
    bool empty() const{
        return mHead == nullptr;
    }
    
    
    
    
    
    // Retrieves the object stored in the node pointed to by the head pointer. This function throws an underflow if the list is empty.
    Type front() const throw (underflow_error){
        if(!empty()){
           return mHead->data;
        } else {
            throw underflow_error("The list is empty.");
        }
    }
    
    
    
    
    
    // Retrieves the object stored in the node pointed to by the tail pointer. This function throws an underflow if the list is empty.
    Type back() const throw (underflow_error){
        if (!empty()){
            return mTail->data;
        } else {
            throw underflow_error("The list is empty.");
        }
    }
    
    
    
    
    
    // Returns the head pointer.
    SingleNode<Type> *head() const{
        return mHead;
    }
    
    
    
    
    
    // Returns the tail pointer.
    SingleNode< Type > *tail() const{
        return mTail;
    }
    
    
    
    
    
    // Returns the number of nodes in the linked list that are storing a value equal to the argument.
    int count( Type const & target) const{
        
        int targetCounter = 0;
    
        SingleNode<Type> * cursor = mHead; // cursor starts at the head of the list
        
        for (int loopCount = 0; loopCount < mSize; cursor = cursor->next, loopCount++){
            if(cursor->data == target)
                targetCounter++;
        }
        
        return targetCounter;
    }
    
    
    
    
    
    /* Creates a new SingleNode<Type> storing the argument, the next pointer of which is set to the current head pointer.
     The head pointer is set to this new node. 
     If the list was originally empty, the tail pointer is set to point to the new node. */
    void push_front(Type const & nodeData){
        
        
        // creates a new node that stores the argument as data and next points to the current head
        SingleNode<Type>* newNode = NULL;
        newNode = new SingleNode<Type>(nodeData, mHead);
        
        mHead = newNode;
    
        if(mTail == nullptr) {
            mTail = newNode;
        }
        
        mTail->next = newNode;
        
        // increases the size of the list by 1 everytime a new node is created.
        mSize++;
    }
    
    
    
    
    
    //Similar to push front, this places a new node at the back of the list.
    void push_back( Type const & nodeData ){
        
        
        // Creates a new node and sets it to point to the current head
        SingleNode<Type>* newNode = NULL;
        newNode = new SingleNode<Type>(nodeData, mHead);
    
        
        if(mHead == nullptr){
            mHead = newNode;
        }
        
        
        if(mTail == nullptr){
            mTail = newNode;
        } else {
            mTail->next = newNode;
            mTail = newNode;
        }
        
        
        mSize++;
    }
    
    
    
    
    
    /* Delete the node at the front of the linked list and, as
     necessary, update the head and tail pointers. Return the object stored in the
     node being popped. Throw an underflow exception if the list is empty. */
    Type pop_front() throw (underflow_error){
        if(!empty()){
            
            mSize--;
            
            Type poppedData;
            
            
            SingleNode<Type> * oldHead = mHead;
            
            poppedData = oldHead->data;
            
            mHead = oldHead->next;
            
            // If the size of the list becomes 0, then it is empty and the head and tail are set to NULL.
            if (mSize == 0){
                mHead = nullptr;
                mTail = nullptr;
            } else {
            mTail->next = mHead;
            }
            
            delete oldHead;
            
            return poppedData;
            
        } else {
            throw underflow_error("The list is empty.");
        }
    }
    
    /* Similar to pop front, this deletes the node at the back of the list and returns the object.*/
    Type pop_back() throw (underflow_error){
        if (!empty()){
            
            mSize--;
            
            Type poppedData;
            
            SingleNode<Type> * oldTail = mTail;
            
            poppedData = oldTail->data;
            
            SingleNode<Type> * cursor = mHead;
            
            for (int i = 1; i < mSize; i++){
                cursor = cursor->next;
            }
            
            cursor->next = oldTail->next;
            
            mTail = cursor;
            
            if (mSize == 0){
                mHead = nullptr;
                mTail = nullptr;
            }
            
            delete oldTail;
            
            return poppedData;
        } else {
            throw underflow_error("The list is empty.");
        }
    }
    
    
    
    
    /* Delete the node(s) (from the front) in the
     linked list that contains the element equal to the argument. As necessary, update the head and
     tail pointers and the next pointer of any other node within the list. Return the
     number of nodes that were deleted.*/
    int erase( Type const & target){
        
        // Holds the number of nodes to be deleted.
        int numberDeleted = count(target);
        
        // Used to check if all instances of target have been deleted.
        int finalSize = (mSize - numberDeleted);
        
        // These pointers keep track of, and traverse through the nodes
        SingleNode<Type> *cursor = mHead;
        SingleNode<Type> *cursorPrevious = mTail;
        
        while (mSize > finalSize) {
            
            if (cursor->data == target){
                
                SingleNode<Type> * willDelete = cursor;
                
                if (willDelete == mHead) {
                    pop_front();
                    
                    // pop_front() deallocates memory of head pointer
                    willDelete = nullptr;
                    cursor = cursor->next;
                    
                } else if (willDelete == mTail) {
                    pop_back();
                    
                    // pop_back() deallocates memory of tail pointer.
                    willDelete = nullptr;
                    
                } else {
                    cursor = cursor->next;
                    cursorPrevious->next = cursor;
                    
                    delete willDelete;
                    
                    mSize--;
                }
            } else {
                cursorPrevious = cursor;
                cursor = cursor->next;
            }
            
        }
        
        return numberDeleted;
    }
    
    
    
    
    // This method steps through the list and prints the items in order from head to tail.
    void print() const throw (underflow_error){
        
        SingleNode<Type> * cursor = mHead;
        if(!empty()){
            
            cout << "List: ";
            
            for (int loopCount = 0; loopCount < mSize; cursor = cursor->next, loopCount++){
                cout << cursor->data << " ";
            }
            
            cout << endl;
        } else {
            throw underflow_error("The list is empty.");
        }
    }
    
    
    
};
#endif /* CyclicLinkedList_h */
