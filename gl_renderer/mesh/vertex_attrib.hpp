#pragma once

#include <gl_wrapper/base/gl_loader.hpp>
#include <gl_wrapper/base/enums.hpp>

namespace gl_renderer
{
    /// @brief 顶点属性
    class VertexAttrib
    {
    public:
        /// @brief 属性索引
        const GLuint attribindex;
        /// @brief 尺寸
        const GLint vertex_size;
        /// @brief 类型
        const gl_wrapper::DataType data_type;
        /// @brief 相对偏移量
        const GLuint relative_offset;

    public:
        inline constexpr VertexAttrib(GLuint index, GLint size, gl_wrapper::DataType type, GLuint offset)
            : attribindex(index),
              vertex_size(size),
              data_type(type),
              relative_offset(offset) {}
        ~VertexAttrib() = default;
    };

} // namespace gl_renderer
