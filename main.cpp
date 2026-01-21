#include <iostream>
#include <vector>

#include "utilities/activations.h"

int main() {

  std::vector<float> input = {0.85, 0.25};

  std::vector<float> weights = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};

  float res = input[0] * weights[0] + input[1] * weights[3];

  std::cout << nn::sigmoid(res) << std::endl;

  return 0;
}
