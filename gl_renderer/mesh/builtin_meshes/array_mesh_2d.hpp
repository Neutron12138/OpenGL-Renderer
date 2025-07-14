#pragma once

#include "../mesh_2d.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(ArrayMesh2D);

    /// @brief 2D数组网格
    class ArrayMesh2D : public Mesh2D
    {
    public:
        inline ArrayMesh2D() = default;
        inline ArrayMesh2D(ArrayMesh2D &&from) : Mesh2D(std::move(from)) {}
        inline ~ArrayMesh2D() override = default;
        BASE_DELETE_COPY_FUNCTION(ArrayMesh2D);

    public:
        ArrayMesh2D &operator=(ArrayMesh2D &&from)
        {
            Mesh2D::operator=(std::move(from));
            return *this;
        }

    public:
        inline void set_vertices(const Vertex2DArray &vertices) { m_vertices = std::move(vertices); }
        inline void set_indices(const VertexIndexArray &indices) { m_indices = std::move(indices); }
        inline void vertices_reserve(base::Size size) { m_vertices.reserve(size); }
        inline void indices_reserve(base::Size size) { m_indices.reserve(size); }

        inline void add_vertex(const Vertex2D &vertex) { m_vertices.push_back(vertex); }
        inline void add_index(VertexIndex index) { m_indices.push_back(index); }
        inline void remove_vertex(Vertex2DConstIterator iter) { m_vertices.erase(iter); }
        inline void remove_index(VertexIndexConstIterator iter) { m_indices.erase(iter); }

        inline const Vertex2D &get_vertex(base::Size index) const { return m_vertices[index]; }
        inline const Vertex2D &get_vertex_safe(base::Size index) const { return m_vertices.at(index); }
        inline Vertex2D &get_vertex(base::Size index) { return m_vertices[index]; }
        inline Vertex2D &get_vertex_safe(base::Size index) { return m_vertices.at(index); }

        inline VertexIndex get_index(base::Size index) const { return m_indices[index]; }
        inline VertexIndex get_index_safe(base::Size index) const { return m_indices.at(index); }
        inline VertexIndex &get_index(base::Size index) { return m_indices[index]; }
        inline VertexIndex &get_index_safe(base::Size index) { return m_indices.at(index); }
    };

} // namespace gl_renderer
