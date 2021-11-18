#include "Ray.h"
#include "Algebra.h"

Ray::Ray()
{
}

Ray::Ray(Vec3f& e_, Vec3f& d_):e(e_),d(d_)
{
}

Vec3f Ray::positionT(float t)
{
    return Vec3f();
}

float Ray::intersect(Sphere& s)
{
    return 0;
}

float Ray::intersect(Face& f)
{
    return 0;
}

float Ray::intersect(Mesh& m)
{
    return 0;
}

float Ray::intersect(Triangle& t)
{
    return 0;
}

Vec3f Ray::calculateColor(Sphere& s)
{
    return Vec3f();
}

Vec3f Ray::calculateColor(Mesh& m)
{
    return Vec3f();
}

Vec3f Ray::calculateColor(Triangle& t)
{
    return Vec3f();
}

Vec3f Ray::calculateColor(Vec3f& intersection, Vec3f& normal, Material& material)
{
    return Vec3f();
}

Vec3f Ray::calculateColor()
{
	/*
	for (Sphere& s : parser::scene.spheres) {
		tmpt = r.intersect(s);
		if (tmpt > camera.near_distance && tmpt < t) {
			t = tmpt;
			sphere = &s;
			bestType = 1;
		}
	}
	for (Triangle& tr : parser::scene.triangles) {
		tmpt = r.intersect(tr);
		if (tmpt > camera.near_distance && tmpt < t) {
			t = tmpt;
			triange = &tr;
			bestType = 2;
		}
	}
	for (Sphere& s : parser::scene.spheres) {
		tmpt = r.intersect(s);
		if (tmpt > camera.near_distance && tmpt < t) {
			t = tmpt;
			sphere = &s;
			bestType = 3;
		}
	}*/
    return Vec3f();
}

Vec3f Ray::calculateDiffuse(Vec3f& intersection, Vec3f& normal, Material& material)
{
    return Vec3f();
}

Vec3f Ray::calculateSpecular(Vec3f& intersection, Vec3f& normal, Material& material)
{
    return Vec3f();
}
