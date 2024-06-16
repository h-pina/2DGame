#include "GameObject.h"
#include "Mesh.h"
#include "Shader.h"

namespace Game {
	//NOTE: Those could be pointers?
	GameObject::GameObject(Mesh* mesh, Shader* shader){
		m_mesh = mesh;
		m_shader = shader;
	}
}
