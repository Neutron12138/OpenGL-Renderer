#pragma once

#include "../default_material.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(DefaultSpriteMaterial);

    /// @brief 默认精灵材质，不允许修改
    class DefaultSpriteMaterial : public DefaultMaterial
    {
    public:
        /// @brief 顶点着色器代码
        static constexpr inline const char *VERTEX_SHADER_SOURCE =
            "#version 450 core\n"
            "layout(location=0)in vec2 a_position;\n"
            "layout(location=1)in vec2 a_tex_coord;\n"
            "out vec2 v_tex_coord;\n"
            "layout(location=0)uniform mat4 u_MVP;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = u_MVP * vec4(a_position, 0.0, 1.0);\n"
            "   v_tex_coord = a_tex_coord;\n"
            "}\n";

        /// @brief 片段着色器代码
        static constexpr inline const char *FRAGMENT_SHADER_SOURCE =
            "#version 450 core\n"
            "in vec2 v_tex_coord;\n"
            "out vec4 o_color;\n"
            "layout(location=1)uniform sampler2D u_texture;\n"
            "void main()\n"
            "{\n"
            "   o_color = texture(u_texture, v_tex_coord);\n"
            "}\n";

    public:
        inline DefaultSpriteMaterial() : DefaultMaterial(VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE) {}
        inline ~DefaultSpriteMaterial() override = default;

    public:
        inline void set_texture_unit(GLuint value) { m_program.set_uniform(static_cast<GLint>(UniformLocation::Texture), value); }
    };

} // namespace gl_renderer
