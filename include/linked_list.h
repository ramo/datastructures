#ifndef LINKED_LIST_H
#define LINKED_LIST_H
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
#endif