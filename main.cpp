#include <iostream>

#include "tanh.h"
#include "sigmoid.h"
#include "relu.h"

int main () {
	std::cout << tanh(0.5) << std::endl;
	std::cout << sigmoid(0.5) << std::endl;
	std::cout << ReLU(0.5) << std::endl;
	
	return 0;
}

