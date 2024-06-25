#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"

namespace Game {
	Mesh::Mesh(VertexArray vertexArray){
		m_vertexArrayConfig = vertexArray;

		glGenVertexArrays(1, &m_vao);
		addVBOToVAO(vertexArray);
		glBindVertexArray(0); //unbind to avoid conflicts
	}

	Mesh::Mesh(VertexArray vertexArray, IndexArray indexArray){
		m_vertexArrayConfig = vertexArray;
		m_indexArrayConfig = indexArray;

		glGenVertexArrays(1, &m_vao);
		addVBOToVAO(vertexArray);
		addIndexToVAO(indexArray);
		glBindVertexArray(0); //unbind to avoid conflicts
	}
	
	void Mesh::addVBOToVAO(VertexArray vertexArray){
		GLuint vbo;
		glGenBuffers(1, &vbo);

		glBindVertexArray(m_vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		
    glBufferData(GL_ARRAY_BUFFER, vertexArray.count * sizeof(float), vertexArray.data, GL_STATIC_DRAW);
    glVertexAttribPointer(0, vertexArray.count, GL_FLOAT, GL_FALSE, 
													vertexArray.stride, 0); //TODO:How to pass this offset?
		glEnableVertexAttribArray(0);
	}

	void Mesh::addIndexToVAO(IndexArray indexArray){
		//TODO
	}

	void Mesh::use(){
		glBindVertexArray(m_vao);
	}

}


