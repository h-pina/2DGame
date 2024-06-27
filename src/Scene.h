#pragma once
#include "Player.h"
#include "GameObject.h"
#include "Window.h"
#include <memory>
#include <unordered_map>
#include <vector>

namespace Game {

	class Scene{
		public:	
			Scene(Window* window);
			std::shared_ptr<Player> getPlayer();
			std::vector<std::shared_ptr<GameObject>>& getGameObjects();
		private:
			Window* m_window;
			std::shared_ptr<Player> m_player;
			std::vector<std::shared_ptr<GameObject>> m_gameObjects; 

			void initializeGameObjects();
	};
}
