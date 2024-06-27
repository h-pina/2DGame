#include "Scene.h"
#include "Player.h"
#include <memory>

namespace Game {
	Scene::Scene(Window* window)
		:	m_window(window)
	{
		//Created a separate function to avoid clustering the constructor
		initializeGameObjects();
	}

	std::shared_ptr<Player> Scene::getPlayer(){
		return m_player;
	}
	
	std::vector<std::shared_ptr<GameObject>>& Scene::getGameObjects(){
		return m_gameObjects;
	}

	void Scene::initializeGameObjects(){
		m_player = std::make_shared<Player>(m_window);
		m_gameObjects.push_back(m_player);
	}

	

}
