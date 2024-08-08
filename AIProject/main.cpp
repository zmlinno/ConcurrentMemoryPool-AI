#define _CRT_SECURE_NO_WARNINGS
#include "NeuralNetwork.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <atomic>
#include "ConcurrentAlloc.h" 
//简单的
// 训练神经网络并记录时间
void train_neural_network(size_t input_size, size_t output_size, size_t dataset_size, size_t epochs, const std::vector<size_t>& hidden_layers, bool use_custom_allocator) {
    NeuralNetwork nn(input_size, output_size, hidden_layers);
    std::vector<std::vector<float>> inputs(dataset_size, std::vector<float>(input_size, 1.0f));
    std::vector<std::vector<float>> targets(dataset_size, std::vector<float>(output_size, 0.0f));
    nn.train(inputs, targets, epochs, use_custom_allocator);
}

int main() {
    size_t input_size = 100;
    size_t output_size = 10;
    size_t epochs = 50;  // 增加训练次数

    // 不同规模的数据集
    std::vector<size_t> dataset_sizes = { 10000, 50000, 100000 };

    // 定义不同复杂度的神经网络架构
    std::vector<size_t> simple_nn = { 10 };              // 简单神经网络
    std::vector<size_t> medium_nn = { 50, 50 };          // 中等神经网络
    std::vector<size_t> complex_nn = { 100, 100, 100 };  // 复杂神经网络

    for (size_t dataset_size : dataset_sizes) {
        std::cout << "Dataset size: " << dataset_size << std::endl;

        // 简单神经网络
        std::cout << "Simple Neural Network - Training with Custom Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, simple_nn, true);
        std::cout << "Simple Neural Network - Training with Default Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, simple_nn, false);

        // 中等神经网络
        std::cout << "Medium Neural Network - Training with Custom Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, medium_nn, true);
        std::cout << "Medium Neural Network - Training with Default Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, medium_nn, false);

        // 复杂神经网络
        std::cout << "Complex Neural Network - Training with Custom Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, complex_nn, true);
        std::cout << "Complex Neural Network - Training with Default Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, complex_nn, false);
    }

    return 0;
}






















