#define _CRT_SECURE_NO_WARNINGS
#include "NeuralNetwork.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <atomic>
#include "ConcurrentAlloc.h" 
//�򵥵�
// ѵ�������粢��¼ʱ��
void train_neural_network(size_t input_size, size_t output_size, size_t dataset_size, size_t epochs, const std::vector<size_t>& hidden_layers, bool use_custom_allocator) {
    NeuralNetwork nn(input_size, output_size, hidden_layers);
    std::vector<std::vector<float>> inputs(dataset_size, std::vector<float>(input_size, 1.0f));
    std::vector<std::vector<float>> targets(dataset_size, std::vector<float>(output_size, 0.0f));
    nn.train(inputs, targets, epochs, use_custom_allocator);
}

int main() {
    size_t input_size = 100;
    size_t output_size = 10;
    size_t epochs = 50;  // ����ѵ������

    // ��ͬ��ģ�����ݼ�
    std::vector<size_t> dataset_sizes = { 10000, 50000, 100000 };

    // ���岻ͬ���Ӷȵ�������ܹ�
    std::vector<size_t> simple_nn = { 10 };              // ��������
    std::vector<size_t> medium_nn = { 50, 50 };          // �е�������
    std::vector<size_t> complex_nn = { 100, 100, 100 };  // ����������

    for (size_t dataset_size : dataset_sizes) {
        std::cout << "Dataset size: " << dataset_size << std::endl;

        // ��������
        std::cout << "Simple Neural Network - Training with Custom Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, simple_nn, true);
        std::cout << "Simple Neural Network - Training with Default Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, simple_nn, false);

        // �е�������
        std::cout << "Medium Neural Network - Training with Custom Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, medium_nn, true);
        std::cout << "Medium Neural Network - Training with Default Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, medium_nn, false);

        // ����������
        std::cout << "Complex Neural Network - Training with Custom Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, complex_nn, true);
        std::cout << "Complex Neural Network - Training with Default Allocator" << std::endl;
        train_neural_network(input_size, output_size, dataset_size, epochs, complex_nn, false);
    }

    return 0;
}






















