#pragma once

#include "vertex_attrib.hpp"

namespace gl_renderer
{
    /// @brief 顶点布局
    /// @tparam VertexT 顶点类型
    template <typename VertexT>
    class VertexLayout
    {
    public:
        using VertexType = VertexT;
    };

} // namespace gl_renderer
