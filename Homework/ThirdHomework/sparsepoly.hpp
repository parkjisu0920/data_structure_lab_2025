#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <iostream>
#include <vector>

class SparsePoly {
    int numTerms;
    std::vector<int> exponents;
    std::vector<float> coefficients;

public:
    // 생성자
    SparsePoly() : numTerms(0) {}

    // 다항식 입력 함수
    void read();

    // 다항식 출력 함수
    void display(const char* str);

    // 다항식 덧셈 함수
    void add(SparsePoly a, SparsePoly b);
};

#endif
