#include "shader_material.hpp"

namespace gl_renderer
{
    ShaderMaterial &ShaderMaterial::operator=(ShaderMaterial &&from)
    {
        m_program = std::move(from.m_program);
        m_locations = std::move(from.m_locations);
        return *this;
    }

    bool ShaderMaterial::is_valid() const
    {
        if (!m_program)
            return false;

        return m_program->is_valid();
    }

    void ShaderMaterial::create(const gl_wrapper::ProgramRef &program)
    {
        m_program = program;
    }

    void ShaderMaterial::create(const gl_wrapper::ShaderRef &vshader, const gl_wrapper::ShaderRef &fshader)
    {
        m_program = std::make_shared<gl_wrapper::Program>();
        m_program->attach_shader(*vshader);
        m_program->attach_shader(*fshader);
        m_program->link_program();
    }

    void ShaderMaterial::create(const std::string &vsource, const std::string &fsource)
    {
        gl_wrapper::ShaderRef vshader = std::make_shared<gl_wrapper::Shader>(GL_VERTEX_SHADER);
        vshader->set_source(std::move(vsource));
        vshader->compile_shader();
        gl_wrapper::ShaderRef fshader = std::make_shared<gl_wrapper::Shader>(GL_FRAGMENT_SHADER);
        fshader->set_source(std::move(fsource));
        fshader->compile_shader();
        create(vshader, fshader);
    }

    void ShaderMaterial::destroy()
    {
        m_program.reset();
    }

    void ShaderMaterial::bind() const
    {
        if (!m_program)
            throw BASE_MAKE_RUNTIME_ERROR("The shader program has not been created yet");

        if (!m_program->is_valid())
            throw BASE_MAKE_RUNTIME_ERROR("The shader program is invalid");

        m_program->use();
    }

    GLint ShaderMaterial::get_uniform_location(const std::string &name) const
    {
        if (!m_program)
            throw BASE_MAKE_RUNTIME_ERROR("The shader program has not been created yet");

        if (!m_program->is_valid())
            throw BASE_MAKE_RUNTIME_ERROR("The shader program is invalid");

        auto iter = m_locations.find(name);
        if (iter != m_locations.cend())
            return iter->second;

        GLint location = m_program->get_uniform_location(name);
        if (location == -1)
            throw BASE_MAKE_RUNTIME_ERROR("\"", name, "\" is not a valid uniform name");

        m_locations[name] = location;
        return location;
    }

} // namespace gl_renderer
