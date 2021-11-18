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
	int bestType = 0;
	
	for (Sphere& s : parser::scene.spheres) {
		tmpt = intersect(s);
		if (tmpt > minDistance && tmpt < t) {
			t = tmpt;
			sphere = &s;
			material = &s.material; 
			normal = intersection - sphere->center_vertex;
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
			}
		}	
	}
	color = calculateColor(intersection, normal, *material);
	if (recursion != 0 && !material->is_mirror ) {
		newRay = generateReflection(intersection, normal);
		Vec3f reflectionColor = newRay.calculateColor(parser::scene.shadow_ray_epsilon);
		return color + hadamardProduct(reflectionColor, material->mirror);
	}
    else return color;
}

Vec3f Ray::calculateDiffuse(Vec3f& intersection, Vec3f& normal, Material& material)
{
    return Vec3f();
}

Vec3f Ray::calculateSpecular(Vec3f& intersection, Vec3f& normal, Material& material)
{
    return Vec3f();
}

Ray Ray::generateReflection(Vec3f position, Vec3f normal)
{
	return Ray();
}
