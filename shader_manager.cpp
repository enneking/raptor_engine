/*
* ShaderManager.cpp
*
*  Created on: Nov 23, 2015
*      Author: alexander
*/

#include "shader_manager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace rpt;

ShaderManager::ShaderManager()
{
}

GLuint ShaderManager::CreateShaderProg(const std::string sfileNameFs, const std::string sfileNameVs) {


	//create shader and program
	auto vs = glCreateShader(GL_VERTEX_SHADER);
	auto fs = glCreateShader(GL_FRAGMENT_SHADER);
	auto prog = glCreateProgram();

	std::cout << "initializing Prog_" << prog << "(" << sfileNameFs << ", " << sfileNameVs << ") ... ";

	//read content from files
	const auto fileContent_vs = getFileContent(sfileNameVs);
	const auto fileContent_fs = getFileContent(sfileNameFs);


	//compile vertex shader
	const auto *vscr = fileContent_vs.c_str();
	glShaderSource(vs, 1, &vscr, NULL);
	glCompileShader(vs);
	printGLSLCompileLog(vs);


	//compile fragment shader
	const auto  *fscr = fileContent_fs.c_str();
	glShaderSource(fs, 1, &fscr, NULL);
	glCompileShader(fs);
	printGLSLCompileLog(fs);

	// link program
	glAttachShader(prog, vs);
	glAttachShader(prog, fs);
	glLinkProgram(prog);
	printGLSLLinkLog(prog);

	std::cout << " success! \n";

	return prog;

}

std::string ShaderManager::getFileContent(const std::string fileName) {
	std::string line = "";
	std::string fileContent = "";

	std::ifstream fileStream(fileName.c_str(), std::ifstream::in);

	if (fileStream.is_open()) {
		while (fileStream.good()) {
			std::getline(fileStream, line);
			fileContent += line + "\n";
		}
		fileStream.close();
	}
	else {
		std::cout << "Failed to open file: " << fileName << std::endl;
		return "";
	}
	return fileContent;
}

void ShaderManager::printGLSLCompileLog(GLuint shaderHandle) {
	GLint shaderError;
	glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &shaderError);
	if (shaderError != GL_TRUE) {
		std::cerr << "Shader compile error: " << std::endl;
	}

	// a log gets always printed (could be warnings)
	GLsizei length = 0;
	glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &length);
	if (length > 1) {
		// a compile log can get produced even if there were no errors, but warnings!
		GLchar* pInfo = new char[length + 1];
		glGetShaderInfoLog(shaderHandle, length, &length, pInfo);
		std::cerr << "Compile log: " << std::string(pInfo) << std::endl;
		delete[] pInfo;
	}
}

void ShaderManager::printGLSLLinkLog(GLuint progHandle) {
	// check for program link errors:
	GLint programError;
	glGetProgramiv(progHandle, GL_LINK_STATUS, &programError);

	if (programError != GL_TRUE) {
		std::cerr << "Program could not get linked:" << std::endl;
	}

	GLsizei length = 0;
	glGetProgramiv(progHandle, GL_INFO_LOG_LENGTH, &length);
	if (length > 1) {
		// error log or warnings:
		GLchar* pInfo = new char[length + 1];
		glGetProgramInfoLog(progHandle, length, &length, pInfo);
		std::cout << "Linker log: " << std::string(pInfo) << std::endl;
		delete[] pInfo;
	}
}