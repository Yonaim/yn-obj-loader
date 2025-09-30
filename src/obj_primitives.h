#pragma once

/**
 * @brief primitives - f, l, p
 *
 * face -> polygon mesh
 * line -> polylines
 * point -> point cloud
 */

#include <vector>

namespace ynobj
{

    // invalid한 경우 값은 -1
    // 메모리를 조금 더 사용하고 로직을 통일시킴
    struct Index
    {
        int v;  // coordinate
        int vn; // normal
        int vt; // texcoord
    };

    struct Mesh
    {
        std::vector<Index>        indices;
        std::vector<unsigned int> n_per_face;
    };

    struct Lines
    {
        std::vector<Index>        indices; // use only v, vt
        std::vector<unsigned int> n_per_line;
    };

    struct Points
    {
        std::vector<Index> indices; // use only v
    };

} // namespace ynobj
