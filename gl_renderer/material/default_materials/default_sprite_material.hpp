#pragma once

#include "../material.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(DefaultSpriteMaterial);

    /// @brief 默认精灵材质，不允许修改
    class DefaultSpriteMaterial : public Material
    {
    public:
        static constexpr inline GLint MVP_LOCATION = 0;
        static constexpr inline GLint TEXTURE_LOCATION = 1;

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

    private:
        /// @brief 着色器程序
        gl_wrapper::Program m_program;

    private:
        void _create()
        {
            gl_wrapper::Shader vshader(GL_VERTEX_SHADER);
            vshader.set_source(VERTEX_SHADER_SOURCE);
            vshader.compile_shader();
            gl_wrapper::Shader fshader(GL_FRAGMENT_SHADER);
            fshader.set_source(FRAGMENT_SHADER_SOURCE);
            fshader.compile_shader();
            m_program.attach_shader(vshader);
            m_program.attach_shader(fshader);
            m_program.link_program();
        }

    public:
        inline DefaultSpriteMaterial() { _create(); }
        inline ~DefaultSpriteMaterial() override = default;

    public:
        inline bool is_valid() const override { return true; }
        inline void bind() const override { m_program.use(); }
        inline void set_MVP(const glm::mat4 &value) { m_program.set_uniform(MVP_LOCATION, value); }
        inline void set_texture_unit(GLuint value) { m_program.set_uniform(TEXTURE_LOCATION, value); }

        void set_uniform(const std::string &name, const glm::mat4 &value)
        {
            if (name != "u_MVP")
                throw BASE_MAKE_RUNTIME_ERROR("\"", name, "\" is not a valid uniform name");
            set_MVP(value);
        }

        void set_uniform(const std::string &name, GLuint value)
        {
            if (name != "u_texture")
                throw BASE_MAKE_RUNTIME_ERROR("\"", name, "\" is not a valid uniform name");
            set_texture_unit(value);
        }
    };

} // namespace gl_renderer
