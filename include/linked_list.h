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

		class iterator : public std::iterator<std::forward_iterator_tag, int> {
			public:
				friend class array_list;
				SNode *curr;

				// the following typedefs are needed for the iterator to play nicely with C++ STL
		        typedef int value_type;
		        typedef int& reference;
		        typedef int* pointer;
		        typedef int difference_type;
		        typedef std::forward_iterator_tag iterator_category;

		        iterator(SNode* x = 0):curr(x){}

		        bool operator==(const iterator& x) const {
		        	return curr == x.curr;
		        }

		        bool operator!=(const iterator& x) const {
		        	return curr != x.curr;
		        }

		        reference operator*() const {
		        	return curr->data;
		        }

		        iterator& operator++() { //pre increment
		        	curr = curr->next;
		        	return *this;
		        }

		        iterator operator++(int) { //post increment
		        	iterator tmp(curr);
		        	curr = curr->next;
		        	return tmp;
		        }
		};

		iterator begin() {return iterator(head);}
		iterator end() {return iterator(NULL);}

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

		class iterator : public std::iterator<std::forward_iterator_tag, int> {
			public:
				friend class array_list;
				DNode *curr;

				// the following typedefs are needed for the iterator to play nicely with C++ STL
		        typedef int value_type;
		        typedef int& reference;
		        typedef int* pointer;
		        typedef int difference_type;
		        typedef std::forward_iterator_tag iterator_category;

		        iterator(DNode* x = 0):curr(x){}

		        bool operator==(const iterator& x) const {
		        	return curr == x.curr;
		        }

		        bool operator!=(const iterator& x) const {
		        	return curr != x.curr;
		        }

		        reference operator*() const {
		        	return curr->data;
		        }

		        iterator& operator++() { //pre increment
		        	curr = curr->next;
		        	return *this;
		        }

		        iterator operator++(int) { //post increment
		        	iterator tmp(curr);
		        	curr = curr->next;
		        	return tmp;
		        }
		};

		iterator begin() {return iterator(head);}
		iterator end() {return iterator(NULL);}

};
#endif
