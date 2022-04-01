#include <iostream>
using namespace std;

template<class T>
// ChangeSize1D
void ChangeSize1D(T*& a, const int oldSize, const int newSize) {
	if (newSize < 0) throw"New length must be >= 0";

	T* temp = new T[newSize];
	int number = min(oldSize, newSize);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}
template<class T>
class Stack {
public:
	Stack(int stackCapacity);
	~Stack() { delete[] stack; }
	bool IsEmpty()const;
	T& Top() const;
	void Push(const T& item);
	void Pop();
private:
	T* stack;     // array for stack elements
	int top;      // position of top element
	int capacity; // capacity of stack array 
};
// constructor
template<class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}
// IsEmpty
template<class T>
inline bool Stack<T>::IsEmpty()const { return top == -1; }
// Top
template<class T>
inline T& Stack<T>::Top()const {
	if (IsEmpty()) throw"Stack is empty!";
	return stack[top];
}	
// Push
template<class T>
void Stack<T>::Push(const T& x) {
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}
// Pop
template<class T>
void Stack<T>::Pop() {
	if (IsEmpty()) throw"Stack is empty. Cannot delete.";
	stack[top--].~T();
}


int main()
{
	int n;
	cin >> n;
	Stack<int> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.Push(x);
	}
	for (int i = n - 1; i >= 0; i--) {
		cout << a.Top() << " ";
		a.Pop();
	}
}

