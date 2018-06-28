#include <iostream>
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

	private:
		int *mArray;
		int mLength;
		int mSize;

		void check_and_expand_array();
};
