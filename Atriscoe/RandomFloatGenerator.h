#pragma once
#include <random>

class RandomFloatGenerator {
public:
	static float generateRandomFloatInRange(float min, float max);
private:
	const static float baseMin;
	const static float baseMax;
	static std::random_device rd;						// seeder
	static std::mt19937 gen;							// mersenne twister engine
	static std::uniform_real_distribution<float> dis;
};
