#include <iostream>
#include "linked_list.h"
using namespace std;
/**
 *
 * Test wrapper methods to print some useful information 
 * on performing operations on the linked list
 */

/**
 *
 *  Singly linked list operations
 */
void remove(SinglyLinkedList &sl, int value) {
	if (sl.remove(value)) {
		cout << value << " is removed successfully." << endl;
	} else {
		cout << value << " is not there." << endl;
	}
	sl.print();
}

void find(SinglyLinkedList &sl, int value) {
	if (sl.find(value)) {
		cout << value << " is found" << endl;
	} else {
		cout << value << " is not found" << endl;
	}
}

void insert(SinglyLinkedList &sl, int index, int value) {
	cout << "Inserting " << value << ", at index: " << index << endl;
	sl.insert(index, value);
	sl.print();
}

/**
 *
 * Doubly linked list operations
 */
void remove(DoublyLinkedList &dl, int value) {
	if (dl.remove(value)) {
		cout << value << " is removed successfully." << endl;
	} else {
		cout << value << " is not there." << endl;
	}
	dl.print();
}

void find(DoublyLinkedList &dl, int value) {
	if (dl.find(value)) {
		cout << value << " is found" << endl;
	} else {
		cout << value << " is not found" << endl;
	}
}

void insert(DoublyLinkedList &dl, int index, int value) {
	cout << "Inserting " << value << ", at index: " << index << endl;
	dl.insert(index, value);
	dl.print();
}


/**
 *
 * Invoking operations
 */
void processSinglyLinkedList() {
	cout << "Demo on SinglyLinkedList" << endl;
	cout << "######################################################################" << endl;
	SinglyLinkedList sl;
	for (int i = 1; i <= 10; i++) {
		sl.append(i);
	}
	sl.print();

	// Finding, inserting and removing elements in arbitarary order
	cout << "Initial size of the list is: " << sl.size() << endl;
	find(sl, 7);
	remove(sl, 5);
	remove(sl, 11);
	insert(sl, 3, 15);
	remove(sl, 9);
	find(sl, 5);
	find(sl, 6);
	insert(sl, 0, 100);
	remove(sl, 1);
	remove(sl, 4);
	insert(sl, 8, 1);
	remove(sl, 2);
	find(sl, 3);
	find(sl, 10);
	cout << "Final size of the list is: " << sl.size() << endl;
}

void processDoublyLinkedList() {
	cout << "Demo on DoublyLinkedList" << endl;
	cout << "######################################################################" << endl;
	DoublyLinkedList dl;
	for (int i = 1; i <= 10; i++) {
		dl.append(i);
	}
	dl.print();

	// Finding, inserting and removing elements in arbitarary order
	cout << "Initial size of the list is: " << dl.size() << endl;
	find(dl, 7);
	remove(dl, 5);
	remove(dl, 11);
	insert(dl, 3, 15);
	remove(dl, 9);
	find(dl, 5);
	find(dl, 6);
	insert(dl, 0, 100);
	remove(dl, 1);
	remove(dl, 4);
	insert(dl, 8, 1);
	remove(dl, 2);
	find(dl, 3);
	find(dl, 10);
	cout << "Final size of the list is: " << dl.size() << endl;
}


/**
 *
 * End of Test operational methods
 */

/**
 *
 * main method
 */
int main() {
	cout << "Playing with Data Structures!!!" << endl;
	cout << "######################################################################" << endl;
	processSinglyLinkedList();
	cout << "######################################################################" << endl;
	processDoublyLinkedList();
	cout << "######################################################################" << endl;
	return 0;
}
