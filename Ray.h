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

    float intersect(const Sphere& s); // returns t
    float intersect(const Face& f);
	float intersect(const Vec3f& position);

	Vec3f calculateColor(const Sphere& s);// returns: RGB
	Vec3f calculateColor(const Face& f);
	Vec3f calculateColor(const Vec3f& intersection, const Vec3f& normal, const Material& material);
	Vec3f calculateColor(float minDistance);
	Vec3f calculateDiffuse(const Vec3f& intersection, const Vec3f& normal, const Material& material);
	Vec3f calculateSpecular(const Vec3f& intersection, const Vec3f& normal, const Material& material);
	Ray generateReflection(const Vec3f& position, const Vec3f& normal);
};

