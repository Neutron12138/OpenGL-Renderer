#pragma once

#include <gl_wrapper/texture/texture_2d.hpp>
#include "../visual_2d.hpp"
#include "../../material/material.hpp"
#include "../../mesh/builtin_meshes/quad_mesh.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Sprite);

    /// @brief 2D精灵
    class Sprite : public Visual2D
    {
    protected:
        /// @brief 尺寸（单位：像素）
        glm::ivec2 m_size;
        /// @brief 纹理
        gl_wrapper::Texture2DRef m_texture;
        /// @brief 网格
        QuadMeshRef m_mesh;
        /// @brief 自定义材质
        MaterialRef m_material;

    public:
        Sprite() = default;
        ~Sprite() = default;

    public:
        const glm::ivec2 &get_size() const;
        const gl_wrapper::Texture2DRef &get_texture() const;
        const QuadMeshRef &get_mesh() const;
        const MaterialRef &get_material() const;
        void set_material(const MaterialRef &material);

    protected:
        void _draw(const Renderer &renderer) const override;

    public:
        void load_image(const std::string &filename);
        void destroy();
    };

} // namespace gl_renderer
