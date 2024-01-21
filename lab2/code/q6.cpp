// TIME COMPLEXITY :- O(N*Log(N)); Avarage complexity ,O(N*N*Log(N)) Worst Case
// SPACE COMPLEXITY :- O(1);

#include<bits/stdc++.h>
using namespace std;

int partition(int left, int right, int arr[]) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int MedianElement(int left, int right, int k, int arr[]) {
    int pivotIndex = partition(left, right, arr);

    if (pivotIndex - left == k - 1) {
        return pivotIndex;
    } else if (pivotIndex - left > k - 1) {
        return MedianElement(left, pivotIndex - 1, k, arr);
    }

    return MedianElement(pivotIndex + 1, right, k - pivotIndex + left - 1, arr);
}

void quickSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int k = (right - left + 2) / 2;
    int mid = MedianElement(left, right, k, arr);
    int pivot = arr[mid];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot && j != mid) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    arr[i] = pivot;

    quickSort(arr, left, mid);
    quickSort(arr, mid + 1, right);
}

int main() {
    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    int array[size];
    
    cout << "Enter elements of the array" << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    
    quickSort(array, 0, size - 1); // function call
    cout << "Array after sorting is :" << endl;
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    
    cout << endl;
    return 0;
}
