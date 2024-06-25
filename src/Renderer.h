#pragma once

#include <GLFW/glfw3.h>
#include "Scene.h"
#include "GameObject.h"
#include "Application.h"

namespace Game {

	class Renderer {
		public:
			Renderer(Window* window, Scene* scene);
			void renderFrame();

		private:
			Window* m_window;
			Scene* m_scene;

			void executeDrawCalls();
			void renderGameObject();
		};

}

