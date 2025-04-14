#include <iostream>
#include <vector>
#include "sparsepoly.hpp"

using namespace std;

int main() {
    // 희소 다항식 A와 B 생성
    SparsePoly A;
    SparsePoly B;

    // 다항식 A 입력 후 확인
    A.read();
    A.display("Poly A: ");

    // 다항식 B 입력 후 확인
    B.read();
    B.display("Poly B: ");

    // A와 B를 더한 값을 C에 저장 후 확인
    SparsePoly C;
    C.add(A, B);
    C.display("Poly C: ");

    return 0;
}

// 다항식 입력 함수 구현
void SparsePoly::read() {
    cout << "항의 개수를 입력하세요 : ";
    cin >> numTerms;

    int expo;
    float coef;
    for (int i = 0; i < numTerms; ++i) {
        cout << i + 1 << "번 째 항의 계수와 차수를 입력하세요 (예 : 계수 차수) : ";
        cin >> coef >> expo;
        if (coef != 0) {
            coefficients.push_back(coef);
            exponents.push_back(expo);
        }
    }
    numTerms = coefficients.size(); // 0이 아닌 항 수만 저장
}

// 다항식 출력 함수 구현
void SparsePoly::display(const char* str) {
    cout << str;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        cout << coefficients[i] << "x^" << exponents[i];
        if (i != coefficients.size() - 1)
            cout << " + ";
    }
    cout << endl;
}

// 다항식 덧셈 함수 구현
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
