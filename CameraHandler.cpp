#include "CameraHandler.h"

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
}
