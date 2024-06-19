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
		Shader shader("./shaders/vertexShader.vert",
						"./shaders/fragShader.frag");
		player.create(vertexData, 9);
		GameObject go("playertest", player, shader);
		m_gameObjects.push_back(go);
	}

}
