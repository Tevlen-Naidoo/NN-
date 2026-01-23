#include "layer.h"
#include <cmath>
#include <random>

double randomWeight() {
  static std::random_device randomDevice;
  static std::mt19937 generator(randomDevice());

  static std::normal_distribution<> distribution(0.0, 0.1);

  return distribution(generator);
}

DenseLayer::DenseLayer(int inputSize, int outputSize) {
  weights.resize(outputSize, Vector(inputSize));
  biases.resize(outputSize);

  for (int i = 0; i < outputSize; ++i) {
    biases[i] = 0.0;
    for (int j = 0; j < inputSize; ++j) {
      weights[i][j] = randomWeight();
    }
  }
}

Vector DenseLayer::forward(const Vector &input) {
  this->inputCache = input;

  int outputSize = weights.size();
  int inputSize = weights[0].size();

  Vector output(outputSize);

  for (int i = 0; i < outputSize; ++i) {
    double sum = 0.0;
    for (int j = 0; j < inputSize; ++j) {
      sum += weights[i][j] * input[j];
    }
    sum += biases[i];

    output[i] = 1.0 / (1.0 + std::exp(-sum));
  }

  return output;
}
