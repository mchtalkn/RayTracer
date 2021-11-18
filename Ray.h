#pragma once
#include "Algebra.h"

class Ray
{
public:
	Vec3f e;
	Vec3f d;
	int recursion;
	Ray();
	Ray(Vec3f& e, Vec3f& d);

	Vec3f positionT(float t);   // returns: ray'in t'ye gore x-y-z koordinatlari

    float intersect(Sphere& s); // returns t
    float intersect(Face& f);

	Vec3f calculateColor(Sphere& s);// returns: RGB
	Vec3f calculateColor(Face& f);
	Vec3f calculateColor(Vec3f& intersection, Vec3f& normal, Material& material);
	Vec3f calculateColor(float minDistance);
	Vec3f calculateDiffuse(Vec3f& intersection, Vec3f& normal, Material& material);
	Vec3f calculateSpecular(Vec3f& intersection, Vec3f& normal, Material& material);
	Ray generateReflection(Vec3f position, Vec3f normal);
};

