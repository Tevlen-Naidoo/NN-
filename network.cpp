#include "network.h"
#include "layer.h"

Network::~Network() {
  for (Layer *layer : layers) {
    delete layer;
  }
};

void Network::add(Layer *layer) { layers.push_back(layer); }

Vector Network::predict(Vector input) {
  Vector currentActivation = input;

  for (Layer *layer : this->layers) {
    currentActivation = layer->forward(currentActivation);
  }

  return currentActivation;
}
