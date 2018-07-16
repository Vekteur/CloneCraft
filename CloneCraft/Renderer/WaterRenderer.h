#pragma once

#include "GlmCommon.h"
#include "glad/glad.h"
#include "Shader.h"
#include "Mesh.h"

class WaterRenderer {
public:
	WaterRenderer();

	void render(const WaterMesh& mesh) const;

private:
	Shader m_shader;
};
