#pragma once

#include "array_mesh_2d.hpp"

namespace gl_renderer
{
    ArrayMesh2D::ArrayMesh2D(ArrayMesh2D &&from) : Mesh2D(std::move(from)) {}

    ArrayMesh2D &ArrayMesh2D::operator=(ArrayMesh2D &&from)
    {
        Mesh2D::operator=(std::move(from));
        return *this;
    }

    void ArrayMesh2D::set_vertices(const Vertex2DArray &vertices) { m_vertices = std::move(vertices); }
    void ArrayMesh2D::set_indices(const VertexIndexArray &indices) { m_indices = std::move(indices); }
    void ArrayMesh2D::vertices_reserve(base::Size size) { m_vertices.reserve(size); }
    void ArrayMesh2D::indices_reserve(base::Size size) { m_indices.reserve(size); }

    void ArrayMesh2D::add_vertex(const Vertex2D &vertex) { m_vertices.push_back(vertex); }
    void ArrayMesh2D::add_index(VertexIndex index) { m_indices.push_back(index); }
    void ArrayMesh2D::remove_vertex(Vertex2DConstIterator iter) { m_vertices.erase(iter); }
    void ArrayMesh2D::remove_index(VertexIndexConstIterator iter) { m_indices.erase(iter); }

    const Vertex2D &ArrayMesh2D::get_vertex(base::Size index) const { return m_vertices[index]; }
    const Vertex2D &ArrayMesh2D::get_vertex_safe(base::Size index) const { return m_vertices.at(index); }
    Vertex2D &ArrayMesh2D::get_vertex(base::Size index) { return m_vertices[index]; }
    Vertex2D &ArrayMesh2D::get_vertex_safe(base::Size index) { return m_vertices.at(index); }

    VertexIndex ArrayMesh2D::get_index(base::Size index) const { return m_indices[index]; }
    VertexIndex ArrayMesh2D::get_index_safe(base::Size index) const { return m_indices.at(index); }
    VertexIndex &ArrayMesh2D::get_index(base::Size index) { return m_indices[index]; }
    VertexIndex &ArrayMesh2D::get_index_safe(base::Size index) { return m_indices.at(index); }

} // namespace gl_renderer
