#include <iostream>

using namespace std;


void swap(int& val1, int& val2){
    int temp = val1;
    val1 = val2;
    val2 = temp;
};

void partition(int array[], int left,  int right, int& pivot_index){
    int pivot = array[pivot_index];

    int leftPointer = left, rightPointer = right;

    while (leftPointer < rightPointer){

        while(array[leftPointer] <= pivot && leftPointer < rightPointer){
            leftPointer++;
        }
        while(array[rightPointer] >= pivot && leftPointer < rightPointer){
            rightPointer--;
        }
        if (leftPointer < rightPointer){
            swap(array[leftPointer], array[rightPointer]);
        }
    }
    swap(array[leftPointer], array[pivot_index]);

    pivot_index = rightPointer;

};

void quicksort(int data[], int left, int right){
    if (left < right){
        int pivot_index = left;
        partition(data, left, right, pivot_index);
        quicksort(data, left, pivot_index - 1);
        quicksort(data, pivot_index + 1, right);
    };
};

int main() {
    int array[] = {3, 5, 4, 9, 0};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Before Sort: " << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    quicksort(array, 0, size - 1);

    cout << "After Sort: " << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

