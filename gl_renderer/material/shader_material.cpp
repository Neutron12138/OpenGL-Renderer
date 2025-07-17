#include "shader_material.hpp"

namespace gl_renderer
{
    ShaderMaterial::ShaderMaterial(const gl_wrapper::ProgramRef &program) : m_program(program) {}
    ShaderMaterial::ShaderMaterial(const gl_wrapper::ShaderRef &vshader, const gl_wrapper::ShaderRef &fshader) { create(vshader, fshader); }
    ShaderMaterial::ShaderMaterial(const std::string &vsource, const std::string &fsource) { create(vsource, fsource); }
    ShaderMaterial::ShaderMaterial(ShaderMaterial &&from)
        : m_program(std::move(from.m_program)),
          m_locations(std::move(from.m_locations)) {}

    ShaderMaterial &ShaderMaterial::operator=(ShaderMaterial &&from)
    {
        m_program = std::move(from.m_program);
        m_locations = std::move(from.m_locations);
        return *this;
    }

    const gl_wrapper::ProgramRef &ShaderMaterial::get_program() const { return m_program; }
    const UniformLocationHashMap &ShaderMaterial::get_locations() const { return m_locations; }

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
        gl_wrapper::ShaderRef vshader = std::make_shared<gl_wrapper::Shader>(
            gl_wrapper::Shader::ShaderType::Vertex, vsource);
        gl_wrapper::ShaderRef fshader = std::make_shared<gl_wrapper::Shader>(
            gl_wrapper::Shader::ShaderType::Fragment, fsource);
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

    void ShaderMaterial::set_MVP_matrix(const glm::mat4 &MVP) { set_uniform("u_MVP", MVP); }

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
