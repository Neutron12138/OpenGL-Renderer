#pragma once

#include <gl_wrapper/base/gl_loader.hpp>

namespace gl_renderer
{
    /// @brief 顶点属性
    class VertexAttrib
    {
    public:
        /// @brief 属性索引
        const GLuint attribindex;
        /// @brief 尺寸
        const GLint size;
        /// @brief 类型
        const GLenum type;
        /// @brief 相对偏移量
        const GLuint relativeoffset;

    public:
        constexpr VertexAttrib(GLuint idx, GLint s, GLenum t, GLuint offset)
            : attribindex(idx),
              size(s),
              type(t),
              relativeoffset(offset) {}
        inline ~VertexAttrib() = default;
    };

} // namespace gl_renderer
