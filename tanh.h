#include <cmath>

double tanh(float x) {
	return (2.0 / (1 + exp(-2 * x))) - 1;
}
