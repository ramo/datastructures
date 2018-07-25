#include "binary_search_tree.h"
#include <iostream>

using namespace std;

bool binary_search_tree :: insert(int element) {
	Node* newNode = new Node(element);
	if (!root) {
		root = newNode;
		++sz;
		return true;
	}

	Node* curr = root;
	while (curr) {
		if (curr->data > element) {
			if (!curr->leftChild) {
				curr->leftChild = newNode;
				++sz;
				return true;
			} else {
				curr = curr->leftChild;	
			}
		} else if (curr->data < element) {
			if (!curr->rightChild) {
				curr->rightChild = newNode;
				++sz;
				return true;
			} else {
				curr = curr->rightChild;	
			}
		} else { // we don't allow duplicates
			break;
		}
	}
	return false;
}

int binary_search_tree :: size() {
	return sz;
}

void helper_in_order(Node* node) {
	if (!node)
		return;
	helper_in_order(node->leftChild);
	cout << node->data << " ";
	helper_in_order(node->rightChild);
}

void binary_search_tree :: in_order() { //LEFT-ROOT-RIGHT
	helper_in_order(root);
	cout << endl;
}

void helper_post_order(Node* node) {
	if (!node)
		return;
	helper_post_order(node->leftChild);
	helper_post_order(node->rightChild);
	cout << node->data << " ";
}

void binary_search_tree :: post_order() { //LEFT-RIGHT-ROOT
	helper_post_order(root);
	cout << endl;
}

void helper_pre_order(Node* node) {
	if (!node)
		return;
	cout << node->data << " ";
	helper_pre_order(node->leftChild);
	helper_pre_order(node->rightChild);
}

void binary_search_tree :: pre_order() { //ROOT-LEFT-RIGHT
	helper_pre_order(root);
	cout << endl;
}

bool binary_search_tree :: empty() {
	return sz > 0;
}

bool binary_search_tree :: find(int element) {
	bool result = false;
	Node* curr = root;
	while (curr) {
		if (curr->data == element) {
			result = true;
			break;
		} else if (curr->data > element) {
			curr = curr->leftChild;
		} else {
			curr = curr->rightChild;
		}
	}
	return result;
}

Node* helper_remove(Node* node, int element, int* result) {
	if (!node) {
		*result = 0;
		return 0;
	}

	if (node->data < element) {
		node->rightChild = helper_remove(node->rightChild, element, result);
	} else if (node->data > element) {
		node->leftChild = helper_remove(node->leftChild, element, result);
	} else {
		if (node->rightChild) { //case1: 2 child or single child (right)
			//take successor 
			Node* curr = node->rightChild;
			while (curr->leftChild) {
				curr = curr->leftChild;
			}
			node->data = curr->data;
			node->rightChild = helper_remove(node->rightChild, curr->data, result);
		} else if (node->leftChild) { //case2: single child (left)
			//take predecessor
			Node* curr = node->leftChild;
			while (curr->rightChild) {
				curr = curr->rightChild;
			}
			node->data = curr->data;
			node->leftChild = helper_remove(node->leftChild, curr->data, result);
		} else {		//case3: no child (leaf node)
			delete node;
			*result = 1;
			return 0;
		}
	}
	return node;
}

bool binary_search_tree :: remove(int element) {
	//Let's try recursive approach first
	int result = 0;
	root = helper_remove(root, element, &result);
	return result == 1;
}

Node* helper_clear(Node* node) {
	if (!node)
		return 0;
	node->leftChild = helper_clear(node->leftChild);
	node->rightChild = helper_clear(node->rightChild);
	delete node;
	return 0;
}

void binary_search_tree :: clear() {
	cout << "Before clearing " << root << endl;
	root = helper_clear(root);
	sz = 0;
	cout << "After clearing " << root << endl;
}
