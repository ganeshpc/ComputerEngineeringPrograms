#include<iostream>

using namespace std;

int linearSearch(int* arr, int size, int element);

int main() {
    cout<<"hi"<<endl;
    int arr[] = {12, 34, 56, 23, 1, 5, 34, 12, 65, 12, 34, 56, 12};
    int element = 12;
    int index = linearSearch(arr, sizeof(arr)/sizeof(arr[0]), element);   

    if(index == -1) {
        cout<<"Element not found"<<endl;
    } else {
        cout<<"Element "<<element<<" found at index "<<index<<endl;
    }
}

int linearSearch(int* arr, int size, int element) {
    
    for(int i = 0; i<size; i++){
        if(arr[i] == element) {
            return i;
        }
    }

    return -1;
}