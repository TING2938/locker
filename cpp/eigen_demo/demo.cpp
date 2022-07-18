#include <Eigen/Dense>
#include <iostream>

using Eigen::all;
using Eigen::ArrayXXd;
using Eigen::last;
using Eigen::MatrixXd;
using Eigen::seq;
using Eigen::seqN;
using DataMap = Eigen::Map<Eigen::ArrayXXd>;

int main()
{
    // 1. basic operation
    ArrayXXd m(7, 5);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);

    // 2. block operation
    m(seq(0, 5, 2), last / 2) = 5.67;
    m(last, seqN(1, 2))       = 7.89;
    m({1, 3, 4}, last - 1)    = 8.90;
    std::cout << m << std::endl;

    // 3. rowwise/colwise operation
    std::cout << m.rowwise().maxCoeff() << std::endl;

    // 4. Map of raw data
    double raw_array[6] = {0, 1, 2, 3, 4, 5};
    DataMap raw_array_map(raw_array, 2, 3);
    raw_array_map(1, {0, 2}) = 5.4;
    std::cout << "raw_array: ";
    for (auto&& i : raw_array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
