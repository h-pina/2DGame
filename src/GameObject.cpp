#include "GameObject.h"

namespace Game {

	uint32_t GameObject::s_idCounter = 0;
	  
	GameObject::GameObject(const char* name, std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader)
		: m_mesh(mesh),
			m_shader(shader),
			m_name(name),
			m_id(s_idCounter++),
			m_modelMatrix(glm::mat4(1.0))
	{ }

	GameObject::GameObject(const char* name) // if mesh and shader defined later
		: m_name(name),
			m_id(s_idCounter++),
			m_modelMatrix(glm::mat4(1.0))
	{ }
	glm::mat4 GameObject::getModelMatrix(){
		return m_modelMatrix;
	}

	std::string GameObject::getName(){
		return m_name;
	}

	uint32_t GameObject::getId(){
		return m_id;
	}

	std::shared_ptr<Mesh> GameObject::getMesh(){
		return m_mesh;
	}

	std::shared_ptr<Shader> GameObject::getShader(){
		return m_shader;
	}
}
