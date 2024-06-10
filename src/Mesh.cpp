#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"
#include <cstddef>

namespace Game {

	void Mesh::create(const float* vertexData, size_t dataSize){
		m_vertexCount = dataSize;
		GLuint vbo;
		glGenVertexArrays(1, &m_vao);
		glGenBuffers(1, &vbo);

		glBindVertexArray(m_vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		
    glBufferData(GL_ARRAY_BUFFER, dataSize * sizeof(float), vertexData, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0); //unbind to avoid conflicts
	}

	void Mesh::use(){
		glBindVertexArray(m_vao);
	}

	//TODO: Create a mesh  destructor

}


