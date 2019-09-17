#include<iostream>

using namespace std;

void mergeSort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);
void printArray(int* arr, int size);

int main() {
    int arr[] = {12, 11, 29, 73, 121, 43, 56, 10, 34, 2, 76};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size-1);

    printArray(arr, size);
}

void mergeSort(int* arr, int left, int right) {
    int mid;
    if(left < right) {
        mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int* arr, int left, int mid, int right) {
    int newSorted[right - left + 1];

    int counter = 0, leftCounter = left, rightCounter = mid+1;
    
    while(leftCounter <= mid && rightCounter <= right) {
        if(arr[leftCounter] < arr[rightCounter]) {
            newSorted[counter] = arr[leftCounter];
            leftCounter++;
        } else {
            newSorted[counter] = arr[rightCounter];
            rightCounter++;
        }
        counter++;
    }

    while(leftCounter <= mid) {
        newSorted[counter] = arr[leftCounter];
        leftCounter++;
        counter++;
    }

    while (rightCounter <= right) {
        newSorted[counter] = arr[rightCounter];
        rightCounter++;
        counter++;
    }
    
    for(counter = 0; counter < right - left + 1; counter++) {
        arr[left + counter] = newSorted[counter];
    }
}

void printArray(int* arr, int size){
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}