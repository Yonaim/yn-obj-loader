#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "obj_primitives.h"
#include "obj_types.h"

namespace ynobj
{
    // group or object
    struct Shape
    {
        std::string name;
        Mesh        mesh;   // faces (f)
        Lines       lines;  // lines (l)
        Points      points; // points (p)
    };

    class MtlReader
    {
        bool parseFromIstream(std::istream &is, std::vector<Material> &materials,
                              std::map<std::string, int> &matMap);
        bool parseFromFile(const std::string &path, std::vector<Material> &materials,
                           std::map<std::string, int> &matMap);
        bool parseFromText(const std::string &text, std::map<std::string, int> &matMap);
    };

    class ObjReader
    {
      private:
        // global data
        VertexAttrib          _attrib;
        std::vector<Material> _mats; // access by index

        // non-global data
        std::vector<Shape> _shapes;

      public:
        struct Config
        {
            bool        triangulate;
            std::string mtl_search_path;

            Config() : triangulate(true), mtl_search_path("") {}
        };

        // parsing API
        bool parseFromIstream(std::istream &is, const Config &config = Config());
        bool parseFromFile(const std::string &path, const Config &config = Config());
        bool parseFromText(const std::string &text, const Config &config = Config());

        // get parsed data
        VertexAttrib          &getVertexAttrib();
        std::vector<Material> &getMaterials();
        std::vector<Shape>    &getShapes();
    };

} // namespace ynobj
