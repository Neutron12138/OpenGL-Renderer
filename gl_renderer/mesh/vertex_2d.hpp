#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "vertex_layout.hpp"

namespace gl_renderer
{
    /// @brief 2D顶点
    class Vertex2D
    {
    public:
        /// @brief 位置
        glm::vec2 position;
        union
        {
            /// @brief 纹理坐标
            glm::vec2 tex_coord;
            /// @brief 纹理坐标
            glm::vec2 UV;
        };

    public:
        Vertex2D() = default;
        inline constexpr Vertex2D(const glm::vec2 &pos, const glm::vec2 &uv = {})
            : position(pos),
              tex_coord(uv) {}
        ~Vertex2D() = default;
    };

    using Vertex2DArray = std::vector<Vertex2D>;
    using Vertex2DConstIterator = Vertex2DArray::const_iterator;

    template <>
    class VertexLayout<Vertex2D>
    {
    public:
        using VertexType = Vertex2D;

        static constexpr VertexAttrib POSITION{0, 2, gl_wrapper::DataType::Float, 0};
        static constexpr VertexAttrib TEXCOORD{1, 2, gl_wrapper::DataType::Float, sizeof(glm::vec2)};
        static constexpr VertexAttrib UV{1, 2, gl_wrapper::DataType::Float, sizeof(glm::vec2)};
    };

} // namespace gl_renderer
