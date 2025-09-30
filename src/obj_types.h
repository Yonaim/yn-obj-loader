#pragma once
#include <vector>
#include <map>

namespace ynobj
{
    typedef float real_t;

    struct Material
    {
        real_t ka;
        real_t kd;
        real_t ns;
        real_t ni;
        real_t d;
        real_t illum;
    };

    // Vertex attributes
    // default w value 
    struct VertexAttrib
    {
        std::vector<real_t> coords;      // 'v' (x y z)
        std::vector<real_t> coords_w;    // 'v' (w)
        std::vector<real_t> normals;     // 'vn' (x y z)
        std::vector<real_t> texcoords;   // 'vt' (uv)
        std::vector<real_t> texcoords_w; // 'vt' (uv)
    };
} // namespace ynobj
