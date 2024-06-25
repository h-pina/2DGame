#include "GameObject.h"

namespace Game {
	GameObject::GameObject(const char* name, std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader)
		: m_mesh(mesh),
			m_shader(shader),
			m_name(name),
			m_id(s_idCounter++),
			m_modelMatrix(glm::mat4(1.0))
	{ }

	glm::mat4 GameObject::getModelMatrix(){
		return m_modelMatrix;
	}

	std::string GameObject::getName(){
		return m_name;
	}

	std::shared_ptr<Mesh> GameObject::getMesh(){
		return m_mesh;
	}

	std::shared_ptr<Shader> GameObject::getShader(){
		return m_shader;
	}
}
