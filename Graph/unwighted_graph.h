#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

// undirected graph
template<class T>
class node {                         // the node of graph edge
public:                                
	T data;                            // data
	node* next;                        // next node(edge)
	node(T data, node* next) {         // constructur(data, next)
		this->data = data;
		this->next = next;
	}
	node(int data) {
		this->data = data;             // constructor(data)
		this->next = NULL;
	}
};
template<class T>
class UnW_Graph {                   // Unwegighted graph
private:
	vector<node<T>*> adjLists;         // adjacency lists  
	vector<T> VexArray;                // vetrix array, save vertex data
	int number;                        // the number of vertex
public:
	UnW_Graph() {                      // constructor
		number = 0;
	}
	// operations
	void Build();
	void InsertVertex(T v);
	void InsertEdge(T v1, T v2);
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
			node<T>* pointer = adjLists[i];
			cout << "\"" << VexArray[i] << "\" : ";
			if (!pointer) continue;
			while (pointer) {
				cout << " --" << pointer->data;
				pointer = pointer->next;
			}
			cout << "\n  Number of vertex : " << NumberOfVertices(VexArray[i]) << endl;
			cout << "  Degree : " << Degree(VexArray[i]) << endl;
			cout << "\n";
		}
	}       
};

