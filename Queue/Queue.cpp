#include <iostream>
using namespace std;

template<class T>
void ChangeSize1D(T*& a, const int oldSize, int newSize) 
{
    if (newSize < 0) throw "New length must be >= 0";
    T* temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

template<class T>
class Queue 
{
private:
    T* queue;
    int front, rear, capacity;
public:
    Queue(int queueCapacity);
    ~Queue();
    bool IsEmpty() const;
    T& Front() const;
    T& Rear() const;
    void Push(const T& data);
    void Pop();
};

// Queue
template<class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) 
{
    if (queueCapacity < 1) throw "Queue capacity must be > 0";
    queue = new T[queueCapacity];
    front = rear = -1;
}

// ~Queue
template<class T>
Queue<T>::~Queue() 
{
    delete[] queue;
    front = rear = capacity;
}

//IsEmpty
template<class T>
bool Queue<T>::IsEmpty() const
{
    return front == rear;
}

// Front
template<class T>
T& Queue<T>::Front() const
{
    if (IsEmpty()) throw "Queue is empty. No fornt element.";
    return queue[front+1];
}

// Rear
template<class T>
T& Queue<T>::Rear() const 
{
    if (IsEmpty()) throw "Queue is empty. No rear element.";
    return queue[rear];
}

// Push
template<class T>
void Queue<T>::Push(const T& data)
{
    if (rear == capacity - 1) 
    {
        ChangeSize1D(queue, capacity, 2 * capacity);
        capacity *= 2;
    }
    queue[++rear] = data;
}

// Pop
template<class T>
void Queue<T>::Pop() 
{
    if (IsEmpty()) throw "Queue is Empty, Cannot delete";
    for (int i = front+1; i < rear; i++) {
        queue[i] = queue[i + 1];
    }
    rear--;
}

int main()
{
   // test
    int n;
    // Input
    cout << "Size:";
    cin >> n;
    Queue<int> q(n);
    for (int i = 0; i < n; i++) 
    {
        int t;
        cin >> t;
        q.Push(t);
    }
    
    // Output
    cout << "Queue:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << q.Front() << " " << q.Rear() << endl;
        q.Pop();
    }
}
