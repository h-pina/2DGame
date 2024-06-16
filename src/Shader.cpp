#include "Shader.h"
#include "glm/ext/vector_float2.hpp"
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Game {

	Shader::Shader(const char* vertexPath, const char* fragPath){
		GLuint vertexId = generateShaderObject(GL_VERTEX_SHADER, vertexPath);
		GLuint fragId = generateShaderObject(GL_FRAGMENT_SHADER, fragPath);

		m_programId = glCreateProgram();

		glAttachShader(m_programId, vertexId);
		glAttachShader(m_programId, fragId);
		glLinkProgram(m_programId);

		GLint linkSuccess = 0;
		glGetProgramiv(m_programId, GL_LINK_STATUS, (int *)&linkSuccess);
		if (linkSuccess == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_programId, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<GLchar> errorLog(maxLength);
			glGetProgramInfoLog(m_programId, maxLength, &maxLength, &errorLog[0]);
			
			glDeleteProgram(m_programId);
			glDeleteShader(vertexId);
			glDeleteShader(fragId);
			
			//TODO: Replace for Logger Class and improve error message
			std::cout << "[SHADER ERROR] Shader program failed to link: " << std::string(errorLog.data(), errorLog.size());
			throw std::runtime_error("Could not link shaders correctly");//Is there a better error for that?
		}

		glDetachShader(m_programId, vertexId);
		glDetachShader(m_programId, fragId);
	}

	int Shader::generateShaderObject(int shaderType, const char* filePath ){
		std::string shaderName = shaderType == GL_VERTEX_SHADER ?  "VertexShader" : "Fragment Shader";
		std::string shaderContent = readFromFile(filePath);
		const char* c_shaderContent = shaderContent.c_str(); //TODO: is this naming correct?

		GLuint shaderId = glCreateShader(shaderType);
		glShaderSource(shaderId,1,&(c_shaderContent),NULL); 
		glCompileShader(shaderId);
		
		//ErrorHandling
		GLint success = 0;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
		if(!success){
			GLint maxLength = 0;
			glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(shaderId, maxLength, &maxLength, &errorLog[0]);
			glDeleteShader(shaderId); 
			//TODO: Replace for Logger Class and improve error message
			std::cout << "[SHADER ERROR] " << shaderName << " failed to compile: " << std::string(errorLog.data(), errorLog.size());
			throw std::runtime_error("Could not compile shader correctly");//Is there a better error for that?
		}
		return shaderId;
	}

	void Shader::use(){
		glUseProgram(m_programId);
	}

	void Shader::vec2Uniform(const char* name, glm::vec2 value){
		GLint location = glGetUniformLocation(m_programId, name);
		glUniform2fv(location, 1 ,glm::value_ptr(value));
	}

	void Shader::vec3Uniform(const char* name, glm::vec3 value){
		GLint location = glGetUniformLocation(m_programId, name);
		glUniform3fv(location, 1 ,glm::value_ptr(value));
	}

	void Shader::vec4Uniform(const char* name, glm::vec4 value){
		GLint location = glGetUniformLocation(m_programId, name);
		glUniform4fv(location, 1 ,glm::value_ptr(value));
	}

	void Shader::mat4Uniform(const char* name, glm::mat4 value){
		GLint location = glGetUniformLocation(m_programId, name);
		glUniformMatrix4fv(location, 1 , false, glm::value_ptr(value));
	}

	std::string Shader::readFromFile(const char* filePath){
		std::ifstream fileStream(filePath);
		std::stringstream ss;
		ss << fileStream.rdbuf();
		std::string fileContent = ss.str();
		return fileContent;
	}
	}
