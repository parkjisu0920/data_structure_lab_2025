#include <iostream>
#include <vector>
#include "sparsepoly.hpp"

using namespace std;

int main() {
    // ��� ���׽� A�� B ����
    SparsePoly A;
    SparsePoly B;

    // ���׽� A �Է� �� Ȯ��
    A.read();
    A.display("Poly A: ");

    // ���׽� B �Է� �� Ȯ��
    B.read();
    B.display("Poly B: ");

    // A�� B�� ���� ���� C�� ���� �� Ȯ��
    SparsePoly C;
    C.add(A, B);
    C.display("Poly C: ");

    return 0;
}

// ���׽� �Է� �Լ� ����
void SparsePoly::read() {
    cout << "���� ������ �Է��ϼ��� : ";
    cin >> numTerms;

    int expo;
    float coef;
    for (int i = 0; i < numTerms; ++i) {
        cout << i + 1 << "�� ° ���� ����� ������ �Է��ϼ��� (�� : ��� ����) : ";
        cin >> coef >> expo;
        if (coef != 0) {
            coefficients.push_back(coef);
            exponents.push_back(expo);
        }
    }
    numTerms = coefficients.size(); // 0�� �ƴ� �� ���� ����
}

// ���׽� ��� �Լ� ����
void SparsePoly::display(const char* str) {
    cout << str;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        cout << coefficients[i] << "x^" << exponents[i];
        if (i != coefficients.size() - 1)
            cout << " + ";
    }
    cout << endl;
}

// ���׽� ���� �Լ� ����
void SparsePoly::add(SparsePoly a, SparsePoly b) {
    int i = 0, j = 0;
    while (i < a.coefficients.size() && j < b.coefficients.size()) {
        if (a.exponents[i] > b.exponents[j]) {
            exponents.push_back(a.exponents[i]);
            coefficients.push_back(a.coefficients[i]);
            ++i;
        }
        else if (a.exponents[i] < b.exponents[j]) {
            exponents.push_back(b.exponents[j]);
            coefficients.push_back(b.coefficients[j]);
            ++j;
        }
        else {
            float sum = a.coefficients[i] + b.coefficients[j];
            if (sum != 0) {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(sum);
            }
            ++i;
            ++j;
        }
    }

    while (i < a.coefficients.size()) {
        exponents.push_back(a.exponents[i]);
        coefficients.push_back(a.coefficients[i]);
        ++i;
    }

    while (j < b.coefficients.size()) {
        exponents.push_back(b.exponents[j]);
        coefficients.push_back(b.coefficients[j]);
        ++j;
    }

    numTerms = coefficients.size();
}
