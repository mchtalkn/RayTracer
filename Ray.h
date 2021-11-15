#pragma once
#include "parser.h"

#ifndef GIT_RAY_H
#define GIT_RAY_H

using namespace parser;
class Ray
{
public:
	Vec3f e;
	Vec3f d;
	int recursion_level;
	Ray(Vec3f& e, Vec3f& d);
	Vec3f positionT(float t);

    float intersect(Sphere& s); // intersection coordinates ??
    float intersect(Face& f);
    float intersect(Mesh& m);
    float intersect(Triangle& t);

	Vec3f calculateColor(Sphere& s);
	Vec3f calculateColor(Mesh& m);
	Vec3f calculateColor(Triangle& t);
	Vec3f calculateColor(Vec3f& intersection, Vec3f& normal, Material& material);
	Vec3f calculateColor();
};

#endif //GIT_RAY_H