#pragma once

#include "../mesh_2d.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(QuadMesh);

    /// @brief 四边形网格，以三角形条带模式绘制4个顶点
    class QuadMesh : public Mesh2D
    {
    private:
        /// @brief 脏标记
        bool m_is_dirty = false;
        /// @brief 尺寸（单位：像素）
        glm::vec2 m_size = glm::vec2(0.0f);

    public:
        QuadMesh() = default;
        QuadMesh(const glm::vec2 &size);
        QuadMesh(QuadMesh &&from);
        ~QuadMesh() = default;
        BASE_DELETE_COPY_FUNCTION(QuadMesh);

    public:
        QuadMesh &operator=(QuadMesh &&from);
        bool is_dirty() const;
        const glm::vec2 &get_size() const;
        void set_size(const glm::vec2 &size);

    protected:
        void _update_vertices();

    public:
        void create();
        void update_mesh();
        void destroy();
    };

} // namespace gl_renderer
