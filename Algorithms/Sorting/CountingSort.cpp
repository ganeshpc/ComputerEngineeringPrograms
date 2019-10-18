#include<iostream>

using namespace std; 

void printArray(int* arr, int size);
void zeroArray(int* arr, int size);
void countElements(int* arr, int* countArray, int arrSize, int countArraySize);
void sortArray(int* arr, int* countArray, int size, int countArraySize, int* sortedArray);

int main() {
    int arr[] = {5, 1, 4, 1, 5, 2, 6, 7, 3, 7, 0, 0, 3, 5, 3, 6, 5, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sortedArray[size];
    cout<<"Size: "<<size<<endl;
    int countArray[10];

    countElements(arr, countArray, size, 10);

    printArray(arr, size);

    sortArray(arr, countArray, size, 10, sortedArray);

    printArray(sortedArray, size);

}

void printArray(int* arr, int size) {
    for (int i = 0; i<size; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void zeroArray(int* arr, int size) {
    for (int i = 0; i<size; i++) {
        arr[i] = 0;
    }
}

void countElements(int* arr, int* countArray, int arrSize, int countArraySize) {
    zeroArray(countArray, countArraySize);

    for (int i = 0; i<arrSize; i++) {
        countArray[arr[i]]++;
    }

    for (int i = 1; i<countArraySize; i++) {
        countArray[i] = countArray[i-1] + countArray[i];
    }
    printArray(countArray, countArraySize);
}

void sortArray(int* arr, int* countArray, int size, int countArraySize, int* sortedArray) {

    for (int i = size-1; i>=0; i--) {
        sortedArray[countArray[arr[i]]] = arr[i];
        countArray[arr[i]]--;
    }
}