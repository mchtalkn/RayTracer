#include "Ray.h"
#include "Algebra.h"

Ray::Ray()
{
}

Ray::Ray(Vec3f& e_, Vec3f& d_):e(e_),d(d_),recursion(parser::scene.max_recursion_depth)
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


Vec3f Ray::calculateColor(Sphere& s)
{
    return Vec3f();
}

Vec3f Ray::calculateColor(Face& f)
{
	return Vec3f();
}

Vec3f Ray::calculateColor(Vec3f& intersection, Vec3f& normal, Material& material)
{
    return Vec3f();
}

Vec3f Ray::calculateColor(float minDistance)
{
	float t, tmpt;
	Vec3f color,normal,intersection;
	color.x = 0;
	color.y = 0;
	color.z = 0;
	if (recursion == -1) return color;
	Ray newRay = *this;
	newRay.recursion--;
	Sphere* sphere = nullptr;
	Triangle* triange = nullptr;
	Mesh* mesh = nullptr;
	Face* face = nullptr;
	int bestType = 0;
	
	for (Sphere& s : parser::scene.spheres) {
		tmpt = intersect(s);
		if (tmpt > minDistance && tmpt < t) {
			t = tmpt;
			sphere = &s;
			bestType = 1;
		}
	}
	for (Triangle& tr : parser::scene.triangles) {
		Face& f = tr.indices;
		tmpt = intersect(f);
		if (tmpt > minDistance && tmpt < t) {
			t = tmpt;
			face = &f;
			bestType = 2;
		}
	}
	for (Mesh& m : parser::scene.meshes) {
		for (Face& f : m.faces) {
			tmpt = intersect(f);
			if (tmpt > minDistance && tmpt < t) {
				t = tmpt;
				face = &f;
				bestType = 2;
			}
		}	
	}
	switch (bestType)
	{
	case 0:
		return color;
		break;
	case 1:
		color = calculateColor(*sphere);

		break;
	case 2:
		color = calculateColor(*face);
		break;
	default:
		break;
	}
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
