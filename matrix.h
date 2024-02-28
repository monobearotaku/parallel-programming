//
// Created by deck on 2/25/24.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>

class Row {
public:
    Row();
    explicit Row(int n);
    Row(const Row& r);
    double& operator [](int index);
    double operator [](int index) const;

    void SetEmpty();
    void SetRandom();

    [[nodiscard]] int Size() const;

    ~Row();

private:
    std::vector<double> row;

};

std::ostream& operator <<(std::ostream& os, const Row& r);

class Matrix {
public:
    Matrix();
    explicit Matrix(int n);
    Matrix(const Matrix& m);
    Row& operator [](int index);
    Row operator [](int index) const;

    void SetEmpty();
    void SetIdentity();
    void SetRandom();

    [[nodiscard]] int Size() const;

    ~Matrix();

private:
    std::vector<Row> matrix;
};

std::ostream& operator <<(std::ostream& os, const Matrix& m);


#endif //MATRIX_H
