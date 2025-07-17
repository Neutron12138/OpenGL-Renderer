#pragma once

#include <gl_wrapper/buffer/buffer.hpp>
#include <gl_wrapper/vertex_array/vertex_array.hpp>
#include "mesh.hpp"
#include "vertex_2d.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Mesh2D);

    /// @brief 2D网格
    class Mesh2D : public Mesh
    {
    public:
        using VertexType = Vertex2D;
        using VertexLayout = VertexLayout<Vertex2D>;

    protected:
        /// @brief 顶点数组
        Vertex2DArray m_vertices;
        /// @brief 顶点索引数组
        VertexIndexArray m_indices;
        /// @brief 顶点数组对象
        gl_wrapper::VertexArrayRef m_VAO;
        /// @brief 顶点缓冲对象
        gl_wrapper::BufferRef m_VBO;
        /// @brief 顶点索引对象
        gl_wrapper::BufferRef m_EBO;

    public:
        Mesh2D() = default;
        Mesh2D(Mesh2D &&from);
        ~Mesh2D() override = default;
        BASE_DELETE_COPY_FUNCTION(Mesh2D);

    public:
        Mesh2D &operator=(Mesh2D &&from);
        const Vertex2DArray &get_vertices() const;
        const VertexIndexArray &get_indices() const;
        const gl_wrapper::VertexArrayRef &get_VAO() const;
        const gl_wrapper::BufferRef &get_VBO() const;
        const gl_wrapper::BufferRef &get_EBO() const;

    public:
        bool is_support_3d() const override;
        bool has_vertex_indices() const override;
        const void *get_raw_vertices() const override;
        const void *get_raw_indices() const override;
        base::Size get_vertex_count() const override;
        base::Size get_index_count() const override;
        bool is_valid() const override;

    public:
        const Vertex2D &get_vertex(base::Size index) const;
        const Vertex2D &get_vertex_safe(base::Size index) const;
        VertexIndex get_index(base::Size index) const;
        VertexIndex get_index_safe(base::Size index) const;

    public:
        void bind() const override;
        void create();
        void destroy();
    };

} // namespace gl_renderer
