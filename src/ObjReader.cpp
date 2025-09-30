#include "loader.h"
#include <fstream>
#include <sstream>

namespace ynobj
{
    bool ObjReader::parseFromIstream(std::istream &is, const Config &config)
    {
        std::map<std::string, int> matMap; // look-up용 (<name, index>)

        std::string line;
        while (is)
        {
            std::getline(is >> std::ws, line, '\n');
            if (line[0] == '#')
                continue;

            std::cout << line << '\n';
            // todo: keyword 따라 분기 처리
        }
        return true;
    }

    bool ObjReader::parseFromFile(const std::string &path, const Config &config)
    {
        std::filebuf fb;
        if (!fb.open(path, std::ios_base::in))
            return false;
        std::istream is(&fb);
        return (parseFromIstream(is, config));
    }

    bool ObjReader::parseFromText(const std::string &text, const Config &config)
    {
        std::stringbuf strbuf;
        strbuf.str(text);
        std::istream is(&strbuf);
        return (parseFromIstream(is, config));
    }

    VertexAttrib &ObjReader::getVertexAttrib() { return _attrib; }

    std::vector<Material> &ObjReader::getMaterials() { return _mats; }

    std::vector<Shape> &ObjReader::getShapes() { return _shapes; };

} // namespace ynobj
