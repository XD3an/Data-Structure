#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

// Max Heap
template<class T>
class MaxHeap {
private:
    T* heap;                    // heap array
    int size;                   // size
    int capacity;               // capacity
public:
    MaxHeap(int capacity = 10) {                                        // constructor MaxHeap
        this->capacity = capacity;
        size = 0;
        heap = new T[capacity + 1];
    }
    // Operations
    void ChangeSize1D(T*& a, const int oldSize, const int newSize);     // ChangeSize1D
    void push(T data);                                                  // push
    void pop();                                                         // pop                                       
    bool IsEmpty();                                                     // IsEmpty
    T top();                                                            // top 
};

template<class T>
void MaxHeap<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize) {
    T* temp = new T[newSize];                                           // If capacity was not enough,  change the size of the array.
    int number = min(oldSize, newSize);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

template<class T>
void MaxHeap<T>::push(T data) {
    if (size == capacity) {                                             // If size = capacity,
        ChangeSize1D(heap, capacity, 2 * capacity);                         // then change the size of array.
        capacity *= 2;
    }
    int current = ++size;                                               // Declring current to save the position of the current node .
    while (current != 1 && heap[current / 2] < data) {                      // find position
        // bubble up
        heap[current] = heap[current / 2];
        current /= 2;
    }
    heap[current] = data;                                               // Saving the data in heap array.
}

template<class T>
void MaxHeap<T>::pop() {
    T lastData = heap[size--];                                      // Declaring lastData to save the last data.
    int current = 1;                                                    // Declaring current to save the position of the current node.
    int child = 2;                                                      // Declaring child to save the position of the current node.          
    while (child <= size) {                                             // find position
        if (child < size && heap[child] < heap[child + 1]) child++;
        if (lastData >= heap[child]) break;
        heap[current] = heap[child];
        current = child *= 2;
    }
    heap[current] = lastData;                                       // Saving the data in  heap array.
}

template<class T>
bool MaxHeap<T>::IsEmpty() {                                            // Returnning whether it is empty. 
    if (size == 0) return true;                                             // If size  =  0, then return true.
    else return false;                                                      // Else, then return false.
}

template<class T>
T MaxHeap<T>::top() {                                                   // Returnning the top data.
    return heap[1];
}


int main()
{
    MaxHeap<int> heap;
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