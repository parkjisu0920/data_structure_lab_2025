#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <iostream>
#include <vector>

class SparsePoly {
    int numTerms;
    std::vector<int> exponents;
    std::vector<float> coefficients;

public:
    // ������
    SparsePoly() : numTerms(0) {}

    // ���׽� �Է� �Լ�
    void read();

    // ���׽� ��� �Լ�
    void display(const char* str);

    // ���׽� ���� �Լ�
    void add(SparsePoly a, SparsePoly b);
};

#endif
