#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>  // freopen_s 사용

int main() {
    // OpenCV 로그 제거
    FILE* fp;
    freopen_s(&fp, "nul", "w", stderr);  // stderr 무시 (OpenCV 로그 제거)

    // 이미지 로드 (같은 경로에 있는 Lenna.png)
    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        // 이미지 로드 실패 시 0 출력
        std::cout << "0" << std::endl;
        return -1;
    }

    // 최대 화소 밝기 계산
    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    // 숫자만 출력 (정수형 밝기값)
    std::cout << static_cast<int>(maxVal) << std::endl;

    return 0;
}
