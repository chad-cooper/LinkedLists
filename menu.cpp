// Kin Ng and Chad Cooper
// menu.cpp

#include <iostream>
#include "CyclicLinkedList.h"
#include "DoublyLinkedList.h"
using namespace std;
 
int main() {
    
    int code;
   	char letter;
   	CyclicLinkedList<double> list1;
   	DoublyLinkedList<double> list2;
    
   	cout << "Operation Code: \n";
   	cout << "1. Create list\n"
    "2. Count number of items\n"
    "3. Retrieve first item\n"
    "4. Retrieve last item\n"
    "5. Count instances of an item\n"
    "6. Push front\n"
    "7. Push back\n"
    "8. Pop front\n"
    "9. Pop back\n"
    "10. Delete instance(s) of an item\n"
    "11. Print list\n"
    "12. Exit\n";
    
    cout << "Enter s for Singly or d for Doubly: ";
   	cin >> letter;
    
   	switch (letter) {
            
        case 's':
            
            for (;;) {
                cout << "Enter operation code: ";
                cin >> code;
                
                switch (code) {
                        
                    case 1:
                       	cout << "List was succesfully created." << endl;
                       	break;
                    case 2:
                       	cout << "Number of items in the list: " << list1.size() << endl;
                       	break;
                    case 3:
                       	try {
                            cout << "Front of the list: " << list1.front() << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    case 4:
                       	try {
                            cout << "Back of the list: " << list1.back() << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    case 5:
                       	int value;
                       	cout << "Enter a value: ";
                       	cin >> value;
                       	cout << "The number of times " << value <<
                        " appears in the list is: " << list1.count(value) << endl;
                       	break;
                    case 6:
                       	double num1;
                       	cout << "Enter the value to push front: ";
                       	cin >> num1;
                       	list1.push_front(num1);
                       	break;
                    case 7:
                       	double num2;
                       	cout << "Enter the value to push back: ";
                       	cin >> num2;
                       	list1.push_back(num2);
                       	break;
                    case 8:
                       	try {
                            cout << list1.pop_front() << " was eliminated from the list." << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    case 9:
                       	try {
                            cout << list1.pop_back() << " was eliminated from the list." << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    case 10:
                       	double num3;
                       	cout << "Enter the value to erase from the list: ";
                       	cin >> num3;
                       	cout << list1.erase(num3) << " occurrences of " << num3
                        << " were eliminated." << endl;
                       	break;
                    case 11:
                        try {
                       	list1.print();
                        }
                        catch (const exception& e) {
                            cout << e.what();
                        }
                       	break;
                    case 12:
                       	cout << "Exit succesful." << endl;
                       	return 0;
                    default: cout << "Invalid code." << endl;
                }
                cout << endl;
            }
            break;
            
        case 'd':
            
            for (;;) {
                cout << "Enter operation code: ";
                cin >> code;
                
                switch (code) {
                        
                    case 1:
                       	cout << "List was succesfully created." << endl;
                       	break;
                    case 2:
                       	cout << "Number of items in the list: " << list2.size() << endl;
                       	break;
                    case 3:
                       	try {
                            cout << "Front of the list: " << list2.front() << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    case 4:
                       	try {
                            cout << "Back of the list: " << list2.back() << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    case 5:
                       	int value;
                       	cout << "Enter a value: ";
                       	cin >> value;
                       	cout << "The number of times " << value <<
                        " appears in the list is: " << list2.count(value) << endl;
                       	break;
                    case 6:
                       	double num1;
                       	cout << "Enter the value to push front: ";
                       	cin >> num1;
                       	list2.push_front(num1);
                       	break;
                    case 7:
                       	double num2;
                       	cout << "Enter the value to push back: ";
                       	cin >> num2;
                       	list2.push_back(num2);
                       	break;
                    case 8:
                       	try {
                            cout << list2.pop_front() << " was eliminated from the list." << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    case 9:
                       	try {
                            cout << list2.pop_back() << " was eliminated from the list." << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    case 10:
                       	double num3;
                       	cout << "Enter the value to erase from the list: ";
                       	cin >> num3;
                       	cout << list2.erase(num3) << " occurrences of " << num3
                        << " were eliminated." << endl;
                       	break;
                    case 11:
                    	try {
                       	list2.print();
                        }
                        catch (const exception& e) {
                            cout << e.what();
                        }
                       	break;
                    case 12:
                       	cout << "Exit succesful." << endl;
                       	return 0;
                    default: cout << "Invalid code." << endl;
                }
                cout << endl;
            }
            break;
        default: cout << "Invalid code." << endl;
            
   	}
    
   	return 0;
    
};
