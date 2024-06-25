#pragma once 

#include "GameObject.h"
#include "Window.h"
#include <cstdint>

namespace Game {
	class Player : GameObject{

		public:
			Player(Window* window, std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader);
			void move(const char* direction, const float amount);
			void move(const glm::vec3 vector);

		private:
			uint32_t m_health;
	};
}


