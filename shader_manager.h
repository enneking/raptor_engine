/*
* ShaderManager.h
*
*  Created on: Nov 23, 2015
*      Author: alexander
*/

#pragma once

#include <glew.h>
#include <GLFW/glfw3.h>

//std libs
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include <vector>

#include "non_copyable.h" 

namespace rpt {
	class ShaderManager : public NonCopyable {
	public:

		ShaderManager();

		GLuint CreateShaderProg(const std::string sfileNameFragmentShader, const std::string sfileNameVertexShader);

	private:
		std::string getFileContent(const std::string fileName);
		void printGLSLCompileLog(GLuint shaderHandle);
		void printGLSLLinkLog(GLuint progHandle);

	};
}