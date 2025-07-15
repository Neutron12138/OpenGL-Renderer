#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "camera.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Camera2D);

    /// @brief 2D相机
    class Camera2D : public Camera
    {
    private:
        /// @brief 脏标记
        mutable bool m_is_dirty = false;
        /// @brief 投影矩阵缓存
        mutable glm::mat4 m_projection_cache = glm::mat4(1.0f);
        /// @brief 屏幕尺寸
        glm::vec2 m_screen_size;

    public:
        inline Camera2D() = default;
        inline ~Camera2D() override = default;

    public:
        inline bool is_dirty() const { return m_is_dirty; }
        inline const glm::vec2 &get_screen_size() const { return m_screen_size; }
        inline void set_screen_size(const glm::vec2 &size)
        {
            m_screen_size = size;
            m_is_dirty = true;
        }

    public:
        inline const glm::mat4 &get_projection_matrix() const override
        {
            update();
            return m_projection_cache;
        }

        inline const glm::mat4 &get_view_matrix() const override
        {
            update();
            return m_projection_cache;
        }

        inline const glm::mat4 &get_VP_matrix() const override
        {
            update();
            return m_projection_cache;
        }

        void update() const override
        {
            if (!m_is_dirty)
                return;

            m_projection_cache = glm::ortho(0.0f, m_screen_size.x, m_screen_size.y, 0.0f);
            m_is_dirty = false;
        }
    };

} // namespace gl_renderer
