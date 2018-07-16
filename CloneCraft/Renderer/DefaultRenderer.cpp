#include "DefaultRenderer.h"

#include "ResManager.h"
#include "Logger.h"

#include <filesystem>

namespace fs = std::filesystem;

DefaultRenderer::DefaultRenderer()
{
	m_shader.loadFromFile("Resources/Shaders/cube.vs", "Resources/Shaders/cube.frag");
	ResManager::setShader(m_shader, "cube");

	std::string blockTexturesPath = "Resources/Textures/Blocks";
	std::vector<fs::path> paths;
	for (const fs::directory_entry& entry : fs::directory_iterator(blockTexturesPath)) {
		if (entry.path().extension().string() == ".png") {
			paths.push_back(entry.path());
		}
	}
	texArray = TextureArray{ paths, ivec2{ 16, 16 }, GL_RGBA };
}

void DefaultRenderer::render(const DefaultMesh& mesh) const {
	if (mesh.indicesNb != 0) {
		glActiveTexture(GL_TEXTURE0);
		texArray.bind();
		m_shader.use();

		mesh.draw();

		texArray.unbind();
	}
}

TextureArray & DefaultRenderer::getTextureArray() {
	return texArray;
}
