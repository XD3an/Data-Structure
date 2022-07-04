#include <iostream>
using namespace std;

void swap(int *e1, int *e2) {
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}
void print(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void Bubble_Sort(int arr[], const int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        cout << i << endl;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
            // print(arr, n);
        }
        // cout << endl;
    }
}

int main()
{
	/*
    int arr[] = {26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
    Bubble_Sort(arr, 10);
	*/
}
