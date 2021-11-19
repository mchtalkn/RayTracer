#include "SceneHandler.h"
using namespace parser;
Scene parser::scene;
SceneHandler::SceneHandler(string input)
{
    scene.loadFromXml(input);
	for (Camera& c : scene.cameras) {
		cameras.push_back(CameraHandler(c));
	}
    for (Sphere& s : scene.spheres) {
        s.center_vertex = scene.vertex_data[s.center_vertex_id];
        s.material = scene.materials[s.material_id];
    }
    for (Triangle& t : scene.triangles) {
        t.material = scene.materials[t.material_id];

        Vec3f a = parser::scene.vertex_data[ t.indices.v0_id];
        Vec3f b = parser::scene.vertex_data[t.indices.v1_id];
        Vec3f c = parser::scene.vertex_data[t.indices.v2_id];

        t.indices.normal = crossProduct((c-b), (a-b));
    }
    for (Mesh& m : scene.meshes) {
        m.material = scene.materials[m.material_id];
    }
}

void SceneHandler::render()
{
	for (CameraHandler& c : cameras) c.render();
}
