#pragma once
 
#include "Mesh.h"
#include "Shader.h"
#include "glm/ext/matrix_float4x4.hpp"
#include <cstdint>
namespace Game {

	class GameObject {
	public:
		std::string m_name; 
		Mesh m_mesh; 
		Shader m_shader;

		//GameObject();
		//GameObject(Mesh mesh);
		GameObject(const char* name, Mesh mesh, Shader shader);
		void move(const char* direction);
		glm::mat4 getModelMatrix();


	private:
		//Texture2D m_tex2d:
		glm::mat4 m_modelMatrix;
	};
}
