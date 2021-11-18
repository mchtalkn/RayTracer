#pragma once
#include "Ray.h"
using namespace parser;
class CameraHandler
{
public:
	Camera& camera;
	Vec3f q,u,v,w,e;
	int nx, ny;
	float suConstant, svConstant;
	int pixelId = 0;
	CameraHandler(Camera& camera);
	Ray generateRay(int i, int j);
	Ray generateRay(); // bunu simdilik implement etmeye gerek yok optimizasyon için ileride bi bakýlýr
	void render();

};
