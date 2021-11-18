#include "CameraHandler.h"
#include "ppm.h"

CameraHandler::CameraHandler(Camera& cam) : camera(cam)
{
	w = -1 * camera.gaze;
	v = camera.up;
	u = crossProduct(u, w);
	float left, right, top, bottom;
	left = cam.near_plane.x;
	right = cam.near_plane.y;
	bottom = cam.near_plane.z;
	top = cam.near_plane.w;
	Vec3f m = cam.gaze + (cam.gaze * cam.near_distance);
	q = m + u * left + v * right;
	suConstant = (right - left) / cam.image_width;
	svConstant = (top - bottom) / cam.image_height;
	e = cam.position;
	image =(Vec3i*)malloc(sizeof(Vec3f)*nx*ny);
}

Ray CameraHandler::generateRay(int i, int j)
{
	float su, sv;
	Vec3f s;
	su = (i + 0.5) * suConstant;
	sv = (i + 0.5) * svConstant;
	s = q + u * su + v * sv;
	Ray ray(e, s);
	return ray;
}

Ray CameraHandler::generateRay()
{
	
	return Ray();
}

void CameraHandler::render()
{
	Ray r;
	float t,tmpt;
	Sphere* sphere = nullptr;
	Triangle* triange = nullptr;
	Mesh* mesh=nullptr;
	int sphereid, triangeid, mehsid,bestType = 0;
	for (int j = 0; j < ny; j++) {
		for (int i = 0; i < nx; i++) {
			r = generateRay(i, j);
			Vec3f rgbf = r.calculateColor(camera.near_distance);
			Vec3i rgbi;
			// min max might be checked if neccessary and not checked in calculate color
			rgbi.x = rgbf.x;
			rgbi.y = rgbf.y;
			rgbi.z = rgbf.z;
			image[ny * j + nx * i] = rgbi;
		}
	}
	write_ppm(camera.image_name.c_str(),(unsigned char*) image, camera.image_width, camera.image_height);
}
