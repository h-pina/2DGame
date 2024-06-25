#pragma once
#include "GameObject.h"
#include <unordered_map>
#include <vector>

namespace Game {

	class Scene{
		public:	
			Scene();  

		private:
			std::unordered_map<uint32_t, GameObject> m_gameObjects;

			void initializeGameObjects();
	};
}
