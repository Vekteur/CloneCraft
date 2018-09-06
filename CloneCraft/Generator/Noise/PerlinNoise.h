#include <GlmCommon.h>
#include <array>

#pragma once
class PerlinNoise
{
public:
	PerlinNoise();
	~PerlinNoise();

	float getNoise(vec2 pos);

private:
	static double lerp(float amount, float left, float right);
	static double fade(float t);
	static double grad(int hash, float x, float y);

	static std::array<int, 512> perm;
};
