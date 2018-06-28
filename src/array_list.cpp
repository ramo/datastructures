#include <iostream>
#include <sstream>
#include "array_list.h"

using namespace std;

void array_list :: append(int data) {
	check_and_expand_array();
	mArray[mSize++] = data;
}

void array_list :: check_and_expand_array() {
	if (mSize == mLength) { //If array is full
		mLength *= 2; // double the size of backing array
		int *tmp = mArray;
		mArray = new int[mLength];
		memcpy(mArray, tmp, sizeof(int) * mSize);
		delete[] tmp;
	}	
}

void array_list :: insert(int index, int data) {
	if (index < 0 || index >= mSize) {
		stringstream ss;
		ss << "Index out of bound exception: " << index;
		throw invalid_argument(ss.str());
	}
	check_and_expand_array();

	for (int i = mSize; i >= index; i--) {
		mArray[i] = mArray[i-1];
	}

	mArray[index] = data;
	++mSize;
}

bool array_list :: remove(int data) {
	int idx = -1;
	for (int i = 0; i < mSize; i++) {
		if (mArray[i] == data) {
			idx = i;
			break;
		}
	}

	if (idx == -1)
		return false;

	for (int i = idx; i < mSize-1; i++) {
		mArray[i] = mArray[i+1];
	}
	--mSize;

	return true;
}

bool array_list :: find(int data) {
	bool found = false;
	for (int i = 0; i < mSize; i++) {
		if (mArray[i] == data) {
			found = true;
			break;
		}
	}
	return found;
}

int array_list :: size() {
	return mSize;
}

void array_list :: print() {
	if (mSize == 0) {
		cout << "[]" << endl;
	} else {
		for (int i = 0; i < mSize; i++) {
			cout << mArray[i] << " ";
		}
		cout << endl;
	}
}
