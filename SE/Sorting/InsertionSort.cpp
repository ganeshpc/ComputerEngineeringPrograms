#include<iostream>

using namespace std;

void insertionSort(int* arr, int size);
void swap(int* arr, int i, int j);
void swapRight(int* arr, int index);
void printArray(int* arr, int size);

int main() {
    int arr[] = {12, 12, 29, 73, 121, 43, 56, 10, 34, 2, 76};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);
    printArray(arr, size);
}

void insertionSort(int* arr, int size) {
    for(int i = 0; i<size; i++) {
        int unsortedElement = arr[i];
        int finalPos = i;
        for(int j = i-1; j>=0; j--) {
            if(arr[j] > unsortedElement) {
                swapRight(arr, j);
                finalPos = j;
            }
        }
        arr[finalPos] = unsortedElement;
    }
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swapRight(int* arr, int index) {
    arr[index+1] = arr[index];
}

void printArray(int* arr, int size){
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}