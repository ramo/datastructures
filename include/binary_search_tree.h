#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


struct Node {
	int data;
	Node* leftChild;
	Node* rightChild;	
	Node(int data) : data(data), leftChild(0), rightChild(0) {}
};


class binary_search_tree {
	public:
		binary_search_tree() : root(0), sz(0) {}
		bool insert(int element);
		bool find(int element);
		int size();
		void clear();
		bool empty();
		bool remove(int element);
		
		void in_order();
		void pre_order();
		void post_order();

		/**
		 *
		 * We could have a successor function which could be used for in order 
		 * traversal from any node (not just root node); But, for this we need 
		 * parent pointer in each node. 
		 */

	private: 
		Node* root;
		int sz;
};


#endif