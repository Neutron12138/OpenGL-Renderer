#pragma once

#include <glm/glm.hpp>
#include <base/core/polymorphic_object.hpp>

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Camera);

    /// @brief 相机基类
    class Camera : public base::PolymorphicObject
    {
    public:
        Camera() = default;
        ~Camera() override = default;

    public:
        /// @brief 获取投影矩阵
        /// @return 投影矩阵
        virtual const glm::mat4 &get_projection_matrix() const = 0;

        /// @brief 获取视图矩阵
        /// @return 视图矩阵
        virtual const glm::mat4 &get_view_matrix() const = 0;

        /// @brief 获取视图投影矩阵
        /// @return 视图投影矩阵
        virtual const glm::mat4 &get_VP_matrix() const = 0;

        /// @brief 更新矩阵
        virtual void update() const = 0;
    };

} // namespace gl_renderer
