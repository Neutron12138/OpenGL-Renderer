#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace gl_renderer
{
    /// @brief 2D变换对象
    class Transform2D
    {
    private:
        /// @brief 脏标记
        mutable bool m_is_dirty = false;
        /// @brief 矩阵缓存
        mutable glm::mat4 m_matrix_cache = glm::mat4(1.0f);
        /// @brief 变换原点
        glm::vec2 m_origin = glm::vec2(0.0f);
        /// @brief 位置
        glm::vec2 m_position = glm::vec2(0.0f);
        /// @brief 旋转
        float m_rotation = 0.0f;
        /// @brief 缩放
        glm::vec2 m_scale = glm::vec2(1.0f);

    public:
        inline Transform2D() = default;
        inline Transform2D(const Transform2D &from)
            : m_matrix_cache(from.get_matrix()),
              m_origin(from.m_origin),
              m_position(from.m_position),
              m_rotation(from.m_rotation),
              m_scale(from.m_scale) {}
        inline ~Transform2D() = default;

    public:
        Transform2D &operator=(const Transform2D &from)
        {
            m_is_dirty = false;
            m_matrix_cache = from.get_matrix();
            m_origin = from.m_origin;
            m_position = from.m_position;
            m_rotation = from.m_rotation;
            m_scale = from.m_scale;

            return *this;
        }

    public:
        inline const glm::vec2 &get_origin() const { return m_origin; }
        inline const glm::vec2 &get_position() const { return m_position; }
        inline float get_rotation() const { return m_rotation; }
        inline const glm::vec2 &get_scale() const { return m_scale; }

    public:
        void update() const
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

        inline const glm::mat4 &get_matrix() const
        {
            update();
            return m_matrix_cache;
        }

    public:
        inline void set_origin(const glm::vec2 &origin)
        {
            m_origin = origin;
            m_is_dirty = true;
        }

        inline void set_position(const glm::vec2 &position)
        {
            m_position = position;
            m_is_dirty = true;
        }

        inline void set_rotation(float rotation)
        {
            m_rotation = rotation;
            m_is_dirty = true;
        }

        inline void set_scale(const glm::vec2 &scale)
        {
            m_scale = scale;
            m_is_dirty = true;
        }

    public:
        inline void move(const glm::vec2 &offset)
        {
            m_position += offset;
            m_is_dirty = true;
        }

        inline void rotate(float rotation)
        {
            m_rotation += rotation;
            m_is_dirty = true;
        }
    };

} // namespace gl_renderer
