#pragma once

#include "renderer.hpp"
#include "../camera/camera_2d.hpp"
#include "../material/default_materials/default_sprite_material.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Default2DRenderer);

    /// @brief 默认2D渲染器
    class Default2DRenderer : public Renderer
    {
    private:
        CameraRef m_camera = std::make_shared<Camera2D>();
        MaterialRef m_default_sprite_material = std::make_shared<DefaultSpriteMaterial>();

    public:
        Default2DRenderer() = default;
        ~Default2DRenderer() override = default;

    public:
        const CameraRef &get_camera() const;
        void set_camera(const Camera2DRef &camera);

    public:
        const CameraRef &get_current_camera() const override;
        const MaterialRef &get_default_sprite_material() const override;
    };

} // namespace gl_renderer
