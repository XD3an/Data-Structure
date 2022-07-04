#include <iostream>
using namespace std;

void swap(int* e1, int* e2) {
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
void Selection_Sort(int arr[], const int n) {
    int i, j, min_index;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
        // cout << "Round " << i+1 << " : ";
        print(arr, n);
    }
}

int main()
{
	/* 
    int arr[] = {26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
    Selection_Sort(arr, 10);
	*/ 
}
