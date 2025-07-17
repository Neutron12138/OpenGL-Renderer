#pragma once

#include "default_2d_renderer.hpp"

namespace gl_renderer
{
    const CameraRef &Default2DRenderer::get_camera() const { return m_camera; }
    void Default2DRenderer::set_camera(const Camera2DRef &camera) { m_camera = camera; }

    const CameraRef &Default2DRenderer::get_current_camera() const { return m_camera; }
    const MaterialRef &Default2DRenderer::get_default_sprite_material() const { return m_default_sprite_material; }

} // namespace gl_renderer
