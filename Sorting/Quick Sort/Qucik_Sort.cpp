#include <iostream>
using namespace std;
/*void swap(int* e1, int* e2) {
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}*/
void print(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    // cout << endl;
}
void QuickSort(int arr[], const int left, const int right) {
    if (left < right) {
        int i = left, j = right + 1, pivot = arr[left];
        do {
            do i++; while (arr[i] < pivot);
            do j--; while(arr[j] > pivot);
            if (i < j) swap(arr[i], arr[j]);
        } while (i < j);
        swap(arr[left], arr[j]);
        // print(arr, 11);
        // cout << "   left : " << left << "  Right : " << right << endl;
        QuickSort(arr, left, j - 1);
        QuickSort(arr, j + 1, right);
    }
}

int main()
{
	/* 
    int arr[] = { 12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};
    QuickSort(arr, 0, 10);
	*/ 
}
