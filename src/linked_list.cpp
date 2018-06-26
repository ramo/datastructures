#include <iostream.h>
using namespace std;


class SNode {
	public:
		SNode(int _data) {
			data = _data;
		}

		int data;
		SNode *next = NULL;
};

class SinglyLinkedList {
	public:
		SNode *head = NULL;

		void append(int value) {
			SNode *newNode = new SNode(value);
			cout << "append(): head = " << head << endl;
			if (!head) {
				head = newNode;
			} else {
				SNode *current = head;
				while (current->next) {
					current = current->next;
				}
				current->next = newNode;
			}
		}

		bool remove(int value) {
			cout << "remove() : head = " << head << endl;
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
			cout << "Found value : " << value << ", current = " << current << endl;

			if (current == head) {
				cout << "came here" << endl;
				cout << "head = " << head << endl;
				cout << "head->next = " << head->next << endl;
				head = head->next;
			} else {
				prev->next = current->next;
			}
			delete current;
			return true;
		}

		void print() {
			if (!head) {
				cout << "list is empty" << endl;
				return;
			}
			SNode *current = head;
			while (current) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
};

void remove(SinglyLinkedList sl, int value) {
	if (sl.remove(value)) {
		cout << value << ", removed successfully." << endl;
	} else {
		cout << value << ", is not there." << endl;
	}
	sl.print();
}

int main() {
	SinglyLinkedList sl;
	for (int i = 1; i <= 10; i++) {
		sl.print();
		cout << "i = " << i << endl;
		sl.append(i);
	}
	sl.print();

	// removing some data from list
	remove(sl, 5);
	remove(sl, 11);
	remove(sl, 9);
	remove(sl, 1);
	remove(sl, 4);
	remove(sl, 2);

	return 0;
}
