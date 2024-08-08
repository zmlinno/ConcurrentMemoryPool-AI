#define _CRT_SECURE_NO_WARNINGS
#include "NeuralNetwork.h"
#include "ConcurrentAlloc.h" // 包含自定义内存分配器头文件
#include <algorithm>
#include <iostream>

// 下面这个是后加的
#include<chrono>
//简单的
NeuralNetwork::NeuralNetwork(size_t input_size, size_t output_size, const std::vector<size_t>& hidden_layers)
    : input_size_(input_size), output_size_(output_size), hidden_layers_(hidden_layers) {
    // Initialize weights for each layer
    size_t prev_size = input_size_;
    for (size_t layer_size : hidden_layers_) {
        weights_.emplace_back(std::vector<float>(prev_size * layer_size, 0.1f));
        prev_size = layer_size;
    }
    weights_.emplace_back(std::vector<float>(prev_size * output_size_, 0.1f));
}

void NeuralNetwork::train(const std::vector<std::vector<float>>& inputs, const std::vector<std::vector<float>>& targets, size_t epochs, bool use_custom_allocator) {
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t epoch = 0; epoch < epochs; ++epoch) {
        for (size_t sample = 0; sample < inputs.size(); ++sample) {
            for (size_t i = 0; i < 100; ++i) { // 增加内存操作的复杂性
                float* gradients;
                float* temp_storage;
                if (use_custom_allocator) {
                    // 使用自定义内存分配器分配内存
                    gradients = static_cast<float*>(ConcurrentAlloc(weights_.size() * sizeof(float)));
                    temp_storage = static_cast<float*>(ConcurrentAlloc(weights_.size() * sizeof(float)));
                }
                else {
                    // 使用默认内存分配器分配内存
                    gradients = new float[weights_.size()];
                    temp_storage = new float[weights_.size()];
                }

                // 模拟复杂内存操作
                for (size_t j = 0; j < weights_.size(); ++j) {
                    gradients[j] = gradients[j] * weights_[j][0] - inputs[sample][j % input_size_];
                    temp_storage[j] = gradients[j] + weights_[j][0];
                }

                // 更新权重
                for (size_t j = 0; j < weights_.size(); ++j) {
                    weights_[j][0] -= gradients[j] + temp_storage[j];
                }

                if (use_custom_allocator) {
                    // 释放自定义内存分配器分配的内存
                    ConcurrentFree(gradients);
                    ConcurrentFree(temp_storage);
                }
                else {
                    // 释放默认内存分配器分配的内存
                    delete[] gradients;
                    delete[] temp_storage;
                }
            }
        }
        std::cout << "Epoch " << epoch + 1 << " complete." << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << (use_custom_allocator ? "Custom Allocator" : "Default Allocator") << " - Training time: " << duration.count() << " seconds" << std::endl;
}
















