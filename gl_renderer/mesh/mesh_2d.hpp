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
        inline Mesh2D() = default;
        inline Mesh2D(Mesh2D &&from)
            : m_vertices(std::move(from.m_vertices)),
              m_indices(std::move(from.m_indices)),
              m_VAO(std::exchange(from.m_VAO, nullptr)),
              m_VBO(std::exchange(from.m_VBO, nullptr)),
              m_EBO(std::exchange(from.m_EBO, nullptr)) {}
        inline ~Mesh2D() override = default;
        BASE_DELETE_COPY_FUNCTION(Mesh2D);

    public:
        Mesh2D &operator=(Mesh2D &&from);
        inline const Vertex2DArray &get_vertices() const { return m_vertices; }
        inline const VertexIndexArray &get_indices() const { return m_indices; }
        inline const gl_wrapper::VertexArrayRef &get_VAO() const { return m_VAO; }
        inline const gl_wrapper::BufferRef &get_VBO() const { return m_VBO; }
        inline const gl_wrapper::BufferRef &get_EBO() const { return m_EBO; }

    public:
        inline bool is_support_3d() const override { return false; }
        inline bool has_vertex_indices() const override { return m_indices.size(); }
        inline const void *get_raw_vertices() const override { return m_vertices.data(); }
        inline const void *get_raw_indices() const override { return m_indices.data(); }
        inline base::Size get_vertex_count() const override { return m_vertices.size(); }
        inline base::Size get_index_count() const override { return m_indices.size(); }
        bool is_valid() const override;

    public:
        const Vertex2D &get_vertex(base::Size index) const { return m_vertices[index]; }
        const Vertex2D &get_vertex_safe(base::Size index) const { return m_vertices.at(index); }
        VertexIndex get_index(base::Size index) const { return m_indices[index]; }
        VertexIndex get_index_safe(base::Size index) const { return m_indices.at(index); }

    public:
        void bind() const override;
        void create();
        void destroy();
    };

} // namespace gl_renderer
