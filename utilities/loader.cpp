#include "loader.h"

#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <vector>

uint32_t swapEndian(uint32_t value) {
  return ((value >> 24) & 0x000000FF) | ((value >> 8) & 0x0000FF00) |
         ((value << 8) & 0x00FF0000) | ((value << 24) & 0xFF000000);
}

Data loadData(const char *imageFilename, const char *labelFilename) {
  Data data;

  std::ifstream imageFile(imageFilename, std::ios::binary);
  if (!imageFile.is_open()) {
    throw std::runtime_error("Cannot open image file!");
  }

  uint32_t magic = 0, numImages = 0, rows = 0, cols = 0;

  // Read Headers
  imageFile.read(reinterpret_cast<char *>(&magic), 4);
  imageFile.read(reinterpret_cast<char *>(&numImages), 4);
  imageFile.read(reinterpret_cast<char *>(&rows), 4);
  imageFile.read(reinterpret_cast<char *>(&cols), 4);

  // Swap Endianness
  magic = swapEndian(magic);
  numImages = swapEndian(numImages);
  rows = swapEndian(rows);
  cols = swapEndian(cols);

  // Sanity Check
  if (magic != 2051)
    throw std::runtime_error("Invalid magic number for images!");

  // Resize dataset
  int imageSize = rows * cols;
  data.images.resize(numImages, std::vector<float>(imageSize));

  // Read Pixels
  for (uint32_t i = 0; i < numImages; ++i) {
    for (int p = 0; p < imageSize; ++p) {
      uint8_t pixel = 0;
      imageFile.read((char *)&pixel, 1);

      data.images[i][p] = pixel / 255.0f;
    }
  }

  std::ifstream labelFile(labelFilename, std::ios::binary);
  if (!labelFile.is_open()) {
    throw std::runtime_error("Cannot open label file!");
  }

  uint32_t labelMagic = 0, numLabels = 0;
  labelFile.read((char *)&labelMagic, 4);
  labelFile.read((char *)&numLabels, 4);

  labelMagic = swapEndian(labelMagic);
  numLabels = swapEndian(numLabels);

  if (labelMagic != 2049) {
    throw std::runtime_error("Invalid magic number for labels!");
  }

  data.labels.resize(numLabels);
  for (uint32_t i = 0; i < numLabels; ++i) {
    uint8_t label = 0;
    labelFile.read((char *)&label, 1);
    data.labels[i] = label;
  }

  return data;
}
