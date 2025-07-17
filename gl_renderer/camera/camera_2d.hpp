#pragma once

#include <glm/glm.hpp>
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
        Camera2D() = default;
        ~Camera2D() override = default;

    public:
        bool is_dirty() const;
        const glm::vec2 &get_screen_size() const;
        void set_screen_size(const glm::vec2 &size);

    public:
        const glm::mat4 &get_projection_matrix() const override;
        const glm::mat4 &get_view_matrix() const override;
        const glm::mat4 &get_VP_matrix() const override;
        void update() const override;
    };

} // namespace gl_renderer
