#include <algorithm>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include "kernel/cu_func.cuh"
#include "matrix.h"
#include "timer.hpp"

void vector_add_test()
{
    int N = 1 << 20;
    std::vector<float> x(N, 1.5);
    std::vector<float> y(N, 2.2);
    std::vector<float> z(N, 1.0);

    vectorAdd(x.data(), y.data(), z.data(), N);

    float maxError = 0.0;
    for (int i = 0; i < N; i++)
        maxError = std::max(maxError, std::abs(z[i] - 3.7f));
    std::cout << "最大误差: " << maxError << std::endl;
}

void matrix_op_test()
{
    int N = 1 << 5;
    Matrix x(N, N);
    Matrix y(N, N);
    std::iota(x.data, x.data + N * N, 1);
    std::iota(y.data, y.data + N * N, 1);
    ct::Timeit timer;


    timer.start();
    Matrix cu_z(N, N);
    matrixMulti(x.data, y.data, cu_z.data, x.nrow, y.ncol, x.ncol);
    timer.stop();
    timer.printSpan("cuda: ", "\n");

    timer.start();
    auto z = x * y;
    timer.stop();
    timer.printSpan("normal: ", "\n");

    std::cout << z;
    std::cout << "===============\n";
    std::cout << cu_z;
}

int main()
{
    matrix_op_test();
}