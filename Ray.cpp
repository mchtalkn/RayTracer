#include "Ray.h"
#include "Algebra.h"
#include "math.h"
#include <limits>
using namespace std;
using namespace parser;
Ray::Ray()
{
}

Ray::Ray(const Vec3f& e_, const Vec3f& d_):e(e_),d(d_),recursion(parser::scene.max_recursion_depth)
{
}

inline Vec3f Ray::positionT(float t)
{
    return e+d*t;
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
    if(discriminant < scene.shadow_ray_epsilon ) return -1;

    float t1 = (-B + sqrt(discriminant) ) / (2*A) ;
    float t2 = (-B - sqrt(discriminant) ) / (2*A) ;
    return t1<t2 ? t1 : t2;
}

/* returns -1 if the plane and the ray are perpendicular.
 * to eachother.
*/
float Ray::intersect(const Face& f)
{
    float product = dotProduct( f.normal, this->d);
    if( product < scene.shadow_ray_epsilon) return -1;
    Vec3f a = scene.vertex_data[f.v0_id];
    float t = (dotProduct(f.normal , (a-this->e))) / product;
    return t;
}

float Ray::intersect(const Vec3f& position)
{
	return (e.x - position.x)/d.x;
}

/*
 * verify intersection of the ray in the proper range.
*/
bool Ray::checkObstacle(float minDistance, float maxDistance)
{
	float t ; //= std::numeric_limits<float>::max();
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



Vec3f Ray::calculateColor(const Vec3f& intersection, const Vec3f& normal, const Material& material)
{
	return hadamardProduct(scene.ambient_light,material.ambient) + calculateDiffuse(intersection, normal, material) + calculateSpecular(intersection, normal, material);
}

/* minDistance = epsilon
 * for recursion level 1, minDistance = distance of scene
 */
Vec3f Ray::calculateColor(float minDistance)
{
	float t = std::numeric_limits<float>::max(), tmpt = 0;
	Vec3f color,normal,intersection;
	color.x = scene.background_color.x;
	color.y = scene.background_color.y;
	color.z = scene.background_color.z;
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
		color.x = scene.background_color.x;
		color.y = scene.background_color.y;
		color.z = scene.background_color.z;
		return color;
	}
	intersection = positionT(t);
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
