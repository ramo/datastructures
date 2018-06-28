#include <iostream>
#include <sstream>
#include "linked_list.h"
using namespace std;



/**
 *  Add a value to rear of the list.
 *  Time complexity: O(1)
 */	
void SinglyLinkedList :: append(int value) {
	SNode *newNode = new SNode(value);
	if (!head) {
		head = tail = newNode;
	} else {
		tail->next = newNode;
		tail = tail->next;
	}
	++sz;
}

void SinglyLinkedList :: insert(int index, int value) {
	if (index < 0 || index >= sz) {
		stringstream ss;
		ss << "Index out of bound exception: " << index;
		throw invalid_argument(ss.str());
	}

	if (sz == 0 || index == sz-1) { // optimization: empty list or insert as last index
		append(value);
		return;
	}

	int i = 0;
	SNode *current = head;
	SNode *prev = NULL;
	while (i < index && current) {
		++i;
		prev = current;
		current = current->next;
	}
	SNode *newNode = new SNode(value);
	/**
	 * Note: As we have already handled empty list and last index 
	 * insertion using append() function. Here we care only about
	 * middle elements and 0th index element insertion.
	 */
	if (current == head) {
		newNode->next = head;
		head = newNode;
	} else {
		prev->next = newNode;
		newNode->next = current;
	}
	++sz;
}


/**
 *
 * Find an element in the list
 * Return true if found else otherwise.
 * Time complexity: O(n)
 */
bool SinglyLinkedList :: find(int value) {
	SNode *current = head;
	bool found = false;
	while (current) {
		if (current->data == value) {
			found = true;
			break;
		}
		current = current->next;
	}
	return found;
}

/**
 *  Remove an element from list
 *	return - true if the value is removed, false otherwise.
 *  Time complexity: O(n)
 */	
bool SinglyLinkedList :: remove(int value) {
	if (!head)
		return false;
	SNode *current = head;
	SNode *prev = NULL;
	while (current) {
		if (current->data == value) {
			break;
		}
		prev = current;
		current = current->next;
	}
	if (!current)
		return false;

	if (current == head) {
		if (head == tail) {
			head = tail = NULL;
		} else {
			head = head->next;
		}
	} else if (current == tail) {
		prev->next = NULL;
		tail = prev;
	} else {
		prev->next = current->next;
	}
	delete current;
	--sz;
	return true;
}

/**
 * Print the list 
 * Time complexity: O(n)
 */
void SinglyLinkedList :: print() {
	if (!head) {
		cout << "[]" << endl;
		return;
	}
	SNode *current = head;
	do {
		cout << current->data;
		current = current->next;
		if (current) {
			cout << " -> ";
		}
	} while(current);
	cout << endl;
}

/**
 *
 * Returns the size of the list
 */
int SinglyLinkedList :: size() {
	return sz;
}

void DoublyLinkedList :: append(int data) {
	DNode *newNode = new DNode(data);
	if (head == NULL) {
		head = tail = newNode;
	} else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	++sz;
}

void DoublyLinkedList :: insert(int index, int data) {
	if (index < 0 || index >= sz) {
		stringstream ss;
		ss << "Index out of bound exception: " << index;
		throw invalid_argument(ss.str());
	}

	// Check if list is empty or last index insertion
	if (sz == 0 || index == sz-1) {
		append(data);
		return;
	}

	DNode *current = head;
	int i = 0;
	while (i < index && current) {
		++i;
		current = current->next;
	}

	DNode *newNode = new DNode(data);
	if (current == head) {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	} else {
		newNode->prev = current->prev;
		current->prev->next = newNode;
		newNode->next = current;
		current->prev = newNode;
	}
	++sz;
}

bool DoublyLinkedList :: find(int data) {
	DNode *current = head;
	bool found = false;
	while (current) {
		if (current->data == data) {
			found = true;
			break;
		}
		current = current->next;
	}
	return found;
}

bool DoublyLinkedList :: remove(int data) {
	DNode *current = head;
	while (current) {
		if (current->data == data) {
			break;
		}
		current = current->next;
	}
	if (!current)
		return false;

	if (current == head) {
		if (head == tail) {
			head = tail = NULL;
		} else {
			head = head->next;	
			head->prev = NULL;
		}
	} else if (current == tail) {
		tail = tail->prev;
		tail->next = NULL;
	} else {
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}
	delete current;
	--sz;

	return true;
}

int DoublyLinkedList :: size() {
	return sz;
}

void DoublyLinkedList :: print() {
	if (!head) {
		cout << "[]" << endl;
		return;
	}
	DNode *current = head;
	do {
		cout << current->data;
		current = current->next;
		if (current) {
			cout << " <-> ";
		}
	} while(current);
	cout << endl;
}
