#pragma once

#include "camera_2d.hpp"

namespace gl_renderer
{
    bool Camera2D::is_dirty() const { return m_is_dirty; }
    const glm::vec2 &Camera2D::get_screen_size() const { return m_screen_size; }

    void Camera2D::set_screen_size(const glm::vec2 &size)
    {
        m_screen_size = size;
        m_is_dirty = true;
    }

    const glm::mat4 &Camera2D::get_projection_matrix() const
    {
        update();
        return m_projection_cache;
    }

    const glm::mat4 &Camera2D::get_view_matrix() const
    {
        update();
        return m_projection_cache;
    }

    const glm::mat4 &Camera2D::get_VP_matrix() const
    {
        update();
        return m_projection_cache;
    }

    void Camera2D::update() const
    {
        if (!m_is_dirty)
            return;

        m_projection_cache = glm::ortho(0.0f, m_screen_size.x, m_screen_size.y, 0.0f);
        m_is_dirty = false;
    }

} // namespace gl_renderer
