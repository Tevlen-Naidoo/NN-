#ifndef LAYER_H
#define LAYER_H

#include <vector>

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

class Layer {
public:
  virtual ~Layer() = default;

  virtual Vector forward(const Vector &input) = 0;
};

class DenseLayer : public Layer {
private:
  Matrix weights;
  Vector biases;

  Vector inputCache;

public:
  DenseLayer(int inputSize, int outputSize);

  Vector forward(const Vector &input) override;
};

#endif // !LAYER_H
