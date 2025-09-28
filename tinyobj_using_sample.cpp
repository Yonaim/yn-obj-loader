// coded by AI

#include <iostream>
#include <string>
#include <vector>

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "사용법: " << argv[0] << " model.obj\n";
        return 1;
    }

    std::string inputfile = argv[1];
    tinyobj::ObjReaderConfig reader_config;
    reader_config.mtl_search_path = "./"; // MTL 파일 찾는 경로

    tinyobj::ObjReader reader;

    if (!reader.ParseFromFile(inputfile, reader_config)) {
        if (!reader.Error().empty()) {
            std::cerr << "TinyObjLoader 오류: " << reader.Error() << std::endl;
        }
        return 1;
    }

    if (!reader.Warning().empty()) {
        std::cout << "경고: " << reader.Warning() << std::endl;
    }

    const tinyobj::attrib_t& attrib = reader.GetAttrib();
    const std::vector<tinyobj::shape_t>& shapes = reader.GetShapes();
    const std::vector<tinyobj::material_t>& materials = reader.GetMaterials();

    // 버텍스 좌표 출력
    std::cout << "버텍스 개수: " << (attrib.vertices.size() / 3) << std::endl;
    for (size_t v = 0; v < attrib.vertices.size() / 3; v++) {
        std::cout << "v[" << v << "]: ("
                  << attrib.vertices[3 * v + 0] << ", "
                  << attrib.vertices[3 * v + 1] << ", "
                  << attrib.vertices[3 * v + 2] << ")\n";
    }

    // shape 단위로 face 정보 출력
    for (size_t s = 0; s < shapes.size(); s++) {
        size_t index_offset = 0;
        std::cout << "Shape: " << shapes[s].name << std::endl;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);

            std::cout << "  face[" << f << "]:";
            for (size_t v = 0; v < fv; v++) {
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                int vidx = idx.vertex_index;
                int nidx = idx.normal_index;
                int tidx = idx.texcoord_index;

                std::cout << " v" << vidx;
                if (tidx >= 0) std::cout << "/t" << tidx;
                if (nidx >= 0) std::cout << "/n" << nidx;
            }
            std::cout << "\n";
            index_offset += fv;
        }
    }

    return 0;
}
