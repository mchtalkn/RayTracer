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
	SceneHandler();
	vector<CameraHandler> cameras;
	void render();
};
