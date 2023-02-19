#include <iostream>
#include <string.h>
using namespace std;

template<class T>
class chain;

template<class T>
class chainNode 
{
    friend class chain<T>;
private:
    T data;
    chainNode<T>* link;
public:
    chainNode();
    chainNode(const T& data);
    chainNode(const T& data, chainNode<T>* link);
};

template<class T>
chainNode<T>::chainNode()
{
    data = -1;     // default
    link = NULL;
}

template<class T>
chainNode<T>::chainNode(const T& data) 
{
    this->data = data;
    this->link = NULL;
}

template<class T>
chainNode<T>::chainNode(const T& data, chainNode<T>* link) 
{
    this->data = data;
    this->link = link;
}

template<class T>
class chain {
private:
    chainNode<T>* first;
public:
    chain();
    chain(const T& data);
    chain(const T& data, chainNode<T>* link);
    ~chain();
    bool IsEmpty() const;
    int IndexOf(const T& theElement) const;
    void Delete(int IndexOf);
    void Insert(int theIndex, const T& theElement);
};

template<class T>
chain<T>::chain() 
{
    first = new chainNode<T>();
}
template<class T>
chain<T>::chain(const T& data) 
{
    first = new chainNode<T>(data);
}

template<class T>
chain<T>::chain(const T& data, chainNode<T>* link) 
{
    first = new chainNode<T>(data, link);
}

template<class T>
chain<T> ::~chain()
{
    while (first != NULL) {
        chainNode<T>* next = first->link;
        delete first;
        first = next;
    }
}

template<class T>
bool chain<T>::IsEmpty() const 
{
    return first == NULL;
}

template<class T>
int chain<T>::IndexOf(const T& theElement) const 
{
    chainNode<T>* currentNode = first;
    int index = 0;
    while (currentNode->data != theElement) 
    {
        currentNode = currentNode->link;
        index++;
    }
    if (currentNode == NULL) return -1;
    else return index;
}

template<class T>
void chain<T>::Delete(int theIndex) 
{
    chainNode<T>* deleteNode;
    if (theIndex == 0) 
    {
        deleteNode = first;
        first = first->link;
    }
    else 
    {
        chainNode<T> *temp = first;
        for (int i = 1; i < theIndex; i++) 
        {
            temp = temp->link;
        }
        deleteNode = temp->link;
        temp ->link = temp->link->link;
    }
    delete deleteNode;
}

template<class T>
void chain<T>::Insert(int theIndex, const T& theElement) 
{
    if (theIndex == 0) first = new chainNode<T>(theElement);
    chainNode<T>* temp = first;
    for (int i = 1; i < theIndex; i++)
        temp = temp->link;
    temp->link = new chainNode<T>(theElement, temp->link);
}

int main()
{
    // test
    chain<int> l;

    // Insert
    cout << "Insert:\n";
    l.Insert(1, 1);
    l.Insert(2, 2);
    cout << l.IndexOf(2) << endl;
    
    // Delete
    cout << "Delete:\n";
    l.Delete(1);
    cout << l.IndexOf(2) << endl;
}
