#include "Ray.h"

Ray::Ray(Vec3f& e, Vec3f& d)
{
}

Vec3f Ray::positionT(float t)
{
    return Vec3f();
}

float Ray::intersect(Sphere& s)
{
    return 0.0f;
}

float Ray::intersect(Face& f)
{
    return 0.0f;
}

float Ray::intersect(Mesh& m)
{
    return 0.0f;
}

float Ray::intersect(Triangle& t)
{
    return 0.0f;
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
    return Vec3f();
}
