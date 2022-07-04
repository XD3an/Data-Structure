#include <bits/stdc++.h>
using namespace std;


void merge(int arr[], int l, int m, int r);

int min(int x, int y) { return (x<y)? x :y; }

void Merge(unsigned long* initList, unsigned long* mergedList, const int l, const int m, const int n) {
    unsigned long i1, i2, iResult;
    for (i1 = l, iResult = l, i2 = m + 1; i1 <= m && i2 <= n; iResult++) {
        if (initList[i1] <= initList[i2]) {
            mergedList[iResult] = initList[i1];
            i1++;
        }
        else {
            mergedList[iResult] = initList[i2];
        }
    }
    copy(initList + i1, initList + m + 1, mergedList + iResult);
    copy(initList + i2, initList + n + 1, mergedList + iResult);
}

void MergePass(unsigned long* initList, unsigned long* resultList, const int n, const int s) {
    int i;
    for (i = 1; i <= n - 2 * s + 1; i += 2 * s) {
        Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
    }
    if ((i + s - 1) < n) Merge(initList, resultList, i, i + s - 1, n);
    else copy(initList + i, initList + n + 1, resultList + i);
}

void mergeSort(unsigned long* a, const int n) {
    unsigned long* tempList = new unsigned long[n + 1];
    for (int l = 1; l < n; l *= 2) {
        MergePass(a, tempList, n, l);
        l *= 2;
        MergePass(tempList, a, n, l);
    }
    delete[] tempList;
}


void printArray(unsigned long *arr, int size){
	int i;
	for (i=0; i < size; i++)
		cout <<" "<< arr[i];
	cout <<"\n";
}


// Recursive
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void Merge(unsigned long *array, const int left, const int mid, const int right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void MergeSort(unsigned long  *array, const int begin, const int end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
}







int main()
{
	/* 
	unsigned long  arr[] = {26,5,77,1,61,11,59,15,48,19};
	unsigned int n = sizeof(arr)/sizeof(arr[0]);	

	cout <<"Given array is \n ";
	printArray(arr, n);

	//mergeSort(arr, n);
	MergeSort(arr, 0, n-1);
	cout <<"\nSorted array is \n ";
	printArray(arr, n);
	*/ 
	return 0;

}

