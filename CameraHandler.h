#pragma once
#include "Ray.h"
using namespace parser;
class CameraHandler
{
	Camera camera;
	int pixelId = 0;
	Ray generateRay(int i, int j);
	Ray generateRay(); // bunu simdilik implement etmeye gerek yok optimizasyon i�in ileride bi bak�l�r
	void render();

};
