#include <exception>
#include <iostream>
#include <vector>

#include "utilities/loader.h"

int main() {

  try {
    auto dataset = loadData("MNIST/train-images-idx3-ubyte/train-images-idx3-ubyte",
                            "MNIST/train-labels-idx1-ubyte/train-labels-idx1-ubyte");

    std::cout << "Loaded " << dataset.images.size() << " images." << std::endl;

  } catch (const std::exception &exception) {
    std::cerr << "Error: " << exception.what() << std::endl;
  }

  return 0;
}
