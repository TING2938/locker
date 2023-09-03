#include <device_launch_parameters.h>
#include <iostream>

#include "cu_func.cuh"

// 两个向量加法kernel，grid和block均为一维
__global__ void add_kernel(float* x, float* y, float* z, int N)
{
    // 获取全局索引
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    // 步长
    int stride = blockDim.x * gridDim.x;
    for (int i = index; i < N; i += stride) {
        z[i] = x[i] + y[i];
    }
}

// x: [M, P]
// y: [P, N]
// ret z: [M, N]
__global__ void multi_kernel(float* x, float* y, float* z, int M, int N, int P)
{
    int i1 = blockIdx.x;
    int i2 = threadIdx.x;
    int s1 = (M + gridDim.x - 1) / gridDim.x;
    int s2 = (N + blockDim.x - 1) / blockDim.x;

    for (int i = i1; i < M; i += s1) {
        for (int j = i2; j < N; j += s2) {
            float sum = 0.0f;
            for (int m = 0; m < P; m++) {
                sum += x[i * P + m] * y[m * N + j];
            }
            z[i * M + j] = sum;
        }
    }
}

void vectorAdd(float* x, float* y, float* z, int n)
{
    float* d_x;
    float* d_y;
    float* d_z;
    size_t nBytes = n * sizeof(float);
    cudaMalloc(&d_x, nBytes);
    cudaMalloc(&d_y, nBytes);
    cudaMalloc(&d_z, nBytes);

    cudaMemcpy(d_x, x, nBytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, y, nBytes, cudaMemcpyHostToDevice);

    dim3 blockSize(256);
    dim3 gridSize((n + blockSize.x - 1) / (blockSize.x));
    add_kernel<<<gridSize, blockSize>>>(d_x, d_y, d_z, n);

    cudaMemcpy(z, d_z, nBytes, cudaMemcpyDeviceToHost);

    cudaFree(d_x);
    cudaFree(d_y);
    cudaFree(d_z);
}

// x: [M, P]
// y: [P, N]
// ret z: [M, N]
void matrixMulti(float* x, float* y, float* z, int M, int N, int P)
{
    float* d_x;
    float* d_y;
    float* d_z;

    size_t byte_x = M * P * sizeof(float);
    size_t byte_y = P * N * sizeof(float);
    size_t byte_z = M * N * sizeof(float);

    cudaMalloc(&d_x, byte_x);
    cudaMalloc(&d_y, byte_y);
    cudaMalloc(&d_z, byte_z);

    cudaMemcpy(d_x, x, byte_x, cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, y, byte_y, cudaMemcpyHostToDevice);

    dim3 blockSize(32);
    dim3 gridSize(32);
    multi_kernel<<<gridSize, blockSize>>>(d_x, d_y, d_z, M, N, P);

    cudaMemcpy(z, d_z, byte_z, cudaMemcpyDeviceToHost);

    cudaFree(d_x);
    cudaFree(d_y);
    cudaFree(d_z);
}


int main1()
{
    constexpr int N = 1 << 20;
    int nBytes      = N * sizeof(float);
    // 申请host内存
    float *x, *y, *z;
    x = (float*)malloc(nBytes);
    y = (float*)malloc(nBytes);
    z = (float*)malloc(nBytes);

    // 初始化数据
    for (int i = 0; i < N; ++i) {
        x[i] = 10.0;
        y[i] = 20.0;
    }

    // 申请device内存
    float *d_x, *d_y, *d_z;
    cudaMalloc((void**)&d_x, nBytes);
    cudaMalloc((void**)&d_y, nBytes);
    cudaMalloc((void**)&d_z, nBytes);

    // 将host数据拷贝到device
    cudaMemcpy((void*)d_x, (void*)x, nBytes, cudaMemcpyHostToDevice);
    cudaMemcpy((void*)d_y, (void*)y, nBytes, cudaMemcpyHostToDevice);
    // 定义kernel的执行配置
    dim3 blockSize(256);
    dim3 gridSize((N + blockSize.x - 1) / blockSize.x);
    // 执行kernel
    add_kernel<<<gridSize, blockSize>>>(d_x, d_y, d_z, N);

    // 将device得到的结果拷贝到host
    cudaMemcpy((void*)z, (void*)d_z, nBytes, cudaMemcpyDeviceToHost);

    // 检查执行结果
    float maxError = 0.0;
    for (int i = 0; i < N; i++)
        maxError = fmax(maxError, fabs(z[i] - 30.0));
    std::cout << "最大误差: " << maxError << std::endl;

    // 释放device内存
    cudaFree(d_x);
    cudaFree(d_y);
    cudaFree(d_z);
    // 释放host内存
    free(x);
    free(y);
    free(z);

    return 0;
}

int main2()
{
    int N      = 1 << 20;
    int nBytes = N * sizeof(float);

    // 申请托管内存
    float *x, *y, *z;
    cudaMallocManaged((void**)&x, nBytes);
    cudaMallocManaged((void**)&y, nBytes);
    cudaMallocManaged((void**)&z, nBytes);

    // 初始化数据
    for (int i = 0; i < N; ++i) {
        x[i] = 10.0;
        y[i] = 20.0;
    }

    // 定义kernel的执行配置
    dim3 blockSize(256);
    dim3 gridSize((N + blockSize.x - 1) / blockSize.x);
    // 执行kernel
    add_kernel<<<gridSize, blockSize>>>(x, y, z, N);

    // 同步device 保证结果能正确访问
    cudaDeviceSynchronize();
    // 检查执行结果
    float maxError = 0.0;
    for (int i = 0; i < N; i++)
        maxError = fmax(maxError, fabs(z[i] - 30.0));
    std::cout << "最大误差: " << maxError << std::endl;

    // 释放内存
    cudaFree(x);
    cudaFree(y);
    cudaFree(z);

    return 0;
}
