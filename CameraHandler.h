#pragma once
#include "Ray.h"
using namespace parser;
class CameraHandler
{
	Camera camera;
	int pixelId = 0;
	Ray generateRay(int i, int j);
	Ray generateRay();
	void render();

};
