#include "CameraHandler.h"
#include "ppm.h"
#include <iostream>
#include "math.h"
#include <chrono>

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
	Ray ray(e, s - e);
	return ray;
}

Ray CameraHandler::generateRay()
{
	
	return Ray();
}

void CameraHandler::render()
{
	auto t_start = std::chrono::high_resolution_clock::now();
	
	cout << "rendering for file: " << camera.image_name<< " started at time" << endl;
	Ray r;
	for (int j = 0; j < ny; j++) {
		for (int i = 0; i < nx; i++) {
			if ( (i == 0) && (((j*100) % ny/100*100) == 0)) {
				auto t_end = std::chrono::high_resolution_clock::now();
				double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
				cout << "rendering... %" << ((j * 100) / nx) << " completed elapsed time: "<<(int) elapsed_time_ms/60/1000 << " minutes "<< ((int)elapsed_time_ms/1000%60)<<" seconds " << endl;
			}
			r = generateRay(i, j);
			Vec3f rgbf = r.calculateColor(1); // as rays are not normalized it should be 1 not neardistance
			if (rgbf.x < 0 || rgbf.x > 255 || rgbf.y < 0 || rgbf.y > 255 || rgbf.z < 0 || rgbf.z > 255) {
				rgbf.x = min(255, max(0,(int) rgbf.x));
				rgbf.y = min(255, max(0, (int)rgbf.y));
				rgbf.z = min(255, max(0, (int)rgbf.z));
			}
			// min max might be checked if neccessary if not checked in calculate color
			image[(nx * j + i)*3] = rgbf.x;
			image[(nx * j + i)*3 + 1] = rgbf.y;
			image[(nx * j + i)*3 + 2] = rgbf.z;
		}
	}
	write_ppm(camera.image_name.c_str(),(unsigned char*) image, camera.image_width, camera.image_height);
}

