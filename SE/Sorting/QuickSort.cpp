#include<iostream>

using namespace std;

void quickSort(int* arr, int left, int right);
void swap(int* arr, int i, int j);
void printArray(int* arr, int size);

int main() {
    int arr[] = {12, 11, 29, 73, 121, 43, 56, 10, 34, 2, 76};
    int size = sizeof(arr) / sizeof(arr[0]);


    quickSort(arr, 0, 10);
    printArray(arr, size);
}

void quickSort(int* arr, int left, int right) {
    if(!(left < right)) return;
    int pivot = left;

    int i = left+1, j = left;

    while(i <= right) {
        if (arr[i] < arr[pivot]) {
            j++;
            swap(arr, j, i);
        }
        i++;
    }
    swap(arr, j, pivot);
    quickSort(arr, left, j-1);
    quickSort(arr, j+1, right);
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printArray(int* arr, int size){
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}