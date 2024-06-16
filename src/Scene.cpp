#include "Scene.h"
#include "GameObject.h"

namespace Game {

	Scene::Scene(){
		float vertexData[] = { //This will be stored in a separate file
			-0.1f, -0.1f, 0.0f,
			 0.1f, -0.1f, 0.0f,
			 0.0f,  0.1f, 0.0f
		};
		Mesh player;
		Shader shader("/home/p/u/dev/2d-game/src/shaders/vertexShader.vert",
						"/home/p/u/dev/2d-game/src/shaders/fragShader.frag");
		player.create(vertexData, 9);
		GameObject go("player", player, shader);
		m_gameObjects.push_back(go);
	}

	std::vector<GameObject> Scene::getGameObjects(){
		return m_gameObjects;
	}	

	

}
