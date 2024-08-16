#include<iostream>
#include<vector>
#include<thread>
using namespace std;
// 稀疏矩阵CRS格式的稀疏矩阵-向量乘法
void parallel_SpMV(const std::vector<double>& values,
                   const std::vector<int>& columnIndex,
                   const std::vector<int>& rowPtr,
                   const std::vector<double>& x,
                   std::vector<double>& y,
                   int start_row,
                   int end_row) {
    for (int i = start_row; i < end_row; ++i) {
        double sum = 0;
        for (int j = rowPtr[i]; j < rowPtr[i + 1]; ++j) {
            sum += values[j] * x[columnIndex[j]];
        }
        y[i] = sum;
    }
}

// 多线程版本的SpMV
void SpMV_parallel(const std::vector<double>& values,
                   const std::vector<int>& columnIndex,
                   const std::vector<int>& rowPtr,
                   const std::vector<double>& x,
                   std::vector<double>& y,
                   int num_threads) {
    int rows = rowPtr.size() - 1;
    std::vector<std::thread> threads;
    int rows_per_thread = rows / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        int start_row = i * rows_per_thread;
        int end_row = (i == num_threads - 1) ? rows : (i + 1) * rows_per_thread;

        threads.emplace_back(parallel_SpMV, std::cref(values), std::cref(columnIndex),
                             std::cref(rowPtr), std::cref(x), std::ref(y),
                             start_row, end_row);
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

int main() {
    // 示例稀疏矩阵 (以CRS格式存储)
    std::vector<double> values = {10, 20, 30, 40, 50, 60};
    std::vector<int> columnIndex = {0, 1, 0, 2, 1, 3};
    std::vector<int> rowPtr = {0, 2, 3, 5, 6};  // rowPtr size = rows + 1

    // 示例向量
    std::vector<double> x = {1, 2, 3, 4};

    // 结果向量
    std::vector<double> y(rowPtr.size() - 1, 0);

    // 使用2个线程进行并行计算
    int num_threads = 2;
    SpMV_parallel(values, columnIndex, rowPtr, x, y, num_threads);

    // 输出结果向量
    std::cout << "Result vector y:" << std::endl;
    for (double yi : y) {
        std::cout << yi << " ";
    }
    std::cout << std::endl;

    return 0;
}