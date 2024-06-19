#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"

namespace Game {
	Mesh::Mesh(VertexArray vertexArray){
		glGenVertexArrays(1, &m_vao);
		addVBOToVAO(vertexData, vertexDataSize);
		glBindVertexArray(0); //unbind to avoid conflicts
	}

	Mesh::Mesh(const float* vertexData, size_t vertexDataSize, const float* indexData, size_t indexDataSize){

		m_vertexCount = vertexDataSize;
		m_indexCount = indexDataSize;

		glGenVertexArrays(1, &m_vao);
		addVBOToVAO(vertexData, vertexDataSize);
		addIndexToVAO(indexData, indexDataSize);
		glBindVertexArray(0); //unbind to avoid conflicts
	}
	
	void Mesh::addVBOToVAO(const float* vertexData, size_t vertexDataSize){
		GLuint vbo;
		glGenBuffers(1, &vbo);

		glBindVertexArray(m_vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		
    glBufferData(GL_ARRAY_BUFFER, vertexDataSize * sizeof(float), vertexData, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);
	}

	void Mesh::addIndexToVAO(const float* vertexData, size_t vertexDataSize){
		//TODO
	}

	void Mesh::use(){
		glBindVertexArray(m_vao);
	}
	//TODO: Create a mesh  destructor

}


