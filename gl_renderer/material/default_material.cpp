#pragma once

#include "default_material.hpp"

namespace gl_renderer
{
    DefaultMaterial::DefaultMaterial(const std::string &vsource, const std::string &fsource)
    {
        m_program = gl_wrapper::Program::link_shaders(
            gl_wrapper::Shader::load_from_string(gl_wrapper::Shader::ShaderType::Vertex, vsource),
            gl_wrapper::Shader::load_from_string(gl_wrapper::Shader::ShaderType::Fragment, fsource));
    }

    bool DefaultMaterial::is_valid() const { return true; }
    void DefaultMaterial::bind() const { m_program.use(); }

    void DefaultMaterial::set_MVP_matrix(const glm::mat4 &MVP)
    {
        m_program.set_uniform(static_cast<GLint>(UniformLocation::MVP), MVP);
    }

} // namespace gl_renderer
