#include <iostream>
#include <vector>

#include "utilities/activations.h"

int main() {

  std::vector<float> input = {0.85, 0.25};

  std::vector<float> weights = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};

  std::cout << nn::sigmoid(input[0]) << std::endl;

  return 0;
}
