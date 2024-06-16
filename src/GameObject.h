#pragma once
 
#include "Mesh.h"
#include "Shader.h"
#include <cstdint>
namespace Game {

	class GameObject {
	public:
		Mesh* m_mesh; 
		Shader* m_shader;

		//GameObject();
		//GameObject(Mesh mesh);
		GameObject(Mesh* mesh, Shader* shader);
		void setupGLStateForRender();
		void move();
		

	private:
		//Texture2D m_tex2d:
		float m_position;
	};
}
