#include <iostream>
#include "ppm.h"
#include "Ray.h"
#include "Algebra.h"
#include "SceneHandler.h"
typedef unsigned char RGB[3];
using namespace parser;

int main(int argc, char* argv[])
{
    SceneHandler s(argv[1]);
    s.render();
}
