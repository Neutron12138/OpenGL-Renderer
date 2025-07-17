#pragma once

#include "visual_2d.hpp"

namespace gl_renderer
{
    void Visual2D::_on_z_index_changed(base::Int16 old_z_index, base::Int16 new_z_index) {}

    Transform2D &Visual2D::get_transform() { return m_transform; }
    const Transform2D &Visual2D::get_transform() const { return m_transform; }
    void Visual2D::set_transform(const Transform2D &transform) { m_transform = transform; }
    base::Int16 Visual2D::get_z_index() const { return m_z_index; }

    void Visual2D::set_z_index(base::Int16 z_index)
    {
        if (m_z_index == z_index)
            return;

        base::Int16 old_z_index = m_z_index;
        m_z_index = z_index;
        _on_z_index_changed(old_z_index, m_z_index);
    }

    const glm::mat4 &Visual2D::get_model_matrix() const { return m_transform.get_matrix(); }
    const glm::mat4 &Visual2D::get_MVP_matrix() const { return m_MVP_cache; }

    void Visual2D::update_matrix(Camera &camera) const
    {
        m_MVP_cache = camera.get_VP_matrix() * m_transform.get_matrix();
    }

} // namespace gl_renderer
