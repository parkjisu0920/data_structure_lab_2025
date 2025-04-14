#include <iostream>

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int size;
    std::cout << "배열의 크기를 입력하세요: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << size << "개의 정수를 입력하세요:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int maxVal = findMax(arr, size);
    std::cout << "최댓값: " << maxVal << std::endl;

    delete[] arr;
    return 0;
}
