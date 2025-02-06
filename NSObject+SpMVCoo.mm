//
//  NSObject+SpMVCoo.m
//  SpMVTest
//
//  Created by 张木林 on 9/19/24.
//

//#import <Foundation/Foundation.h>
//#import <Metal/Metal.h>
//#import <vector>
//
//using namespace std;
//
//// COO Sparse Matrix class
//class COOSparseMatrix {
//public:
//    vector<int> row_indices;
//    vector<int> col_indices;
//    vector<float> values;
//    int rows;
//    int cols;
//
//    // Constructor
//    COOSparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}
//
//    // Add an element to the matrix
//    void addElement(int row, int col, float value) {
//        row_indices.push_back(row);
//        col_indices.push_back(col);
//        values.push_back(value);
//    }
//};
//
//int main() {
//    @autoreleasepool {
//        // 创建一个 100000000 x 100000000 的稀疏矩阵
//        int matrixSize = 100000000;
//        COOSparseMatrix cooMatrix(matrixSize, matrixSize);
//
//        // 随机填充稀疏矩阵，每行有 10 个非零元素
//        srand(time(NULL));
//        for (int i = 0; i < matrixSize; ++i) {
//            for (int j = 0; j < 10; ++j) {
//                int col = rand() % matrixSize;
//                float value = static_cast<float>(rand()) / RAND_MAX;
//                cooMatrix.addElement(i, col, value);
//            }
//        }
//
//        // 创建一个 100000000 维的向量
//        vector<float> vec(matrixSize, 1.0f);
//        vector<float> resultArray(matrixSize, 0.0f);
//
//        // Metal 初始化
//        id<MTLDevice> device = MTLCreateSystemDefaultDevice();
//        id<MTLCommandQueue> commandQueue = [device newCommandQueue];
//
//        // 创建 Metal 缓冲区
//        id<MTLBuffer> valuesBuffer = [device newBufferWithBytes:cooMatrix.values.data()
//                                                         length:cooMatrix.values.size() * sizeof(float)
//                                                        options:MTLResourceStorageModeShared];
//        id<MTLBuffer> rowIndicesBuffer = [device newBufferWithBytes:cooMatrix.row_indices.data()
//                                                             length:cooMatrix.row_indices.size() * sizeof(int)
//                                                            options:MTLResourceStorageModeShared];
//        id<MTLBuffer> colIndicesBuffer = [device newBufferWithBytes:cooMatrix.col_indices.data()
//                                                             length:cooMatrix.col_indices.size() * sizeof(int)
//                                                            options:MTLResourceStorageModeShared];
//        id<MTLBuffer> vecBuffer = [device newBufferWithBytes:vec.data()
//                                                      length:vec.size() * sizeof(float)
//                                                     options:MTLResourceStorageModeShared];
//        id<MTLBuffer> resultBuffer = [device newBufferWithLength:resultArray.size() * sizeof(float)
//                                                         options:MTLResourceStorageModeShared];
//
//        // 加载 Metal 着色器
//        NSError *error = nil;
//        id<MTLLibrary> library = [device newDefaultLibrary];
//        if (!library) {
//            NSLog(@"无法找到默认的Metal库");
//            return 0;
//        }
//        id<MTLFunction> function = [library newFunctionWithName:@"coo_matrix_vector_mul"];
//        if (!function) {
//            NSLog(@"无法找到指定的函数");
//            return 0;
//        }
//        id<MTLComputePipelineState> computePipelineState = [device newComputePipelineStateWithFunction:function error:&error];
//
//        // 开始计时
//        NSDate *startTime = [NSDate date];
//
//        // 提交命令给 GPU
//        id<MTLCommandBuffer> commandBuffer = [commandQueue commandBuffer];
//        id<MTLComputeCommandEncoder> computeEncoder = [commandBuffer computeCommandEncoder];
//        [computeEncoder setComputePipelineState:computePipelineState];
//        [computeEncoder setBuffer:valuesBuffer offset:0 atIndex:0];
//        [computeEncoder setBuffer:rowIndicesBuffer offset:0 atIndex:1];
//        [computeEncoder setBuffer:colIndicesBuffer offset:0 atIndex:2];
//        [computeEncoder setBuffer:vecBuffer offset:0 atIndex:3];
//        [computeEncoder setBuffer:resultBuffer offset:0 atIndex:4];
//
//        MTLSize gridSize = MTLSizeMake(cooMatrix.values.size(), 1, 1);
//        MTLSize threadGroupSize = MTLSizeMake(1, 1, 1);
//        [computeEncoder dispatchThreads:gridSize threadsPerThreadgroup:threadGroupSize];
//
//        [computeEncoder endEncoding];
//        [commandBuffer commit];
//        [commandBuffer waitUntilCompleted];
//
//        // 结束计时
//        NSDate *endTime = [NSDate date];
//        NSTimeInterval elapsedTime = [endTime timeIntervalSinceDate:startTime];
//
//        // 读取 GPU 计算结果
//        float *resultPointer = (float *)[resultBuffer contents];
//        for (int i = 0; i < cooMatrix.rows; i++) {
//            resultArray[i] = resultPointer[i];
//        }
//
//        // 打印计算时间
//        NSLog(@"COO 计算时间: %f 秒", elapsedTime);
//
//        // 打印结果（可选，只打印前10个）
//        NSLog(@"Result of COO Matrix-Vector Multiplication (first 10 elements):");
//        for (int i = 0; i < 10; i++) {
//            NSLog(@"%f ", resultArray[i]);
//        }
//    }
//    return 0;
//}





//#import<Foundation/Foundation.h>
//#import<Metal/Metal.h>
//#include <vector>
//#include <fstream>
//#include <sstream>
//#include <iostream>
//
//using namespace std;
//
//class COOSparseMatrix {
//public:
//    vector<float> values;       // Non-zero values
//    vector<int> row_indices;    // Row indices of non-zero values
//    vector<int> col_indices;    // Column indices of non-zero values
//    int rows;                   // Number of rows
//    int cols;                   // Number of columns
//
//    // Constructor
//    COOSparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}
//
//    // Add element to COO format
//    void addElement(int row, int col, float value) {
//        row_indices.push_back(row);
//        col_indices.push_back(col);
//        values.push_back(value);
//    }
//
//    // Method to display the matrix (for testing purposes)
//    void display() {
//        for (size_t i = 0; i < values.size(); ++i) {
//            cout << "(" << row_indices[i] << ", " << col_indices[i] << ") -> " << values[i] << endl;
//        }
//    }
//};
//
//// Function to read the matrix from Matrix Market format and populate the COO matrix
//void readMatrixMarketFile(const std::string& fileName, COOSparseMatrix& cooMatrix) {
//    std::ifstream file(fileName);
//    std::string line;
//
//    // Skip comments and headers
//    while (std::getline(file, line)) {
//        if (line[0] != '%') {
//            break;
//        }
//    }
//
//    std::istringstream header(line);
//    int rows, cols, nonZeroCount;
//    header >> rows >> cols >> nonZeroCount;
//
//    cooMatrix = COOSparseMatrix(rows, cols);
//
//    int row, col;
//    float value;
//    while (file >> row >> col >> value) {
//        cooMatrix.addElement(row - 1, col - 1, value);  // MTX format starts from 1, we adjust to 0
//    }
//}
//
//
//
//int main() {
//    // COO Sparse Matrix Initialization
//    @autoreleasepool
//    {
//        COOSparseMatrix cooMatrix(0, 0);
//        
//        // Reading matrix from file
//        readMatrixMarketFile("/Users/zhangmulin/Downloads/s3dkq4m2.mtx", cooMatrix);
//        // 创建一个与矩阵维度相匹配的向量
//        vector<float> vec(cooMatrix.cols, 1.0f);
//        vector<float> resultArray(cooMatrix.rows, 0.0f);
//        
//        // Metal 初始化
//        id<MTLDevice> device = MTLCreateSystemDefaultDevice();
//        id<MTLCommandQueue> commandQueue = [device newCommandQueue];
//        
//        // 创建 Metal 缓冲区
//        id<MTLBuffer> valuesBuffer = [device newBufferWithBytes:cooMatrix.values.data()
//                                                         length:cooMatrix.values.size() * sizeof(float)
//                                                        options:MTLResourceStorageModeShared];
//        id<MTLBuffer> colIndicesBuffer = [device newBufferWithBytes:cooMatrix.col_indices.data()
//                                                             length:cooMatrix.col_indices.size() * sizeof(int)
//                                                            options:MTLResourceStorageModeShared];
//        id<MTLBuffer> rowPtrBuffer = [device newBufferWithBytes:cooMatrix.col_indices.data()
//                                                         length:cooMatrix.col_indices.size() * sizeof(int)
//                                                        options:MTLResourceStorageModeShared];
//        id<MTLBuffer> vecBuffer = [device newBufferWithBytes:vec.data()
//                                                      length:vec.size() * sizeof(float)
//                                                     options:MTLResourceStorageModeShared];
//        id<MTLBuffer> resultBuffer = [device newBufferWithLength:resultArray.size() * sizeof(float)
//                                                         options:MTLResourceStorageModeShared];
//        
//        // 加载 Metal 着色器
//        NSError *error = nil;
//        id<MTLLibrary> library = [device newDefaultLibrary];
//        if (!library) {
//            NSLog(@"无法找到默认的Metal库");
//            return 0;
//        }
//        id<MTLFunction> function = [library newFunctionWithName:@"csr_matrix_vector_mul"];
//        if (!function) {
//            NSLog(@"无法找到指定的函数");
//            return 0;
//        }
//        id<MTLComputePipelineState> computePipelineState = [device newComputePipelineStateWithFunction:function error:&error];
//        
//        // 开始计时
//        NSDate *startTime = [NSDate date];
//        
//        // 分块处理矩阵的行
//        int block_size = 1024;  // 你可以根据 GPU 内存选择一个合适的块大小
//        
//        for (int i = 0; i < cooMatrix.rows; i += block_size) {
//            int current_block_size = std::min(block_size, cooMatrix.rows - i);
//            
//            // 分块：每次只将 current_block_size 行传输到 GPU
//            MTLSize gridSize = MTLSizeMake(current_block_size, 1, 1);
//            MTLSize threadGroupSize = MTLSizeMake(1, 1, 1);  // 可以调整线程组大小以优化 GPU 性能
//            
//            // 创建 GPU 编码器
//            id<MTLCommandBuffer> commandBuffer = [commandQueue commandBuffer];
//            id<MTLComputeCommandEncoder> computeEncoder = [commandBuffer computeCommandEncoder];
//            [computeEncoder setComputePipelineState:computePipelineState];
//            
//            // 传递当前块的行到 GPU
//            [computeEncoder setBuffer:valuesBuffer offset:(i * sizeof(float)) atIndex:0];
//            [computeEncoder setBuffer:colIndicesBuffer offset:(i * sizeof(int)) atIndex:1];
//            [computeEncoder setBuffer:rowPtrBuffer offset:(i * sizeof(int)) atIndex:2];
//            [computeEncoder setBuffer:vecBuffer offset:0 atIndex:3];  // 向量不需要分块
//            [computeEncoder setBuffer:resultBuffer offset:(i * sizeof(float)) atIndex:4];
//            
//            // 提交当前块的计算任务给 GPU
//            [computeEncoder dispatchThreads:gridSize threadsPerThreadgroup:threadGroupSize];
//            
//            // 结束编码
//            [computeEncoder endEncoding];
//            [commandBuffer commit];
//            [commandBuffer waitUntilCompleted];
//        }
//        
//        // 结束计时
//        NSDate *endTime = [NSDate date];
//        NSTimeInterval elapsedTime = [endTime timeIntervalSinceDate:startTime];
//        
//        // 读取 GPU 计算结果
//        float *resultPointer = (float *)[resultBuffer contents];
//        for (int i = 0; i < cooMatrix.rows; i++) {
//            resultArray[i] = resultPointer[i];
//        }
//        
//        // 打印计算时间
//        NSLog(@"计算时间: %f 秒", elapsedTime);
//        
//        // 打印结果（可选，只打印前10个）
//        NSLog(@"Result of CSR Matrix-Vector Multiplication (first 10 elements):");
//        for (int i = 0; i < 10; i++) {
//            NSLog(@"%f ", resultArray[i]);
//        }
//        
//        
//        
//    }
//    return 0;
//}
