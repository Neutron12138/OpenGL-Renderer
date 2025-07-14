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
        inline QuadMesh() = default;
        inline QuadMesh(const glm::vec2 &size)
            : m_size(size) { create(); }
        inline QuadMesh(QuadMesh &&from)
            : Mesh2D(std::move(from)),
              m_size(std::exchange(from.m_size, {})) {}
        inline ~QuadMesh() = default;
        BASE_DELETE_COPY_FUNCTION(QuadMesh);

    public:
        QuadMesh &operator=(QuadMesh &&from);
        inline bool is_dirty() const { return m_is_dirty; }
        inline const glm::vec2 &get_size() const { return m_size; }

    public:
        void set_size(const glm::vec2 &size)
        {
            m_size = size;
            m_is_dirty = true;
        }

    protected:
        void _update_vertices();

    public:
        void create();
        void update_mesh();
        void destroy();
    };

} // namespace gl_renderer
