#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>  // freopen_s ���

int main() {
    // OpenCV �α� ����
    FILE* fp;
    freopen_s(&fp, "nul", "w", stderr);  // stderr ���� (OpenCV �α� ����)

    // �̹��� �ε� (���� ��ο� �ִ� Lenna.png)
    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        // �̹��� �ε� ���� �� 0 ���
        std::cout << "0" << std::endl;
        return -1;
    }

    // �ִ� ȭ�� ��� ���
    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    // ���ڸ� ��� (������ ��Ⱚ)
    std::cout << static_cast<int>(maxVal) << std::endl;

    return 0;
}
