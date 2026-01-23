#ifndef LOADER_H
#define LOADER_H

#include <cstdint>
#include <vector>

// Helper to flip High-Endian (File) to Little-Endian (Intel/AMD CPU)
uint32_t swapEndian(uint32_t value);

struct Data {
	std::vector<std::vector<float>> images; // Normalised
	std::vector<uint8_t> labels;
};

Data loadData(const char* imageFilename, const char* labelFilename);

#endif // !LOADER_H
