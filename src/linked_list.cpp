#include <iostream>
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

class SinglyLinkedList {	
	SNode *head;
	SNode *tail;
	int sz;
	
	public:
		SinglyLinkedList() {
			head = tail = NULL;
			sz = 0;
		}

		/**
		 *  Add a value to rear of the list.
		 *  Time complexity: O(1)
		 */	
		void append(int value) {
			SNode *newNode = new SNode(value);
			if (!head) {
				head = tail = newNode;
			} else {
				tail->next = newNode;
				tail = tail->next;
			}
			++sz;
		}

		void insert(int index, int value) {
			if (index < 0 || index > sz) {
				throw invalid_argument( "index out of bound exception");
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
			if (current == head) {
				if (!head) {
					head = tail = newNode;
				} else {
					newNode->next = head;
					head = newNode;
				}
			} else if (current == tail) {
				// This won't happen, just here for the sake 
				// of explaining the different scenario
				tail->next = newNode;
				tail = tail->next;
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
		bool find(int value) {
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
		bool remove(int value) {
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
		void print() {
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
		int size() {
			return sz;
		}
};

/**
 *
 * Test wrapper methods to print some useful information 
 * on performing operations on the linked list
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
 * End of Test operational methods
 */

/**
 *
 * main method
 */
int main() {
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

	return 0;
}
