//
// Created by deck on 2/25/24.
//

#include "matrix.h"

Row::Row() {
    this->row = std::vector<double>();
}

Row::Row(int n) {
    this->row = std::vector<double>(n);
}

Row::Row(const Row &r) {
    this->row = std::vector<double>(r.Size());

    for (auto it = r.row.begin(); it != r.row.end(); it++) {
        this->row[std::distance(r.row.begin(), it)] = *it;
    }
}

double & Row::operator[](int index) {
    return this->row[index];
}

double  Row::operator[](int index) const{
    return this->row[index];
}

void Row::SetEmpty() {
    for (double & it : this->row) {
        it = 0;
    }
}

void Row::SetRandom() {
    for (double & it : this->row) {
        it = (rand() % 99) + ((rand() % 99) / 100.);
    }
}

int Row::Size() const {
    return this->row.size();
}

Row::~Row() {
    this->row.clear();
}

std::ostream & operator<<(std::ostream &os, const Row &r) {
    os << "|";

    os << std::fixed << std::setw(10) << std::setprecision(4);

    for (int i = 0; i < r.Size() - 1; i++) {
        os << std::setw(10)  << r[i] << ", ";
    }
    os << std::setw(10) << r[r.Size() - 1];
    os << "|";

    return os;
}

Matrix::Matrix() {
    this->matrix = std::vector<Row>();
}


Matrix::Matrix(int n) {
    this->matrix = std::vector<Row>(n);

    for (int i = 0; i < n; i++) {
        this->matrix[i] = Row(n);
    }
}

Matrix::Matrix(const Matrix &m) {
    this->matrix = std::vector<Row>(m.Size());

    for (int i = 0; i < m.Size(); i++) {
        this->matrix[i] = m[i];
    }
}

Row & Matrix::operator[](int index) {
    return this->matrix[index];
}

Row  Matrix::operator[](int index) const {
    return this->matrix[index];
}

void Matrix::SetEmpty() {
    for (auto& it : this->matrix) {
        it.SetEmpty();
    }
}

void Matrix::SetIdentity() {
    for (int i = 0; i < this->Size(); i++) {
        this->matrix[i][i] = 1;
    }
}

void Matrix::SetRandom() {
    for (auto& it : this->matrix) {
        it.SetRandom();
    }
}

int Matrix::Size() const {
    return this->matrix.size();
}

Matrix::~Matrix() {
    this->matrix.clear();
}

std::ostream & operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i < m.Size(); i++) {
        os << "------------";
    }
    os<<std::endl;

    for (int i = 0; i < m.Size(); i++) {
        os << m[i]<<std::endl;;
    }
    for (int i = 0; i < m.Size(); i++) {
        os << "------------";
    }
    os<<std::endl;

    return os;
}


