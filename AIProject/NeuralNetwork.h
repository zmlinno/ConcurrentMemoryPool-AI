#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "ConcurrentAlloc.h"
#include <vector>
#include<iostream>
#include <chrono>
//ÐÂ¼Ó
class NeuralNetwork {
public:
    NeuralNetwork(size_t input_size, size_t output_size, const std::vector<size_t>& hidden_layers);
    void train(const std::vector<std::vector<float>>& inputs, const std::vector<std::vector<float>>& targets, size_t epochs, bool use_custom_allocator);

private:
    std::vector<std::vector<float>> weights_;
    size_t input_size_;
    size_t output_size_;
    std::vector<size_t> hidden_layers_;
};




