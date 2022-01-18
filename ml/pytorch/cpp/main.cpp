#include <torch/torch.h>
#include <iostream>

int main() 
{
    torch::Tensor tensor = torch::eye(3);
    std::cout << tensor << std::endl;
}
// 输入如下：
// 1  0  0
// 0  1  0
// 0  0  1
// [ CPUFloatType{3,3} ]

