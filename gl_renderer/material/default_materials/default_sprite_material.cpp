#pragma once

#include "default_sprite_material.hpp"

namespace gl_renderer
{
    DefaultSpriteMaterial::DefaultSpriteMaterial()
        : DefaultMaterial(VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE) {}

    void DefaultSpriteMaterial::set_texture_unit(GLuint value)
    {
        m_program.set_uniform(static_cast<GLint>(UniformLocation::Texture), value);
    }

} // namespace gl_renderer
