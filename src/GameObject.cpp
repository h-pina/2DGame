#include "GameObject.h"
#include "Mesh.h"
#include "Shader.h"

namespace Game {
	// The Meshes have to be passed by value, so their data is copied and
	// stored inside the gameObject 
	GameObject::GameObject(const char* name,Mesh mesh, Shader shader){
		m_name = name;
		m_mesh = mesh;
		m_shader = shader;
	}
}
