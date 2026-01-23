#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"
#include <vector>

class Network {
private:
  std::vector<Layer *> layers;

public:
  ~Network();
  void add(Layer *layer);

  Vector predict(Vector input);
};

#endif // !NETWORK_H
