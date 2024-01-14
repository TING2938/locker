#include "pch.h"

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    os << "{";
    if (!vec.empty()) {
        os << vec[0];
    }
    for (int i = 1; i < vec.size(); i++) {
        os << ", " << vec[i];
    }
    os << "}";
    return os;
}