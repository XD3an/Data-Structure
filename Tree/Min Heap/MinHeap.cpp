#include <iostream>
#include <algorithm>
#include <string>
#include <time.h>
using namespace std;

// Max Heap
template<class T>
class MinHeap {
private:
    T* heap;                                                            
    int size;                                                           
    int capacity;                                                       
public:
    MinHeap(int capacity = 10)                                                  // constructor MinHeap
    {                                        
        this->capacity = capacity;
        size = 0;
        heap = new T[capacity + 1];
    }
    void ChangeSize1D(T*& a, const int oldSize, const int newSize);              // ChangeSize1D
    void push(T data);                                                           // push
    void pop();                                                                  // pop
    bool IsEmpty();                                                              // IsEmpty
    T top();                                                                     // top
};

template<class T>
void MinHeap<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize)       // If capacity was not enough,  change the size of the array.
{     
    T* temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

template<class T>
void MinHeap<T>::push(T data) 
{
    if (size == capacity)                                                       // If size = capacity,
    {                                             
        ChangeSize1D(heap, capacity, 2 * capacity);                             // then change the size of array.
        capacity *= 2;
    }
    int current = ++size;                                                       // Declring current to save the position of the current
    while (current != 1 && heap[current / 2] > data)                            // find position
    {                          
        //bubble up
        heap[current] = heap[current / 2];
        current /= 2;
    }
    heap[current] = data;                                                       // Saving the data in heap array.
}

template<class T>
void MinHeap<T>::pop() 
{
    T lastData = heap[size--];
    int current = 1;
    int child = 2;                                                              // Declaring lastData to save the last data.
    while (child <= size)                                                       // Declaring current to save the position of the current node.
    {                                                    
        if (child < size && heap[child] > heap[child + 1]) child++;             // Declaring child to save the position of the current node.          
        if (lastData <= heap[child]) break;                                     // find position
        heap[current] = heap[child];
        current = child *= 2;
    }
    heap[current] = lastData;                                                   // Saving the data in  heap array.         
}

template<class T>
bool MinHeap<T>::IsEmpty()                                                      // Returnning whether it is empty. 
{                
    if (size == 0) return true;
    else return false;
}

template<class T>
T MinHeap<T>::top()                                                             // Returnning the top data.
{                       
    if (!IsEmpty())
        return heap[1];
}


int main()
{
    // test
    MinHeap<int> heap;
    for (int i = 0; i < 1; i++) {
        heap.push(10);
        heap.push(6);
        heap.push(8);
        heap.push(7);
        heap.push(15);
        heap.push(3);
        heap.push(9);
        heap.push(13);
        heap.push(12);
        heap.push(5);
        heap.push(14);
        heap.push(16);
        cout << "top : " << heap.top() << endl << endl;
    }
    return 0;
}
