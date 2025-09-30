#include "loader.h"
#include <iostream>

int main()
{
    ynobj::ObjReader         reader;
    ynobj::ObjReader::Config config;
    config.triangulate = true;
    config.mtl_search_path = "./assets/materials";

    reader.parseFromFile("./assets/sample.obj", config);
    ynobj::VertexAttrib          attrib = reader.getVertexAttrib();
    std::vector<ynobj::Material> mats = reader.getMaterials();

    // print attributes
    unsigned int n_vertices = attrib.coords.size() / 3;
    std::cout << "count of vertices: " << n_vertices << '\n';
    for (int i = 0; i < n_vertices; i++)
    {
        std::cout << attrib.coords[i * 3] << ", " << attrib.coords[i * 3 + 1] << ", "
                  << attrib.coords[i * 3 + 2] << ", " << attrib.coords_w[i * 3] << '\n';
    }

    // todo
    // print materials
    // print shapes
}