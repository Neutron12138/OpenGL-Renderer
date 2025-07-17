#include "quad_mesh.hpp"

namespace gl_renderer
{
    QuadMesh::QuadMesh(const glm::vec2 &size)
        : m_size(size) { create(); }
    QuadMesh::QuadMesh(QuadMesh &&from)
        : Mesh2D(std::move(from)),
          m_size(std::exchange(from.m_size, {})) {}

    QuadMesh &QuadMesh::operator=(QuadMesh &&from)
    {
        Mesh2D::operator=(std::move(from));
        m_size = std::exchange(from.m_size, {});
        return *this;
    }

    bool QuadMesh::is_dirty() const { return m_is_dirty; }
    const glm::vec2 &QuadMesh::get_size() const { return m_size; }

    void QuadMesh::set_size(const glm::vec2 &size)
    {
        m_size = size;
        m_is_dirty = true;
    }

    void QuadMesh::_update_vertices()
    {
        m_vertices = {
            {{0.0f, 0.0f}, {0.0f, 0.0f}},
            {{0.0f, m_size.y}, {0.0f, 1.0f}},
            {{m_size.x, 0.0f}, {1.0f, 0.0f}},
            {{m_size.x, m_size.y}, {1.0f, 1.0f}},
        };
    }

    void QuadMesh::create()
    {
        _update_vertices();
        Mesh2D::create();
    }

    void QuadMesh::update_mesh()
    {
        if (!m_is_dirty)
            return;

        _update_vertices();
        m_VBO->set_sub_data(0, m_vertices);
        m_is_dirty = false;
    }

    void QuadMesh::destroy()
    {
        m_size = glm::vec2(0.0f);
        Mesh2D::destroy();
    }

} // namespace gl_renderer
