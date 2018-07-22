#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define INIT_SIZE 5

class array_list {
	public:
		array_list() {
			mArray = new int[INIT_SIZE];
			mLength = INIT_SIZE;
			mSize = 0;
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
				int *curr;

				// the following typedefs are needed for the iterator to play nicely with C++ STL
		        typedef int value_type;
		        typedef int& reference;
		        typedef int* pointer;
		        typedef int difference_type;
		        typedef std::forward_iterator_tag iterator_category;

		        iterator(int* x = 0):curr(x){}

		        bool operator==(const iterator& x) const {
		        	return curr == x.curr;
		        }

		        bool operator!=(const iterator& x) const {
		        	return curr != x.curr;
		        }

		        reference operator*() const {
		        	return *curr;
		        }

		        iterator& operator++() { //pre increment
		        	curr++;
		        	return *this;
		        }

		        iterator operator++(int) { //post increment
		        	iterator tmp(curr);
		        	curr++;
		        	return tmp;
		        }
		};

		iterator begin() {return iterator(mArray);}
		iterator end() {return iterator(mArray + mSize);}

	private:
		int *mArray;
		int mLength;
		int mSize;

		void check_and_expand_array();
};

#endif
