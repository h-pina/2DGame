#pragma once

#include <cstddef>
#include <cstdint>
#include "GLFW/glfw3.h"

namespace Game {
	
	struct VertexArray{
		float* data;
		uint32_t count;
		uint32_t startingOffset;
		uint32_t stride;
	};

	struct IndexArray{
		float* data;
		//...
	};

	class Mesh {
		public:
			VertexArray m_vertexArrayConfig;
			IndexArray m_indexArrayConfig;

			Mesh(VertexArray vertexArray);
			Mesh(VertexArray vertexArray, IndexArray indexArray);
			
			void use();
			void getVAO();

		private:
			void addVBOToVAO(VertexArray vertexArray);
			void addIndexToVAO(IndexArray indexArray);
			GLuint m_vao;
	

	};

}
