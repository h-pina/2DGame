#pragma once

#include <string>
#include <glm/glm.hpp>

namespace Game {
	class Shader {
		public:
			Shader(const char* vertexPath, const char*  fragPath);
			void use();

			void vec2Uniform(const char* name, glm::vec2 value);
			void vec3Uniform(const char* name, glm::vec3 value);
			void vec4Uniform(const char* name, glm::vec4 value);

		private:
			int m_programId;


			std::string readFromFile(const char* filePath);
			int generateShaderObject(int shaderType, const char* filePath );
			void isCompilationSuccessful(int shaderId, const char* shaderName);
	};
}