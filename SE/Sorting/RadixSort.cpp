#include<iostream>

using namespace std; 

void radixSort(int* arr, int size);
int getMax(int* arr, int size);
void countingSort(int* arr, int size, int exponent);
void zeroArray(int* arr, int size);
void printArray(int* arr, int size);

int main() {
    int arr[] = {12, 12, 29, 73, 121, 43, 56, 10, 34, 5786, 2, 76, 67, 23, 345, 236};

    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Size: "<<size<<endl;
    printArray(arr, size);
    radixSort(arr, size);
    printArray(arr, size);
}

void radixSort(int* arr, int size) {
    int max = getMax(arr, size);
    for (int i = 1; max/i > 0; i *= 10) {
        countingSort(arr, size, i);
    }
}

int getMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 0; i<size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int* arr, int size, int exponent) {
    int count[10];
    
    zeroArray(count, 10);
    
    for (int i = 0; i<size; i++) {
        count[((arr[i]/exponent)%10)]++;
    }

    for (int i = 1; i<10; i++) {
        count[i] = count[i] + count[i-1];
    }
    
    int sortedArray[size];
    for (int i = size-1; i>=0; i--) {
        sortedArray[count[(arr[i]/exponent)%10]-1] = arr[i];
        count[(arr[i]/exponent)%10]--;
    }

    for (int i = 0; i<size; i++) {
        arr[i] = sortedArray[i];
    }
}

void zeroArray(int* arr, int size) {
    for (int i = 0; i<size; i++) {
        arr[i] = 0;
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i<size; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
