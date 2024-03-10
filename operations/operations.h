//
// Created by deck on 2/25/24.
//

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <omp.h>
#include "../matrix/matrix.h"

Matrix inverse(const Matrix& m);
Matrix inverse_parallel(const Matrix& m, int threads);

Matrix production(const Matrix& A, const Matrix& B);

#endif //OPERATIONS_H
