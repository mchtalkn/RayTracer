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
    float intersect(Mesh& m);
    float intersect(Triangle& t);

	Vec3f calculateColor(Sphere& s);    // returns: RGB
	Vec3f calculateColor(Mesh& m);      // face'lerden olusan bir materyal
	Vec3f calculateColor(Triangle& t);  // tek bir face'ten olusan obje

	Vec3f calculateColor(Vec3f& intersection, Vec3f& normal, Material& material);
	Vec3f calculateColor();

	Vec3f calculateDiffuse(Vec3f& intersection, Vec3f& normal, Material& material);
	Vec3f calculateSpecular(Vec3f& intersection, Vec3f& normal, Material& material);
};

