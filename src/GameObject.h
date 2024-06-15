#include "Mesh.h"
#include "Shader.h"
#include <cstdint>
namespace Game {
	struct DrawCallSpecs{
		int vertexNum;
		//.... Based on possible parameters for glDrawArrays
	};	

	class GameObject {
	public:
		GameObject();
		void setupGLStateForRender();
		void move();
		

	private:
		Mesh m_mesh;
		Shader m_shader;
		//Texture2D m_tex2d:
		DrawCallSpecs m_renderSpecs;

		float m_position;
		//....
	
	};
}
