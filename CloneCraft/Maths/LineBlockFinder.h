#pragma once

#include <GlmCommon.h>
#include <tuple>

class LineBlockFinder {
public:
	LineBlockFinder(vec3 pos, vec3 dir);

	ivec3 next();
	float getDistance();

private:
	const float epsilon = 1e-6;
	vec3 pos;
	vec3 dir;
	float distance = 0.f;

	std::tuple<vec3, float> nextIntersection();
};

