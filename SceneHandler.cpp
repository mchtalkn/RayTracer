#include "SceneHandler.h"
using namespace parser;
Scene parser::scene;
SceneHandler::SceneHandler()
{
	for (Camera& c : scene.cameras) {
		cameras.push_back(CameraHandler(c));
	}
}

void SceneHandler::render()
{
	for (CameraHandler& c : cameras) c.render();
}
