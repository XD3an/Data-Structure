#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

template<class T>
class Node {                                     // the node of graph edge
public:
	T data;											// data
	int weighted;									// weighted
	Node* next;										// next node(edge)
	Node(T data, int weighted, Node* next) { 	 // constructor(data, weighted, next)
		this->data = data;
		this->weighted = weighted;
		this->next = next;
	}
	Node(T data, int weighted) {                 // constructor(data, weighted)
		this->data = data;
		this->weighted = weighted;
		this->next = NULL;
	}
	Node(T data, Node* next) {                   // constructor(data, next)
		this->data = data;
		this->weighted = 0;
		this->next = next;
	}
};

template<class T>
class W_Graph {									// Weighted graph
private:
	vector<Node<T>*> adjLists;						// adjacency lists
	vector<T> VexArray;                             // vextex array
	int number;                                     // the number of vertex
public:
	W_Graph() {                                     // constructor
		number = 0;
	}
	// operations
	void Build();
	void InsertVertex(T v);
	void InsertEdge(T v1, T v2, int weighted);
	bool IsEmpty() const;
	int NumberOfVertices(T v) const;
	int Degree(T v1) const;
	void BFS(T v);
	void DFS();
	void DFS(int index);
	void components();
	// Print
	void Print() {
		/*
			Output vertex information
			data : edge1 edge2 ....
				Number of vertex :
				Degree :
		*/
		for (int i = 0; i < number; i++) {
			Node<T>* pointer = adjLists[i];
			cout << "\"" << VexArray[i] << "\" : ";
			if (!pointer) {
				cout << "\n";
				continue;
			}
			while (pointer) {
				cout << "--" << pointer->weighted << "-->" << pointer->data << "    ";
				pointer = pointer->next;
			}
			cout << "\n  Number of vertex : " << NumberOfVertices(VexArray[i]) << endl;
			cout << "  Degree : " << Degree(VexArray[i]) << endl;
			cout << endl;
		}
	}
};

