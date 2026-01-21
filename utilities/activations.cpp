#include "activations.h"
#include <cmath>

namespace nn {
double sigmoid(double x) { return 1 / (1 + std::exp(-x)); }

double tanh(double x) { return (2 / (1 + std::exp(-2 * x))) - 1; }

double relu(double x) { return (x > 0) ? x : 0; }
} // namespace nn
