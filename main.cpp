#include <iostream>

#include "utilities/tanh.h"
#include "utilities/sigmoid.h"
#include "utilities/relu.h"

int main () {
	std::cout << tanh(0.5) << std::endl;
	std::cout << sigmoid(0.5) << std::endl;
	std::cout << ReLU(0.5) << std::endl;
	
	return 0;
}

