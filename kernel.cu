
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include<cusparse.h>
#include<vector>
#include<iostream>
using namespace std;

void checkCudaError(cudaError_t err, const char* msg)
{
	if (err != cudaSuccess)
	{
		cerr << "CUDA error: " << msg << " - " << cudaGetErrorString(err) << endl;
		exit(EXIT_FAILURE);
	}
}

void checkCusparseError(cusparseStatus_t status, const char* msg)
{
	if (status != CUSPARSE_STATUS_SUCCESS)
	{
		cerr << "cuSPARSE error: " << msg << endl;
		exit(EXIT_FAILURE);
	}
}
int main() {
    // Example matrix in dense form (4x4)
    std::vector<float> denseMatrix = {
        1.0, 0.0, 2.0, 0.0,
        0.0, 3.0, 0.0, 0.0,
        0.0, 0.0, 4.0, 5.0,
        0.0, 6.0, 0.0, 0.0
    };
    const int rows = 4, cols = 4;
    const int nnz = 6; // Number of non-zero elements

    // Dense vector
    std::vector<float> denseVector = { 1.0, 2.0, 3.0, 4.0 };

    // Result vector
    std::vector<float> result(rows, 0.0);

    // Device memory pointers
    float* d_denseMatrix, * d_denseVector, * d_result;
    cusparseHandle_t cusparseHandle;
    cusparseMatDescr_t matDescr;
    cusparseHybMat_t hybMatrix;

    // Allocate memory on device
    checkCudaError(cudaMalloc((void**)&d_denseMatrix, rows * cols * sizeof(float)), "cudaMalloc denseMatrix");
    checkCudaError(cudaMalloc((void**)&d_denseVector, cols * sizeof(float)), "cudaMalloc denseVector");
    checkCudaError(cudaMalloc((void**)&d_result, rows * sizeof(float)), "cudaMalloc result");

    // Copy data to device
    checkCudaError(cudaMemcpy(d_denseMatrix, denseMatrix.data(), rows * cols * sizeof(float), cudaMemcpyHostToDevice), "cudaMemcpy denseMatrix");
    checkCudaError(cudaMemcpy(d_denseVector, denseVector.data(), cols * sizeof(float), cudaMemcpyHostToDevice), "cudaMemcpy denseVector");

    // Initialize cuSPARSE
    checkCusparseError(cusparseCreate(&cusparseHandle), "cusparseCreate");
    checkCusparseError(cusparseCreateMatDescr(&matDescr), "cusparseCreateMatDescr");
    checkCusparseError(cusparseSetMatType(matDescr, CUSPARSE_MATRIX_TYPE_GENERAL), "cusparseSetMatType");
    checkCusparseError(cusparseSetMatIndexBase(matDescr, CUSPARSE_INDEX_BASE_ZERO), "cusparseSetMatIndexBase");

    // Create HYB matrix
    checkCusparseError(cusparseCreateHybMat(&hybMatrix), "cusparseCreateHybMat");

    // Convert dense matrix to HYB format
    checkCusparseError(
        cusparseSdense2hyb(cusparseHandle, rows, cols, matDescr, d_denseMatrix, rows, hybMatrix, 0, CUSPARSE_HYB_PARTITION_AUTO),
        "cusparseSdense2hyb"
    );

    // Perform SpMV (HYB format)
    const float alpha = 1.0f, beta = 0.0f;
    checkCusparseError(
        cusparseShybmv(cusparseHandle, CUSPARSE_OPERATION_NON_TRANSPOSE, &alpha, matDescr, hybMatrix, d_denseVector, &beta, d_result),
        "cusparseShybmv"
    );

    // Copy result back to host
    checkCudaError(cudaMemcpy(result.data(), d_result, rows * sizeof(float), cudaMemcpyDeviceToHost), "cudaMemcpy result");

    // Print result
    std::cout << "Result vector: ";
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clean up
    checkCudaError(cudaFree(d_denseMatrix), "cudaFree denseMatrix");
    checkCudaError(cudaFree(d_denseVector), "cudaFree denseVector");
    checkCudaError(cudaFree(d_result), "cudaFree result");
    checkCusparseError(cusparseDestroyHybMat(hybMatrix), "cusparseDestroyHybMat");
    checkCusparseError(cusparseDestroyMatDescr(matDescr), "cusparseDestroyMatDescr");
    checkCusparseError(cusparseDestroy(cusparseHandle), "cusparseDestroy");

    return 0;
}