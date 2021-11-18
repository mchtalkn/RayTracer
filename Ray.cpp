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

/* return -1 if does not intersect.
 *
*/
float Ray::intersect(Sphere& s)
{
    Vec3f diff = s.center_vertex - this->e;
    float B = 2 * dotProduct(this->d,  diff );
    float A = dotProduct(this->d , this->d );
    float C = dotProduct(diff, diff ) - s.radius*s.radius;

    float discriminant = B*B - 4*A*C;
    if(discriminant < 0 ) return -1;

    float t1 = (-B + sqrt(discriminant) ) / (2*A) ;
    float t2 = (-B - sqrt(discriminant) ) / (2*A) ;
    return t1<t2 ? t1 : t2;
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
