#include <iostream>
#include <sstream>
using namespace std;

/**
 * Building block for our linked list implementation.
 */	
struct SNode {
	int data;
	SNode *next;

	SNode(int _data) {
		data = _data;
		next = NULL;
	}
};

struct DNode
{
	int data;
	DNode *next;
	DNode *prev;
	DNode(int _data) {
		data = _data;
		next = NULL;
		prev = NULL;
	}
};

class SinglyLinkedList {	
	SNode *head;
	SNode *tail;
	int sz;
	
	public:
		SinglyLinkedList() {
			head = tail = NULL;
			sz = 0;
		}

		void append(int data);
		void insert(int index, int data);
		bool remove(int data);
		bool find(int data);
		int size();
		void print();
};

class DoublyLinkedList
{
	DNode *head;
	DNode *tail;
	int sz;

	public:
		DoublyLinkedList() {
			head = NULL;
			tail = NULL;
			sz = 0;
		}

		void append(int data);
		void insert(int index, int data);
		bool remove(int data);
		bool find(int data);
		int size();
		void print();
};


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
	if (index < 0 || index > sz) {
		stringstream ss;
		ss << "Index out of bound exception: " << index;
		throw invalid_argument(ss.str());
	}

	if (sz == 0 || index == sz) { // optimization: empty list or insert as last index
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
	if (index < 0 || index > sz) {
		stringstream ss;
		ss << "Index out of bound exception: " << index;
		throw invalid_argument(ss.str());
	}

	// Check if list is empty or last index insertion
	if (sz == 0 || index == sz) {
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
	cout << "######################################################################" << endl;
	processSinglyLinkedList();
	cout << "######################################################################" << endl;
	processDoublyLinkedList();
	cout << "######################################################################" << endl;
	return 0;
}
