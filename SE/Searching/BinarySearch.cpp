#include<iostream>

using namespace std;

int binarySearch(int* arr, int size, int element);

int binarySearchRecursion(int* arr, int start, int stop, int element);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int element = -1;
    int index = binarySearch(arr, sizeof(arr) / sizeof(arr[0]), element);

    //binary search using recursion 
    int indexRecursion = binarySearchRecursion(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, element);

    if(index == -1) {
        cout<<"Element not found"<<endl;
    } else {
        cout<<"Element "<<element<<" found at index "<<indexRecursion<<endl;
    }
}

int binarySearch(int* arr, int size, int element) {
    
    int firstIndex = 0;
    int lastIndex = size-1;
    while(firstIndex <= lastIndex) {
        int center = (firstIndex + lastIndex) / 2;
        if(arr[center] < element){
            firstIndex = center+1;
        } else if(arr[center] > element) {
            lastIndex = center-1;
        } else {
            return center;
        }
    }

    return -1;
}

int binarySearchRecursion(int* arr, int start, int stop, int element) {
    
    if (start > stop) {
        return -1;
    }

    int center = (start + stop) / 2;

    if(arr[center] < element) {
        start = center + 1;
    } else if (arr[center] > element) {
        stop = center - 1;
    } else {
        return center;
    }

    return binarySearchRecursion(arr, start, stop, element);
}

