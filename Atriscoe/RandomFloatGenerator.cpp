#include "RandomFloatGenerator.h"

const float RandomFloatGenerator::baseMin = 0.0f;
const float RandomFloatGenerator::baseMax = 1.0f;
std::random_device RandomFloatGenerator::rd;
std::mt19937 RandomFloatGenerator::gen(rd());								// seeding the generator
std::uniform_real_distribution<float> RandomFloatGenerator::dis{ baseMin, baseMax };


float RandomFloatGenerator::generateRandomFloatInRange(float min, float max) {
	float range = max - min;
	return dis(gen)*range + min;
}
