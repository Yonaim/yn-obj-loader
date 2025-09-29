#include <map>
#include <string>
#include <vector>
#include <iostream>

namespace ynobj {

typedef float real_t;

// structures

struct Material {
    real_t ka;
    real_t kd;
    real_t kd;
    real_t ns;
    real_t ni;
    real_t d;
    real_t illum;
};

// Vertex attributes
struct VertexAttrib {
    std::vector<real_t> coords;      // 'v' (x y z)
    std::vector<real_t> coords_w;    // 'v' (w)
    std::vector<real_t> normals;     // 'vn' (x y z)
    std::vector<real_t> texcoords;   // 'vt' (uv)
    std::vector<real_t> texcoords_w; // 'vt' (uv)
};

struct GlobalData {
    VertexAttrib               attrib;
    std::vector<Material>      mats;   // access by index
    std::map<std::string, int> matMap; // <name, index>
};

// group or object
struct Shape {};

class MtlReader {
    MtlReader() {}
    ~MtlReader() {}
    virtual bool operator()(std::vector<Material>      &materials,
                            std::map<std::string, int> &matMap) = 0;
};

class MtlFileReader : MtlReader {
    MtlFileReader(const std::string &path);
    virtual bool operator()(std::vector<Material>      &materials,
                            std::map<std::string, int> &matMap) = 0;
};

class MtlStreamReader : MtlReader {
    MtlFileReader(std::istream &inStream);
    virtual bool operator()(std::vector<Material>      &materials,
                            std::map<std::string, int> &matMap) = 0;
};

//
class ObjReader {
  private:
    GlobalData         _global;
    std::vector<Shape> _shapes;

    struct Config {
        bool        triangulate;
        std::string mtl_search_path;

        Config() : triangulate(true), mtl_search_path("") {}
    };

  public:
    // parsing API
    bool parseFromIstream(std::istream &inStream, Config &config = Config());
    bool parseFromFile(std::string &path, Config &config = Config());
    bool parseFromText(std::string &text, Config &config = Config());

    // get parsed data
    GlobalData                 &getGlobal();
    VertexAttrib               &getVertexAttrib();
    std::vector<Material>      &getMaterials();
    std::map<std::string, int> &getMaterialsMap(); // <name, index>
};

} // namespace ynobj
