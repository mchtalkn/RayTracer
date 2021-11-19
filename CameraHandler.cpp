#include "CameraHandler.h"
#include "ppm.h"
#include <iostream>
#include "math.h"
using namespace std;
CameraHandler::CameraHandler(Camera& cam) : camera(cam)
{
	w = -1 * camera.gaze;
	v = camera.up;
	u = crossProduct(v, w);
	float left, right, top, bottom;
	left = cam.near_plane.x;
	right = cam.near_plane.y;
	bottom = cam.near_plane.z;
	top = cam.near_plane.w;
	Vec3f m = cam.position + (cam.gaze * cam.near_distance);
	q = m + u * left + v * top;
	suConstant = (right - left) / cam.image_width;
	svConstant = (top - bottom) / cam.image_height;
	e = cam.position;
	nx = cam.image_width;
	ny = cam.image_height;
	image = new unsigned char[nx*ny*3];
}

Ray CameraHandler::generateRay(int i, int j)
{
	float su, sv;
	Vec3f s;
	su = (i + 0.5) * suConstant;
	sv = (j + 0.5) * svConstant;
	s = q + u * su - v * sv;
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
	for (int j = 0; j < ny; j++) {
		for (int i = 0; i < nx; i++) {
			if (i == nx / 2 && j == ny / 2) {
				int tmp = 0;
			}
			r = generateRay(i, j);
			Vec3f rgbf = r.calculateColor(camera.near_distance);
			if (rgbf.x < 0 || rgbf.x > 255 || rgbf.y < 0 || rgbf.y > 255 || rgbf.z < 0 || rgbf.z > 255) {
				rgbf.x = min(255, max(0,(int) rgbf.x));
				rgbf.y = min(255, max(0, (int)rgbf.y));
				rgbf.z = min(255, max(0, (int)rgbf.z));
				std::cout << "rgbf: " << j << ", " << i << " : " << "( " << rgbf.x << " , " << rgbf.y << " , " << rgbf.z << std::endl;
			}
			// min max might be checked if neccessary if not checked in calculate color
			image[(ny * j +  i)*3] = rgbf.x;
			image[(ny * j + i)*3 + 1] = rgbf.y;
			image[(ny * j + i)*3 + 2] = rgbf.z;
		}
	}
	write_ppm(camera.image_name.c_str(),(unsigned char*) image, camera.image_width, camera.image_height);
}

