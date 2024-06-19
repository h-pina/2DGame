#pragma once
#include "GameObject.h"
#include <vector>

namespace Game {

	class Scene{
		public:	
		Scene();  
		void addGameObject(GameObject go);
		std::vector<GameObject>* getGameObjects();

		private:
			std::vector<GameObject> m_gameObjects;
	     
	};
}
