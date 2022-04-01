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
	Stack(int stackCapacity) : capacity(stackCapacity) {
		if (capacity < 1) throw "Stack capacity must be > 0";
		stack = new T[capacity];
		top = -1;
	}
	~Stack() {
		delete[] stack;
		top = capacity = 0;
	}
	bool IsEmpty() const{
		return top == -1;
	}
	T& Top() const {
		if (IsEmpty()) throw"Stack is empty!";
		return stack[top];
	}
	void Push(const T & data) {
		if (top == capacity - 1) {
			ChangeSize1D(stack, capacity, 2 * capacity);
			capacity *= 2;
		}
		stack[++top] = data;
	}
	T Pop() {
		if (IsEmpty()) throw "Stack is empty. Cannot delete.";
		T t = Top();
		stack[top--].~T();
		return t;
	}
};


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

