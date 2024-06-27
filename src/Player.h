#pragma once 

#include "GameObject.h"
#include "Window.h"
#include <cstdint>

namespace Game {
	class Player : public GameObject{

		public:
			Player(Window* window);
			void move(const char* direction, const float amount);
			void move(const glm::vec3 vector);

		private:
			uint32_t m_health;
	};
}


