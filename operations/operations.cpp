//
// Created by deck on 2/25/24.
//

#include "operations.h"

Matrix inverse(const Matrix &m) {
    int n = m.Size();

    Matrix I = Matrix(m.Size());
    Matrix A = Matrix(m);

    I.SetIdentity();

    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];
        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
            I[i][j] /= pivot;
        }

        for (int row = 0; row < n; row++) {
            if (row != i) {
                double factor = A[row][i];
                for (int col = 0; col < n; col++) {
                    A[row][col] -= factor * A[i][col];
                    I[row][col] -= factor * I[i][col];
                }
            }
        }
    }

    return I;
}

Matrix inverse_parallel(const Matrix &m, int threads) {
    const int n = m.Size();

    Matrix I = Matrix(m.Size());
    Matrix A = Matrix(m);

    I.SetIdentity();

    omp_set_num_threads(threads);

#pragma omp parallel for shared(A,I) firstprivate(n)
    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];

#pragma omp parallel for shared(A,I) firstprivate(n)
        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
            I[i][j] /= pivot;
        }

#pragma omp parallel for shared(A,I) firstprivate(n)
        for (int row = 0; row < n; row++) {
            if (row != i) {
                double factor = A[row][i];

#pragma omp parallel for shared(A,I) firstprivate(n)
                for (int col = 0; col < n; col++) {
                    A[row][col] -= factor * A[i][col];
                    I[row][col] -= factor * I[i][col];
                }
            }
        }
    }

    return I;
}

Matrix production(const Matrix& A, const Matrix& B) {
    Matrix C = Matrix(A.Size());
    C.SetEmpty();

    for (int i = 0; i < A.Size(); i++) {
        for (int j = 0; j < B.Size(); j++) {
            for (int k = 0; k < C.Size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}
