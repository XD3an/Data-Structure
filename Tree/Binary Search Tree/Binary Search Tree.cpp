#include <iostream>
#include <string.h>
using namespace std;

// forward declartion
template<class T>
class BST;

// class node
template<class T>
class node {
	// friend classes & functions
	friend class BST<T>;
private:
	T data;								    // data
	node<T>* left, * right;				    // left children & right children
public:
	node() {						        // constructor  node()
		data = -1;
		left = right = NULL;
	}
	node(T data) {						    // constructor node(data)
		this->data = data;
		left = right = NULL;
	}
};

template<class T>
class BST {
public:
	node<T>* root;							// node root
	BST() {									// constructor BST() 
		root = NULL;
	}
	BST(T data, int key) {					// consturctor BST(data, key)
		root = new node<T>(data);
	}
	// operation
	void insert(T data);                    // insert node
	void inorder(node<T>* currentNode);     // inorder traversal
	void preorder(node<T>* currentNode);    // preorder traversal
	void postorder(node<T>* currentNode);   // postorder traversal
};

template<class T>
void BST<T>::insert(T data) {
	node<T>* newNode;						// Declaring a newNode.
	newNode = new node<T>(data);
	node<T>* x = NULL, * y = NULL;			// Declaring two tempNode. 
	x = root;
	while (x) {								// Finding a position to storage the newNode.
		y = x;
		if (newNode->data < x->data) {			// If newNode's value > leafNode's value,
			x = x->left;							// then find others position in leaf Nodes left.
		}
		else {									// If newNode's value < leafNode's value,
			x = x->right;							// then find others position in leaf Nodes right.
		}
	}
	if (y == NULL) {							// Inserting the newNode in tree.
		root = newNode;
	}
	else if (newNode->data < y->data) {
		y->left = newNode;
	}
	else {
		y->right = newNode;
	}
}
template<class T>
void BST<T>::inorder(node<T>* currentNode) {
	if (currentNode) {							// If curretnNode is not NULL.
		inorder(currentNode->left);				    // L D R
		cout << currentNode->data << " ";
		inorder(currentNode->right);
	}
}
template<class T>
void BST<T>::preorder(node<T>* currentNode) {
	if (currentNode) {							// If vurrentNode is not NUL.
		cout << currentNode->data << " ";			// D L R
		preorder(currentNode->left);
		preorder(currentNode->right);
	}
}
template<class T>
void BST<T>::postorder(node<T>* currentNode) {
	if (currentNode) {							// If currentNode is not NULL.
		postorder(currentNode->left);				// L R D
		postorder(currentNode->right);
		cout << currentNode->data << " ";
	}
}


template<class T>
istream& operator>>(istream& is, BST<T>& tree) {
	int size;
	cout << "Size :";							// Input size.
	cin >> size;
	for (int i = 0; i < size; i++) {			// Input data.
		int temp;
		cin >> temp;
		tree.insert(temp);
	}
	return is;
}
template<class T>
ostream& operator<<(ostream& os, BST<T>& tree) {
	cout << "==========================Traversal========================\n";
	cout << "Inorder : ";						// Inoorder traversal.
	tree.inorder(tree.root);
	cout << endl;
	cout << "Preorder : ";						// Preorder traversal.
	tree.preorder(tree.root);
	cout << endl;
	cout << "Postorder : ";						// Postorder traversal.
	tree.postorder(tree.root);
	return os;
}

int main()
{
	/*
	BST<int> tree;
	cin >> tree;
	cout << tree << endl;
	return 0;
	*/
}


