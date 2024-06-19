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
			size_t m_vertexCount = 0;
			size_t m_indexCount = 0;

			Mesh(VertexArray vertexArray);

			Mesh(VertexArray vertexArray, IndexArray indexArray);
			
			void use();
			void getVAO();

		private:
			void addVBOToVAO(const float* vertexData, size_t vertexDataSize);
			void addIndexToVAO(const float* vertexData, size_t vertexDataSize);
			GLuint m_vao;
	

	};

}
