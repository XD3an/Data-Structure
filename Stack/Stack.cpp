#include <iostream>
#include <string.h>
using namespace std;

// ChangeSize1D
template<class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize) {
	//if (newSize < 0) throw"New length must be >= 0";
	T* temp = new T[newSize];
	int number = min(oldSize, newSize);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}

template<class T>
class Stack {
private:
	T* stack;
	int top;
	int capacity;
public:
	Stack(int stackCapacity);
	~Stack();
	bool IsEmpty() const;
	T& Top() const;
	void Push(const T& data);
	T Pop();
};
template<class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity) {
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}
template<class T>
Stack<T>::~Stack() {
	delete[] stack;
	top = capacity = 0;
}
template<class T>
bool Stack<T>::IsEmpty() const {
	return top == -1;
}
template<class T>
T& Stack<T>::Top() const {
	if (IsEmpty()) throw"Stack is empty!";
	return stack[top];
}
template<class T>
void Stack<T>::Push(const T & data) {
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = data;
}
template<class T>
T Stack<T>:: Pop() {
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	T t = Top();
	stack[top--].~T();
	return t;
}

int main()
{
	// test
	/*
	int n;
	cin >> n;
	Stack<int> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.Push(x);
	}
	for (int i = 0; i < n; i++) {
		cout << a.Pop() << endl;
	}
	*/
}

