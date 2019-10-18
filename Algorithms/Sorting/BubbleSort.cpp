#include<iostream>

using namespace std;

void bubbleSort(int* arr, int size);
void optimisedBubbleSort(int* arr, int size);
void swap(int *arr, int i, int j);
void printArray(int* arr, int size);

int main() {
    int arr[] = {12, 12, 29, 73, 121, 43, 56, 10, 34, 2, 76};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);
    // optimisedBubbleSort(arr, size);
    printArray(arr, size);
}

void bubbleSort(int* arr, int size) {
    for(int i = 0; i<size; i++) {
        for(int j = 0; j<size-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
            }
        }
    }
}

void optimisedBubbleSort(int* arr, int size) {
    for(int i = 0; i<size; i++) {
        bool isSwaped = false;
        cout<<"hi"<<endl;
        for(int j = 0; j<size-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
                isSwaped = true;
            }
        }
        if(!isSwaped) break;
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