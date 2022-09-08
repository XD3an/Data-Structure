#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include "unwighted_graph.h"
#include "weighted_graph.h"
using namespace std;

vector<bool> visited;

// unweighted graph
template<class T>
void UnW_Graph<T>::Build() {
	/*
		vertex : 0, 1, 2, 3, 4, 5, 6, 7
		edge : 0-1, 0-2, 1-3, 1-4, 2-5, 2-6, 3-7, 4-7, 5-7, 6-7
	*/
	InsertVertex(0);
	InsertVertex(1);
	InsertVertex(2);
	InsertVertex(3);
	InsertVertex(4);
	InsertVertex(5);
	InsertVertex(6);
	InsertVertex(7);
	InsertEdge(0, 1);
	InsertEdge(0, 2);
	InsertEdge(1, 3);
	InsertEdge(1, 4);
	InsertEdge(2, 5);
	InsertEdge(2, 6);
	InsertEdge(3, 7);
	InsertEdge(4, 7);
	InsertEdge(5, 7);
	InsertEdge(6, 7);
}
template<class T>
int UnW_Graph<T>::NumberOfVertices(T v) const {
	// Return index(the number) of the vertex
	for (int i = 0; i < number; i++) {      // find the index of the vertex in VexArray.
		if (VexArray[i] == v)					// If found out, then return the index.
			return i;
	}
	return -1;									// Else, return -1.
}
template<class T>
int UnW_Graph<T>::Degree(T v) const {
	// Return the degree of the vertex.
	int sum = 0;                            // Declare sum to save degree.
	int index = NumberOfVertices(v);        // Declare index to save the index of the vertex in VexArray.
	node<T>* pointer = adjLists[index];     // Declrae pointer to be current position.
	while (pointer) {					    // If pointer is not a null ptr, sum++ and pointer = pointer->next.
		sum++;
		pointer = pointer->next;
	}
	return sum;								// return sum
}
template<class T>
void UnW_Graph<T>::InsertVertex(T v) {      
	// Insert a vertex in graph.
	number = number + 1;					// number + 1
	VexArray.push_back(v);					// Push vertex data to the tail of VexArray.
	adjLists.push_back(NULL);				// Push False to the adjLists.
}
template<class T>
bool UnW_Graph<T>::IsEmpty() const {
	// Return wether the graph is empty.
	return number == 0;
}
template<class T>
void UnW_Graph<T>::InsertEdge(T v1, T v2) {
	// Insert the edge between two vertex v1 and v2.
	int i, v1_Index = -1, v2_Index = -1;
	// Find the index of two vertex.
	i = NumberOfVertices(v1);
	if (i == -1) return;
	else v1_Index = i;
	i = NumberOfVertices(v2);
	if (i == -1) return;
	else v2_Index = i;
	// Insert the edge.
	node<T>* pointer1 = adjLists[v1_Index];
	if (adjLists[v1_Index] == NULL) {							// If pointer is a null ptr, then new a pointer to save the edge.
		adjLists[v1_Index] = new node<T>(VexArray[v2_Index]); ;
	}
	else {														// Else, find the null ptr of adjLists, then insert in the position.
		while (pointer1->next) {
			pointer1 = pointer1->next;
		}
		pointer1->next = new node<T>(VexArray[v2_Index]);
	}
	node<T>* pointer2 = adjLists[v2_Index];
	if (adjLists[v2_Index] == NULL) {							// If pointer is a null ptr, then new a pointer to save the edge.
		adjLists[v2_Index] = new node<T>(VexArray[v1_Index]);
	}
	else {														// Else, find the null ptr of adjLists, then insert in the position.
		while (pointer2->next) {
			pointer2 = pointer2->next;
		}
		pointer2->next = new node<T>(VexArray[v1_Index]);
	}
}
template<class T>
void UnW_Graph<T>::BFS(T v) {
	// Breadthj-First Search
	visited.clear();									// Clear the visited.
	for (int i = 0; i < number; i++) {						// Push false to visited.
		visited.push_back(false);
	}
	queue<int> q;										// Declare queue to save the order of traversal.
	int i;
	i = NumberOfVertices(v);							// Declare i to save the index of the vertex in VexArray.
	if (i != -1) q.push(i);								// If the index exist, then push the index of the front index to queue.
	else {												// Else, output "Fail" information to warn user.
		cout << " Fail! \n";
		return;
	}
	// Traversal the vertex in the queue order.
	while (!q.empty()) {
		int current_index = q.front();
		q.pop();
		node<T>* pointer = adjLists[current_index];		// Declare pointer to save current position.
		if (visited[current_index] == 0) {				// If the vertex have been traversaled, then output it and set visited[vertex index] to true.
			cout << VexArray[current_index] << " ";
			visited[current_index] = true;
		}
		while (pointer) {								// If exist others vertex in the edge infomation, then traversals them.
			i = NumberOfVertices(pointer->data);
			if (!visited[i]) {							// If the vertex have been traversaled, then output it and set visited[vertex index] to true.
				cout << pointer->data << " ";
				visited[i] = 1;
				q.push(i);								// Push the data of the pointer to queue.
			}
			pointer = pointer->next;					// Move pointer to the next pointer.
		}
	}
	fill(visited.begin(), visited.end(), false);		// Fill full false to  visited.
}
template<class T>
void UnW_Graph<T>::DFS() {
	// Driver of DFS
	// Depth-First Search
	visited.clear();								// Clear visited.
	for (int i = 0; i < number; i++) {				// Push false to visited.
		visited.push_back(false);
	}
	DFS(0);											// DFS start to 0.
	fill(visited.begin(), visited.end(), false);	// Fill full false to visited.
}
template<class T>
void UnW_Graph<T>::DFS(const int n) {
	// Workhouse eof DFS
	visited[n] = true;								// Set VexArray[n] is true to represent it have been traversaled.
	cout << VexArray[n] << " ";						// Outpur the data 
	node<T>* pointer = adjLists[n];					// Declare pointer to save current position.
	while (pointer) {								// Find the position of next vertex.
		int i;
		i = NumberOfVertices(pointer->data);		// Save the index of current vertex.
		if (i == -1) return;						
		if (visited[i] == false)					// If the vertex had not been traversaled, then traversaled. 
			DFS(i);
		pointer = pointer->next;					// Move pointer to next pointer.
	}
}
template<class T>
void UnW_Graph<T>::components() {
	// Output each components of the graph using DFS.
	visited.clear();								// Clear  visited.
	for (int i = 0; i < number; i++) {				//  Push false to the visited.
		visited.push_back(false);
	}
	for (int i = 0; i < number; i++) {				// Using DFS to traversal and output each components
		if (!visited[i]) {
			DFS(i);
			cout << endl;
		}
	}
	fill(visited.begin(), visited.end(), false);	// Fill full false to visited.
}

// weighted graph
template<class T>
void W_Graph<T>::Build() {
	/*
		Vertex : 0, 1, 2, 3, 4, 5, 6
		Edge : 0--1--28, 0--10--5, 1--16--2, 1--14--6, 5--25--4, 2--12--3, 6--18--3, 6--24--4, 4--22--3 
	*/
	InsertVertex(0);
	InsertVertex(1);
	InsertVertex(2);
	InsertVertex(3);
	InsertVertex(4);
	InsertVertex(5);
	InsertVertex(6);
	InsertEdge(0, 1, 28);
	InsertEdge(0, 5, 10);
	InsertEdge(1, 2, 16);
	InsertEdge(1, 6, 14);
	InsertEdge(5, 4, 25);
	InsertEdge(2, 3, 12);
	InsertEdge(6, 3, 18);
	InsertEdge(6, 4, 24);
	InsertEdge(4, 3, 22);
}
template<class T>
bool W_Graph<T>::IsEmpty() const {
	// Return wether graph is empty.
	return number == 0;
}
template<class T>
int W_Graph<T>::NumberOfVertices(T v) const {
	// Return index(the number) of the vertex
	for (int i = 0; i < number; i++) {				 // find the index of the vertex in VexArray.
		if (VexArray[i] == v)							// If found out, then return the index.
			return i;
	}
	return -1;											// Else, return -1.
}
template<class T>
int W_Graph<T>::Degree(T v) const {
	// Return the degree of the vertex.
	int sum = 0;                            // Declare sum to save degree.
	int index = NumberOfVertices(v);        // Declare index to save the index of the vertex in VexArray .
	Node<T>* pointer = adjLists[index];     // Declrae pointer to be current position.
	while (pointer) {					    // If pointer is not a null ptr, sum++ and pointer = pointer->next.
		sum++;
		pointer = pointer->next;
	}
	return sum;								// return sum
}
template<class T>
void W_Graph<T>::InsertVertex(T v) {
	// Insert a vertex in graph.
	number = number + 1;					// number + 1
	VexArray.push_back(v);					// Push vertex data to the tail of VexArray.
	adjLists.push_back(NULL);				// Push False to the adjLists.
}
template<class T>
void W_Graph<T>::InsertEdge(T v1, T v2, int weighted) {
	// Insert the edge between two vertex v1 and v2.
	int i, v1_Index = -1, v2_Index = -1;
	// Find the index of two vertex.
	i = NumberOfVertices(v1);
	if (i == -1) return;
	else v1_Index = i;
	i = NumberOfVertices(v2);
	if (i == -1) return;
	else v2_Index = i;
	// Insert the edge.
	Node<T>* pointer1 = adjLists[v1_Index];
	if (adjLists[v1_Index] == NULL) {										// If pointer is a null ptr, then new a pointer to save the edge.
		adjLists[v1_Index] = new Node<T>(VexArray[v2_Index], weighted);
	}
	else {																	// Else, find the null ptr of adjLists, then insert in the position.
		while (pointer1->next) {
			pointer1 = pointer1->next;
		}
		pointer1->next = new Node<T>(VexArray[v2_Index], weighted);
	}

	Node<T>* pointer2 = adjLists[v2_Index];
	if (adjLists[v2_Index] == NULL) {										// If pointer is a null ptr, then new a pointer to save the edge.
		adjLists[v2_Index] = new Node<T>(VexArray[v1_Index], weighted);
	}
	else {																	// Else, find the null ptr of adjLists, then insert in the position.
		while (pointer2->next) {
			pointer2 = pointer2->next;
		}
		pointer2->next = new Node<T>(VexArray[v1_Index], weighted);
	}
}
template<class T>
void W_Graph<T>::BFS(T v) {
	// Breadthj-First Search
	visited.clear();									// Clear the visited.
	for (int i = 0; i < number; i++) {						// Push false to visited.
		visited.push_back(false);
	}
	queue<int> q;										// Declare queue to save the order of traversal.
	int i;
	i = NumberOfVertices(v);							// Declare i to save the index of the vertex in VexArray.
	if (i != -1) q.push(i);								// If the index exist, then push the index of the front index to queue.
	else {												// Else, output "Fail" information to warn user.
		cout << " Fail! \n";
		return;
	}
	// Traversal the vertex in the queue order.
	while (!q.empty()) {
		int current_index = q.front();
		q.pop();
		Node<T>* pointer = adjLists[current_index];		// Declare pointer to save current position.
		if (visited[current_index] == 0) {				// If the vertex have been traversaled, then output it and set visited[vertex index] to true.
			cout << VexArray[current_index] << " ";
			visited[current_index] = true;
		}
		while (pointer) {								// If exist others vertex in the edge infomation, then traversals them.
			i = NumberOfVertices(pointer->data);
			if (!visited[i]) {							// If the vertex have been traversaled, then output it and set visited[vertex index] to true.
				cout << pointer->data << " ";
				visited[i] = 1;
				q.push(i);								// Push the data of the pointer to queue.
			}
			pointer = pointer->next;					// Move pointer to the next pointer.
		}
	}
	fill(visited.begin(), visited.end(), false);		// Fill full false to  visited.
}
template<class T>
void W_Graph<T>::DFS() {
	// Driver of DFS
	// Depth-First Search
	visited.clear();								// Clear visited.
	for (int i = 0; i < number; i++) {				// Push false to visited.
		visited.push_back(false);
	}
	DFS(0);											// DFS start to 0.
	fill(visited.begin(), visited.end(), false);	// Fill full false to visited.
}
template<class T>
void W_Graph<T>::DFS(const int n) {
	// Workhouse eof DFS
	visited[n] = true;								// Set VexArray[n] is true to represent it have been traversaled.
	cout << VexArray[n] << " ";						// Outpur the data 
	Node<T>* pointer = adjLists[n];					// Declare pointer to save current position.
	while (pointer) {								// Find the position of next vertex.
		int i;
		i = NumberOfVertices(pointer->data);		// Save the index of current vertex.
		if (i == -1) return;
		if (visited[i] == false)					// If the vertex had not been traversaled, then traversaled. 
			DFS(i);
		pointer = pointer->next;					// Move pointer to next pointer.
	}
}
template<class T>
void W_Graph<T>::components() {
	// Output each components of the graph using DFS.
	visited.clear();								// Clear  visited.
	for (int i = 0; i < number; i++) {				//  Push false to the visited.
		visited.push_back(false);
	}
	for (int i = 0; i < number; i++) {				// Using DFS to traversal and output each components
		if (!visited[i]) {
			DFS(i);
			cout << endl;
		}
	}
	fill(visited.begin(), visited.end(), false);	// Fill full false to visited.
}

// Menu
template<class T>
int menu(UnW_Graph<T> ug, W_Graph<T> wg) {
	cout << "================================================================================================\n"
		<< "===                *******     *******        ****       *******      **    **               ===\n"
		<< "===               ***          **    **      **  **      **    **     **    **               ===\n"
		<< "===               **   ***     *******      **    **     *******      ********               ===\n"
		<< "===               ***   **     **    **     ********     **           **    **               ===\n"
		<< "===                *******     **    **     **    **     **           **    **               ===\n"
		<< "================================================================================================\n"
		<< "Please select graph form the following options!\n(Input 1, 2...)\n\n"
		<< "  1. unweighted graph.\n\n"
		<< "  2. weighted graph.  \n\n"
		<< "  If you want to end, input \"-1\".\n\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	string in;
	cout << " Your option : ";
	cin >> in;
	if (!(in == "1" || in == "2" || in == "-1")) {
		cout << "Invalid Input!\n";
		return -1;
	}
	if (in == "1") {
		return into_UnW_Graph(ug);
	}
	else if (in == "2") {
		return into_W_Graph(wg);
	}
	else {
		return -1;
	}
}
template<class T>
int into_UnW_Graph(UnW_Graph<T> g1){
	cout << "\n-----------------------------------------next stage--------------------------------------------\n";
	cout << "\nPlease select from the following options ! \n\n"
		<< "  1. Print Graph Information( Adjacency Lists ).\n\n"
		<< "  2. Breadth-First Search. \n\n"
		<< "  3. Depth-First Search.   \n\n"
		<< "  4. Print components.     \n\n"
		<< "  5. Do all things.        \n\n"
		<< "  If you want to end, input \"-1\".\n\n";
	string in;
	cout << " Your option : ";
	cin >> in;
	if (!(in == "1" || in == "2" || in == "3" || in == "4" || in == "5" || in == "-1")) {
		cout << "\n Invalid input! \n\n";
		return -1;
	}
	if (in != "-1")
		cout << "-------------------------------------------Result-----------------------------------------------\n";
	if (!in.compare("1")) {
		g1.Print();
		return 1;
	}
	else if (!in.compare("2")) {
		cout << " Breadth-First Search : ";
		g1.BFS(0);
		cout << endl;
		return 2;
	}
	else if (!in.compare("3")) {
		cout << " Depth-First Search : ";
		g1.DFS();
		cout << endl;
		return 3;
	}
	else if (!in.compare("4")) {
		cout << " Components : ";
		g1.components();
		return 4;
	}
	else if (!in.compare("5")) {
		g1.Print();
		cout << " Breadth-First Search : ";
		g1.BFS(0);
		cout << "\n\n Depth-First Search : ";
		g1.DFS();
		cout << "\n\n Components : ";
		g1.components();
		return 5;
	}
	else {
		return -1;
	}
}
template<class T>
int into_W_Graph(W_Graph<T> g1) {
	cout << "\n-----------------------------------------next stage--------------------------------------------\n";
	cout << "\nPlease select from the following options ! \n\n"
		<< "  1. Print Graph Information( Adjacency Lists ).\n\n"
		<< "  2. Breadth-First Search. \n\n"
		<< "  3. Depth-First Search.   \n\n"
		<< "  4. Print components.     \n\n"
		<< "  5. Do all things.        \n\n"
		<< "  If you want to end, input \"-1\".\n\n";
	string in;
	cout << " Your option : ";
	cin >> in;
	if (!(in == "1" || in == "2" || in == "3" || in == "4" || in == "5" || in == "-1")) {
		cout << "\n Invalid input! \n\n";
		return -1;
	}
	if (in != "-1")
		cout << "-------------------------------------------Result-----------------------------------------------\n";
	if (!in.compare("1")) {
		g1.Print();
		return 1;
	}
	else if (!in.compare("2")) {
		cout << " Breadth-First Search : ";
		g1.BFS(0);
		cout << endl;
		return 2;
	}
	else if (!in.compare("3")) {
		cout << " Depth-First Search : ";
		g1.DFS();
		cout << endl;
		return 3;
	}
	else if (!in.compare("4")) {
		cout << " Components : ";
		g1.components();
		return 4;
	}
	else if (!in.compare("5")) {
		g1.Print();
		cout << " Breadth-First Search : ";
		g1.BFS(0);
		cout << "\n\n Depth-First Search : ";
		g1.DFS();
		cout << "\n\n Components : ";
		g1.components();
		return 5;
	}
	else {
		return -1;
	}
}
void Enter() {
	char d;
	cout << "\n\nPLease input any key to continue";
	cin >> d;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
        // test
        /*
	UnW_Graph<int> ug;
	W_Graph<int> wg;	
	ug.Build();
	wg.Build();
        */
}
