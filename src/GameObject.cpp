#include "GameObject.h"
#include "Mesh.h"
#include "Shader.h"
#include "glm/ext/matrix_transform.hpp"
#include "Globals.h"

namespace Game {
	// The Meshes have to be passed by value, so their data is copied and
	// stored inside the gameObject 
	GameObject::GameObject(const char* name,Mesh mesh, Shader shader){
		m_name = name;
		m_mesh = mesh;
		m_shader = shader;

		m_modelMatrix = glm::mat4(1.0f);
		m_modelMatrix = glm::translate(m_modelMatrix,glm::vec3((float)(g_windowConfig.width)/2, (float)(g_windowConfig.height)/9,0.0f));
		m_modelMatrix = glm::scale(m_modelMatrix, glm::vec3(500,500,0.0));
	}

	void GameObject::move(const char* direction){
		if (std::string("left").compare(direction) == 0)
				m_modelMatrix = glm::translate(m_modelMatrix, glm::vec3(0.1f,0.0f,0.0f));
		if (std::string("right").compare(direction) == 0)
				m_modelMatrix = glm::translate(m_modelMatrix, glm::vec3(-0.1f,0.0f,0.0f));
	}

	glm::mat4 GameObject::getModelMatrix(){
		return m_modelMatrix;
	}
}
