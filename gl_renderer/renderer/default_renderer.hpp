#pragma once

#include "renderer.hpp"
#include "../material/default_materials/default_sprite_material.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(DefaultRenderer);

    /// @brief 默认渲染器
    class DefaultRenderer : public Renderer
    {
    private:
        MaterialRef m_default_sprite_material = std::make_shared<DefaultSpriteMaterial>();

    public:
        inline DefaultRenderer() = default;
        inline ~DefaultRenderer() override = default;

    public:
        const MaterialRef &get_default_sprite_material() const { return m_default_sprite_material; }
    };

} // namespace gl_renderer
