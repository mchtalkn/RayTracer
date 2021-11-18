#pragma once
#include "parser.h"
#include "CameraHandler.h"
#include <vector>
#include "Algebra.h"
using namespace parser;
using namespace std;

class SceneHandler
{
public:
	static Scene scene;
	vector<CameraHandler> cameras;
	SceneHandler(Scene& s);
	void render();
};
