#pragma once

#include "../mesh_2d.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(ArrayMesh2D);

    /// @brief 2D数组网格
    class ArrayMesh2D : public Mesh2D
    {
    public:
        ArrayMesh2D() = default;
        ArrayMesh2D(ArrayMesh2D &&from);
        ~ArrayMesh2D() override = default;
        BASE_DELETE_COPY_FUNCTION(ArrayMesh2D);

    public:
        ArrayMesh2D &operator=(ArrayMesh2D &&from);

    public:
        void set_vertices(const Vertex2DArray &vertices);
        void set_indices(const VertexIndexArray &indices);
        void vertices_reserve(base::Size size);
        void indices_reserve(base::Size size);

        void add_vertex(const Vertex2D &vertex);
        void add_index(VertexIndex index);
        void remove_vertex(Vertex2DConstIterator iter);
        void remove_index(VertexIndexConstIterator iter);

        const Vertex2D &get_vertex(base::Size index) const;
        const Vertex2D &get_vertex_safe(base::Size index) const;
        Vertex2D &get_vertex(base::Size index);
        Vertex2D &get_vertex_safe(base::Size index);

        VertexIndex get_index(base::Size index) const;
        VertexIndex get_index_safe(base::Size index) const;
        VertexIndex &get_index(base::Size index);
        VertexIndex &get_index_safe(base::Size index);
    };

} // namespace gl_renderer
