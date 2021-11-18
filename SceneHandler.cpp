#include "SceneHandler.h"
using namespace parser;
Scene parser::scene;
SceneHandler::SceneHandler()
{
	for (Camera& c : scene.cameras) {
		cameras.push_back(CameraHandler(c));
	}
    for (Sphere& s : scene.spheres) {
        s.center_vertex = scene.vertex_data[s.center_vertex_id];
        s.material = scene.materials[s.material_id];
    }
    for (Triangle& t : scene.triangles) {
        t.material = scene.materials[t.material_id];
    }
    for (Mesh& m : scene.meshes) {
        m.material = scene.materials[m.material_id];
    }
}

void SceneHandler::render()
{
	for (CameraHandler& c : cameras) c.render();
}
