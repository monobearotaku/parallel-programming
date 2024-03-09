//
// Created by deck on 2/25/24.
//

#include <chrono>
#include <ctime>

#include "matrix.h"
#include "operations.h"

int main() {
    srand(time(NULL));

    int n = 0;

    std::cin >> n;

    Matrix a = Matrix(n);
    a.SetRandom();
    // std::cout<<a;

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




    // std::cout<<b;

    //
    // Matrix a = Matrix(5);
    // a.SetRandom();
    // std::cout<<a;
    //
    // Matrix b = inverse(a);
    // std::cout<<b;
    //
    //
    // Matrix c = production(a, b);
    // std::cout<<c;
}