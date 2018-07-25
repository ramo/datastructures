#include <iostream>
#include "linked_list.h"
#include "array_list.h"
#include "binary_search_tree.h"
using namespace std;

typedef array_list::iterator a_itr;
typedef SinglyLinkedList::iterator s_itr;
typedef DoublyLinkedList::iterator d_itr;


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
 * Array list operations
 */
void remove(array_list &al, int value) {
	if (al.remove(value)) {
		cout << value << " is removed successfully." << endl;
	} else {
		cout << value << " is not there." << endl;
	}
	al.print();
}

void find(array_list &al, int value) {
	if (al.find(value)) {
		cout << value << " is found" << endl;
	} else {
		cout << value << " is not found" << endl;
	}
}

void insert(array_list &al, int index, int value) {
	cout << "Inserting " << value << ", at index: " << index << endl;
	al.insert(index, value);
	al.print();
}

void print(a_itr begin, a_itr end) {
	for (a_itr it = begin; it != end; it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void print(s_itr begin, s_itr end) {
	for (s_itr it = begin; it != end; it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void print(d_itr begin, d_itr end) {
	for (d_itr it = begin; it != end; it++) {
		cout << *it << " ";
	}
	cout << endl;
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
	insert(sl, 7, 1);
	remove(sl, 2);
	find(sl, 3);
	find(sl, 10);
	insert(sl, 7, 44);
	cout << "Final size of the list is: " << sl.size() << endl;
	cout << "Print SinglyLinkedList using iterator pattern" << endl;
	print(sl.begin(), sl.end());
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
	insert(dl, 7, 1);
	remove(dl, 2);
	find(dl, 3);
	find(dl, 10);
	insert(dl, 7, 44);
	cout << "Final size of the list is: " << dl.size() << endl;
	cout << "Print DoublyLinkedList using iterator pattern" << endl;
	print(dl.begin(), dl.end());

}


void processArrayList() {
	cout << "Demo on ArrayList" << endl;
	cout << "######################################################################" << endl;
	array_list al;
	for (int i = 1; i <= 10; i++) {
		al.append(i);
	}
	al.print();

	// Finding, inserting and removing elements in arbitarary order
	cout << "Initial size of the list is: " << al.size() << endl;
	find(al, 7);
	remove(al, 5);
	remove(al, 11);
	insert(al, 3, 15);
	remove(al, 9);
	find(al, 5);
	find(al, 6);
	insert(al, 0, 100);
	remove(al, 1);
	remove(al, 4);
	insert(al, 7, 1);
	remove(al, 2);
	find(al, 3);
	find(al, 10);
	insert(al, 7, 44);
	cout << "Final size of the list is: " << al.size() << endl;
	cout << "Print ArrayList using iterator pattern" << endl;
	print(al.begin(), al.end());
}


void processBST() {
	cout << "Demo on BST" << endl;
	cout << "######################################################################" << endl;
	binary_search_tree bst;
	bst.insert(10);
	bst.insert(5);
	bst.insert(25);
	bst.insert(2);
	bst.insert(7);
	bst.insert(20);
	bst.insert(35);
	bst.insert(30);
	bst.insert(40);
	cout << "Size of the bst is : " << bst.size() << endl;
	cout << "Print BST in order traversal" << endl;
	bst.in_order();
	cout << "Print BST pre order traversal" << endl;
	bst.pre_order();
	cout << "Print BST post order traversal" << endl;
	bst.post_order();
	cout << "Finding an element: 35 =>" << (bst.find(35) ? "Found" : "Not found") << endl;
	cout << "Finding an element: 100 =>" << (bst.find(100) ? "Found" : "Not found") << endl;
	cout << "Finding an element: 7 =>" << (bst.find(7) ? "Found" : "Not found") << endl;
	cout << "================================Removal operations===================" << endl;
	bst.in_order();
	cout << "Remove element: 40 =>" << (bst.remove(40) ? "Removed" : "Not Removed") << endl;
	bst.in_order();
	cout << "Remove element: 100 =>" << (bst.remove(100) ? "Removed" : "Not Removed") << endl;
	bst.in_order();
	cout << "Remove element: 25 =>" << (bst.remove(25) ? "Removed" : "Not Removed") << endl;
	bst.in_order();
	cout << "Remove element: 10 =>" << (bst.remove(10) ? "Removed" : "Not Removed") << endl;
	bst.in_order();

	cout << "Clear the bst" << endl;
	bst.clear();
	bst.in_order();
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
	processArrayList();
	cout << "######################################################################" << endl;
	processBST();
	cout << "######################################################################" << endl;
	return 0;
}
