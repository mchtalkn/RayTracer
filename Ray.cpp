#include "Ray.h"
#include "Algebra.h"
#include "math.h"
using namespace std;
using namespace parser;
Ray::Ray()
{
}

Ray::Ray(const Vec3f& e_, const Vec3f& d_):e(e_),d(d_),recursion(parser::scene.max_recursion_depth)
{
}

Vec3f Ray::positionT(float t)
{
    return Vec3f();
}

/* return -1 if does not intersect.
 *
*/
float Ray::intersect(const Sphere& s)
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

float Ray::intersect(const Face& f)
{
    return 0;
}

float Ray::intersect(const Vec3f& position)
{
	return (e.x - position.x)/d.x;
}

bool Ray::checkObstacle(float minDistance, float maxDistance)
{
	float t;
	for (Sphere& s : parser::scene.spheres) {
		t = intersect(s);
		if (t > minDistance && t < maxDistance) {
			return true;
		}
	}
	for (Triangle& tr : parser::scene.triangles) {
		Face& f = tr.indices;
		t = intersect(f);
		if (t > minDistance && t < maxDistance) {
			return true;
		}
	}
	for (Mesh& m : parser::scene.meshes) {
		for (Face& f : m.faces) {
			t = intersect(f);
			if (t > minDistance && t < maxDistance) {
				return true;
			}
		}
	}
	return false;
}


Vec3f Ray::calculateColor(const Sphere& s)
{
    return Vec3f();
}

Vec3f Ray::calculateColor(const Face& f)
{
	return Vec3f();
}

Vec3f Ray::calculateColor(const Vec3f& intersection, const Vec3f& normal, const Material& material)
{

	return hadamardProduct(scene.ambient_light,material.ambient) + calculateDiffuse(intersection, normal, material) + calculateSpecular(intersection, normal, material);
}

Vec3f Ray::calculateColor(float minDistance)
{
	float t, tmpt,reflectionConstant;
	Vec3f color,normal,intersection,position;
	color.x = 0;
	color.y = 0;
	color.z = 0;
	if (recursion == -1) return color;
	Ray newRay;
	Sphere* sphere = nullptr;
	Triangle* triange = nullptr;
	Mesh* mesh = nullptr;
	Face* face = nullptr;
	Material* material;
	bool intersected = false;
	for (Sphere& s : parser::scene.spheres) {
		tmpt = intersect(s);
		if (tmpt > minDistance && tmpt < t) {
			t = tmpt;
			sphere = &s;
			material = &s.material; 
			normal = (intersection - sphere->center_vertex)/sphere->radius;
			intersected = true;
		}
	}
	for (Triangle& tr : parser::scene.triangles) {
		Face& f = tr.indices;
		tmpt = intersect(f);
		if (tmpt > minDistance && tmpt < t) {
			t = tmpt;
			face = &f;
			material = &tr.material; 
			normal = face->normal;
			intersected = true;
		}
	}
	for (Mesh& m : parser::scene.meshes) {
		for (Face& f : m.faces) {
			tmpt = intersect(f);
			if (tmpt > minDistance && tmpt < t) {
				t = tmpt;
				face = &f;
				material = &m.material; 
				normal = face->normal;
				intersected = true;
			}
		}	
	}
	if (intersected == false) {
		color.x = -1;
		color.y = -1;
		color.z = -1;
		return color;
	}
	color = calculateColor(intersection, normal, *material);
	if (recursion != 0 && material->is_mirror ) {
		newRay = generateReflection(intersection, normal);
		Vec3f reflectionColor = newRay.calculateColor(parser::scene.shadow_ray_epsilon);
		return color + hadamardProduct(reflectionColor, material->mirror);
	}
    else return color;
}

Vec3f Ray::calculateDiffuse(const Vec3f& intersection, const Vec3f& normal, const Material& material)
{
	float cos;
	Vec3f  diffuse;
	diffuse.x = 0;
	diffuse.y = 0;
	diffuse.z = 0;
	Vec3f diffuseAdd(diffuse);
	for (PointLight& l : scene.point_lights) {
		float distance = calculateDistance(l.position, intersection);
		Ray r(intersection, (l.position - intersection) / distance);
		if (!r.checkObstacle(scene.shadow_ray_epsilon, distance)) {
			cos = max((float)0.0, dotProduct(r.d, normal));
			diffuseAdd = (cos / (distance * distance)) * l.intensity;
			diffuse = diffuse + diffuseAdd;
		}
	}
    return hadamardProduct( diffuse,material.diffuse);
}

Vec3f Ray::calculateSpecular(const Vec3f& intersection, const  Vec3f& normal, const Material& material)
{
	float cos;
	Vec3f spec, half;
	spec.x = 0;
	spec.y = 0;
	spec.z = 0;
	Vec3f specAdd(spec);
	for (PointLight& l : scene.point_lights) {
		float distance = calculateDistance(l.position, intersection);
		Ray r(intersection, (l.position - intersection) / distance);
		if (!r.checkObstacle(scene.shadow_ray_epsilon, distance)) {
			half = r.d - d;
			half = normalize(half);
			cos = max((float)0.0, dotProduct(normal, half));
			specAdd = (pow(cos,material.phong_exponent) / (distance * distance)) * l.intensity;
			spec = spec + specAdd;
		}
	}
    return hadamardProduct(spec, material.specular);
}

Ray Ray::generateReflection(const Vec3f& position, const Vec3f& normal)
{
	Vec3f reflectionD;
	float cos = dotProduct(normal, -1 * d);
	reflectionD = d + 2 * normal * cos;
	Ray r(position, reflectionD);
	r.recursion = recursion - 1;
	return r;
}
