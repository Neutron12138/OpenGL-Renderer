#pragma once

#include <base/core/polymorphic_object.hpp>
#include "../visual/visual.hpp"
#include "../material/material.hpp"
#include "../camera/camera.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Renderer);

    /// @brief 渲染器基类
    class Renderer : public base::PolymorphicObject
    {
    public:
        inline Renderer() = default;
        inline ~Renderer() override = default;

    public:
        virtual void draw(const Visual &visual) const
        {
            visual.request_draw(*this);
        }

    public:
        /// @brief 获取当前活跃的相机
        /// @return 当前相机
        virtual const CameraRef &get_current_camera() const = 0;

        /// @brief 获取默认精灵材质
        /// @return 默认精灵材质
        virtual const MaterialRef &get_default_sprite_material() const = 0;
    };

} // namespace gl_renderer
