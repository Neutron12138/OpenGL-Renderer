#pragma once

#include "transform_2d.hpp"

namespace gl_renderer
{
    Transform2D::Transform2D(const Transform2D &from)
        : m_matrix_cache(from.get_matrix()),
          m_origin(from.m_origin),
          m_position(from.m_position),
          m_rotation(from.m_rotation),
          m_scale(from.m_scale) {}

    Transform2D &Transform2D::operator=(const Transform2D &from)
    {
        m_is_dirty = false;
        m_matrix_cache = from.get_matrix();
        m_origin = from.m_origin;
        m_position = from.m_position;
        m_rotation = from.m_rotation;
        m_scale = from.m_scale;

        return *this;
    }

    const glm::vec2 &Transform2D::get_origin() const { return m_origin; }
    const glm::vec2 &Transform2D::get_position() const { return m_position; }
    float Transform2D::get_rotation() const { return m_rotation; }
    const glm::vec2 &Transform2D::get_scale() const { return m_scale; }

    void Transform2D::update() const
    {
        if (!m_is_dirty)
            return;

        m_matrix_cache = glm::mat4(1.0f);
        m_matrix_cache = glm::translate(m_matrix_cache, glm::vec3(m_origin, 0.0f));
        m_matrix_cache = glm::translate(m_matrix_cache, glm::vec3(m_position, 0.0f));
        m_matrix_cache = glm::rotate(m_matrix_cache, m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));
        m_matrix_cache = glm::scale(m_matrix_cache, glm::vec3(m_scale, 1.0f));
        m_matrix_cache = glm::translate(m_matrix_cache, glm::vec3(-m_origin, 0.0f));

        m_is_dirty = false;
    }

    const glm::mat4 &Transform2D::get_matrix() const
    {
        update();
        return m_matrix_cache;
    }

    void Transform2D::set_origin(const glm::vec2 &origin)
    {
        m_origin = origin;
        m_is_dirty = true;
    }

    void Transform2D::set_position(const glm::vec2 &position)
    {
        m_position = position;
        m_is_dirty = true;
    }

    void Transform2D::set_rotation(float rotation)
    {
        m_rotation = rotation;
        m_is_dirty = true;
    }

    void Transform2D::set_scale(const glm::vec2 &scale)
    {
        m_scale = scale;
        m_is_dirty = true;
    }

    void Transform2D::move(const glm::vec2 &offset)
    {
        m_position += offset;
        m_is_dirty = true;
    }

    void Transform2D::rotate(float rotation)
    {
        m_rotation += rotation;
        m_is_dirty = true;
    }

} // namespace gl_renderer
