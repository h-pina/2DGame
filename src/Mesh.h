#include <cstddef>
#include <cstdint>
namespace Game {
	class Mesh {
		public:
			size_t m_vertexCount;
			uint32_t m_vao;

			void create(const float* vertexData, size_t dataSize);
			void use();
		private:
	

	};

}
