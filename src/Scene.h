#pragma once
#include "GameObject.h"
#include <vector>

namespace Game {

	class Scene{
		public:	
		Scene();  
		//NOTE: Is this too much boilerplate?
		void addGameObject(GameObject go);
		std::vector<GameObject>* getGameObjects();

		private:
			std::vector<GameObject> m_gameObjects;

	};
}
