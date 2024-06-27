#include "Player.h"
#include "Window.h"
#include "Mesh.h"
#include "glm/ext/vector_float3.hpp"
#include <glm/ext.hpp>

namespace Game {
	// The Meshes have to be passed by value, so their data is copied and
	// stored inside the gameObject 
	Player::Player(Window* window):
			GameObject("player"){

		float vertexData[] = { //This will be stored in a separate file
			-0.1f, -0.1f, 0.0f,
			 0.1f, -0.1f, 0.0f,
			 0.0f,  0.1f, 0.0f
		};

		VertexArray va = {
			vertexData, //data
			sizeof(vertexData) / sizeof(float), //count
			0, //startingOffset
			0 //stride
		};

		m_mesh = std::make_shared<Mesh>(va);

		m_shader =std::make_shared<Shader>("./shaders/vertexShader.vert", "./shaders/fragShader.frag");
		m_modelMatrix = glm::translate(m_modelMatrix,glm::vec3((float)(window->getWidth())/2, (float)(window->getHeight())/9,0.0f));
		m_modelMatrix = glm::scale(m_modelMatrix, glm::vec3(500,500,0.0));
	}

	void Player::move(const char* direction, const float amount){
		if (std::string("left").compare(direction) == 0)
				m_modelMatrix = glm::translate(m_modelMatrix, glm::vec3(amount,0.0f,0.0f));
		if (std::string("right").compare(direction) == 0)
				m_modelMatrix = glm::translate(m_modelMatrix, glm::vec3(-amount,0.0f,0.0f));
	}

	void Player::move(const glm::vec3 vector){
		m_modelMatrix = glm::translate(m_modelMatrix, vector);
	}
}
