#pragma once
 
#include "Mesh.h"
#include "Shader.h"
#include <cstdint>
#include <memory>
namespace Game {

	class GameObject {
		public:
			GameObject( const char* name,
									std::shared_ptr<Mesh> mesh,
									std::shared_ptr<Shader> shader);

			GameObject(const char* name); 

			glm::mat4 getModelMatrix();
			std::string getName();
			uint32_t getId();
			std::shared_ptr<Mesh> getMesh();
			std::shared_ptr<Shader> getShader();

		protected:
			uint32_t m_id; 
			std::string m_name; 

			glm::mat4 m_modelMatrix;
			glm::vec3 m_position;
			//glm::vec3 m_speed; //Not sure if I need this 
			
			//Since GameObject will store the shared_ptrs, it guarantees
			//That the mesh and shader will at least exist until the GameObject is destroyed	
			std::shared_ptr<Mesh> m_mesh; 
			std::shared_ptr<Shader> m_shader;

		private:
			static uint32_t s_idCounter;
	};
}
