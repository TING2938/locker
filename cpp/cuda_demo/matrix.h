#pragma once

#include <cassert>
#include <cmath>
#include <initializer_list>
#include <iomanip>
#include <iostream>

struct Matrix
{
public:
    // layout: row major
    float* data = nullptr;
    int nrow    = 0;
    int ncol    = 0;

public:
    Matrix() = default;
    Matrix(int row, int col) : nrow(row), ncol(col), data(new float[row * col]) {}
    Matrix(std::initializer_list<std::initializer_list<float>> it)
    {
        this->nrow = it.size();
        if (this->nrow != 0) {
            this->ncol = it.begin()->size();
            this->data = new float[this->nrow * this->ncol];
            int p      = 0;
            for (auto&& m : it) {
                for (auto&& n : m) {
                    this->data[p++] = n;
                }
            }
        }
    }

    ~Matrix()
    {
        delete[] this->data;
    }

public:
    const float& operator()(int i, int j) const
    {
        return this->data[i * this->ncol + j];
    }

    float& operator()(int i, int j)
    {
        return this->data[i * this->ncol + j];
    }

    Matrix operator*(const Matrix& mat)
    {
        assert(this->ncol == mat.nrow);
        Matrix ret(this->nrow, mat.ncol);

        for (int i = 0; i < this->nrow; i++) {
            for (int j = 0; j < mat.ncol; j++) {
                float sum = 0.0f;
                for (int m = 0; m < this->ncol; m++) {
                    sum += (*this)(i, m) * mat(m, j);
                }
                ret(i, j) = sum;
            }
        }
        return ret;
    }

    bool operator==(const Matrix& mat)
    {
        if (mat.nrow != this->nrow || mat.ncol != this->ncol) {
            return false;
        }
        for (int i = 0; i < this->nrow; i++) {
            for (int j = 0; j < this->ncol; j++) {
                if (std::abs((*this)(i, j) - mat(i, j)) > 1e-5) {
                    return false;
                }
            }
        }
        return true;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Matrix& mat)
{
    for (int i = 0; i < mat.nrow; i++) {
        for (int j = 0; j < mat.ncol; j++) {
            os << std::setw(5) << mat(i, j) << " ";
        }
        os << '\n';
    }
    return os;
}
