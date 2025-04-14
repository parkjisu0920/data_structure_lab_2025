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
    std::cout << "�迭�� ũ�⸦ �Է��ϼ���: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << size << "���� ������ �Է��ϼ���:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int maxVal = findMax(arr, size);
    std::cout << "�ִ�: " << maxVal << std::endl;

    delete[] arr;
    return 0;
}
