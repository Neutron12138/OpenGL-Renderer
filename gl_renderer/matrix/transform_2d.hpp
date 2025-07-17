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
        Transform2D() = default;
        Transform2D(const Transform2D &from);
        ~Transform2D() = default;

    public:
        Transform2D &operator=(const Transform2D &from);

    public:
        const glm::vec2 &get_origin() const;
        const glm::vec2 &get_position() const;
        float get_rotation() const;
        const glm::vec2 &get_scale() const;

    public:
        void update() const;
        const glm::mat4 &get_matrix() const;

    public:
        void set_origin(const glm::vec2 &origin);
        void set_position(const glm::vec2 &position);
        void set_rotation(float rotation);
        void set_scale(const glm::vec2 &scale);

    public:
        void move(const glm::vec2 &offset);
        void rotate(float rotation);
    };

} // namespace gl_renderer
