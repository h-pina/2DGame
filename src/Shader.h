#pragma once

#include <string>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

namespace Game {
	class Shader {
		public:
			Shader() = default;
			Shader(const char* vertexPath, const char* fragPath, std::string name);

			void use();

			void vec2Uniform(const char* name, glm::vec2 value);
			void vec3Uniform(const char* name, glm::vec3 value);
			void vec4Uniform(const char* name, glm::vec4 value);
			void mat4Uniform(const char* name, glm::mat4 value);

			std::string m_shaderName;
		private:	
			GLuint m_programId;

			int generateShaderObject(int shaderType, const char* filePath );
			void isCompilationSuccessful(int shaderId, const char* shaderName);
	};
}
