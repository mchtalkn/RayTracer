#include "SceneHandler.h"

Scene SceneHandler::scene;
SceneHandler::SceneHandler(Scene& s)
{
	scene = s;
	for (Camera& c : scene.cameras) {
		cameras.push_back(CameraHandler(c));
	}
}

void SceneHandler::render()
{
	for (CameraHandler& c : cameras) c.render();
}
