#include <iostream>
#include <vector>

void merge(std::vector<int>& data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = data[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = data[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            data[k] = leftArray[i];
            i++;
        } else {
            data[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);

        merge(data, left, mid, right);
    }
}

int main() {
    std::vector<int> array;
    array.push_back(3);
    array.push_back(5);
    array.push_back(4);
    array.push_back(9);
    array.push_back(0);

    std::cout << "Before Sort: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(array, 0, array.size() - 1);

    std::cout << "After Sort: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
