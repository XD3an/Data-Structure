#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Insertion_Sort(int arr[], const int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		// cout << "Round " << i << " : ";
		// print(arr, n);
	}
}


int main()
{
	/* 
	int arr[] = {26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
	Insertion_Sort(arr, 10);
	*/ 
}

