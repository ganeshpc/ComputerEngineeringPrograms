#include<iostream>

using namespace std;

void selectionSort(int* arr, int size);
void swap(int* arr, int i, int j);
void printArray(int* arr, int size);

int main() {
    int arr[] = {12, 12, 29, 73, 121, 43, 56, 10, 34, 2, 76};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);
    printArray(arr, size);
}

void selectionSort(int* arr, int size) {
    for(int i = 0; i<size; i++) {
        int min = i;
        for(int j = i; j<size; j++) {
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr, min, i);
    }
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