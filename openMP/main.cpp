//
// Created by deck on 2/25/24.
//

#include <chrono>
#include <ctime>

#include "../matrix/matrix.h"
#include "operations.h"

int main() {
    srand(time(nullptr));

    int n = 0;

    std::cout << "Please provide size of matrix: ";
    std::cin >> n;

    Matrix a = Matrix(n);
    a.SetRandom();

    auto start = std::chrono::high_resolution_clock::now();
    Matrix b = inverse(a);
    auto stop = std::chrono::high_resolution_clock::now();

    std::cout<<"Serial: "<<std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()<<std::endl;

    for (int i = 2; i <=8; i++) {
        start = std::chrono::high_resolution_clock::now();
        b = inverse_parallel(a, i);
        stop = std::chrono::high_resolution_clock::now();

        std::cout<<"Parallell "<<i<<" threads: "<<std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()<<std::endl;
    }
}