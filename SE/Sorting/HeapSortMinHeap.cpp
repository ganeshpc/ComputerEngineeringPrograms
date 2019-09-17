#include<iostream>

using namespace std;

void swap(int* arr, int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void hepify(int* arr, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index +2;

    if (arr[left] < arr[smallest] && left < size) {
        smallest = left;
    }

    if (arr[right] < arr[smallest] && right < size) {
        smallest = right;
    }

    if (smallest != index) {
        swap(arr, index, smallest);
        hepify(arr, size, smallest);
    }

}

void heapSort(int* arr, int size) {
    for (int i = size/2; i>=0; i--) {
        hepify(arr, size, i);
    }

    for (int i = 0; i<size; i++) {
        swap(arr, 0, size-i-1);
        hepify(arr, size-i-1, 0);
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i<size; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {12, 12, 29, 73, 121, 43, 56, 10, 34, 2, 76};

    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, size);
    printArray(arr, size);
}