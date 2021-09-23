#pragma once

#include <glad/glad.h>

class Debug
{
public:
	Debug() = delete;
	
	static GLenum glCheckError_(const char *file, int line);
	static void APIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity,
		GLsizei length, const GLchar *message, const void *userParam);

	#define glCheckError() glCheckError_(__FILE__, __LINE__) 
};