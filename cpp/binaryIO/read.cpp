#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>


int main()
{
    int nrow = 10;
    int ncol = 12;

    std::vector<int> matrix(nrow * ncol);
    std::iota(matrix.begin(), matrix.end(), 0);

    // write to file
    std::ofstream ofile("test.bin", std::ios::binary);
    ofile.write((char*) matrix.data(), sizeof(int) * nrow * ncol);
    ofile.close();

    // read from file
    std::ifstream ifile("test.bin", std::ios::binary);
    std::vector<int> container(nrow * ncol);
    ifile.read((char*) container.data(), sizeof(int) * nrow * ncol);
    ifile.close();

    std::cout << container[0] << ' ' << container[1] << ' ' << container[2] << std::endl;
}
