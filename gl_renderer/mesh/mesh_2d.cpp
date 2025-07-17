#include "mesh_2d.hpp"

namespace gl_renderer
{
    Mesh2D::Mesh2D(Mesh2D &&from)
        : m_vertices(std::move(from.m_vertices)),
          m_indices(std::move(from.m_indices)),
          m_VAO(std::exchange(from.m_VAO, nullptr)),
          m_VBO(std::exchange(from.m_VBO, nullptr)),
          m_EBO(std::exchange(from.m_EBO, nullptr)) {}

    Mesh2D &Mesh2D::operator=(Mesh2D &&from)
    {
        m_vertices = std::move(from.m_vertices);
        m_indices = std::move(from.m_indices);
        m_VAO = std::exchange(from.m_VAO, nullptr);
        m_VBO = std::exchange(from.m_VBO, nullptr);
        m_EBO = std::exchange(from.m_EBO, nullptr);
        return *this;
    }

    const Vertex2DArray &Mesh2D::get_vertices() const { return m_vertices; }
    const VertexIndexArray &Mesh2D::get_indices() const { return m_indices; }
    const gl_wrapper::VertexArrayRef &Mesh2D::get_VAO() const { return m_VAO; }
    const gl_wrapper::BufferRef &Mesh2D::get_VBO() const { return m_VBO; }
    const gl_wrapper::BufferRef &Mesh2D::get_EBO() const { return m_EBO; }

    bool Mesh2D::is_support_3d() const { return false; }
    bool Mesh2D::has_vertex_indices() const { return m_indices.size(); }
    const void *Mesh2D::get_raw_vertices() const { return m_vertices.data(); }
    const void *Mesh2D::get_raw_indices() const { return m_indices.data(); }
    base::Size Mesh2D::get_vertex_count() const { return m_vertices.size(); }
    base::Size Mesh2D::get_index_count() const { return m_indices.size(); }

    bool Mesh2D::is_valid() const
    {
        if (!m_VAO)
            return false;

        return m_VAO->is_valid();
    }

    const Vertex2D &Mesh2D::get_vertex(base::Size index) const { return m_vertices[index]; }
    const Vertex2D &Mesh2D::get_vertex_safe(base::Size index) const { return m_vertices.at(index); }
    VertexIndex Mesh2D::get_index(base::Size index) const { return m_indices[index]; }
    VertexIndex Mesh2D::get_index_safe(base::Size index) const { return m_indices.at(index); }

    void Mesh2D::bind() const
    {
        if (!m_VAO)
            throw BASE_MAKE_RUNTIME_ERROR("Vertex array has not been created yet");

        if (!m_VAO->is_valid())
            throw BASE_MAKE_RUNTIME_ERROR("Vertex array object is invalid");

        m_VAO->bind();
    }

    void Mesh2D::create()
    {
        m_VAO = std::make_shared<gl_wrapper::VertexArray>();
        m_VBO = std::make_shared<gl_wrapper::Buffer>(gl_wrapper::Buffer::BufferType::Array);
        m_EBO = std::make_shared<gl_wrapper::Buffer>(gl_wrapper::Buffer::BufferType::ElementArray);

        m_VAO->create();
        m_VBO->set_data(m_vertices);
        m_VAO->bind_vertex_buffer(0, *m_VBO, 0, sizeof(Vertex2D));
        m_EBO->set_data(m_indices);
        m_VAO->bind_element_buffer(*m_EBO);

        m_VAO->enable_attrib(VertexLayout::POSITION.attribindex);
        m_VAO->set_attrib_binding(VertexLayout::POSITION.attribindex, 0);
        m_VAO->set_attrib_format(VertexLayout::POSITION.attribindex,
                                 VertexLayout::POSITION.vertex_size,
                                 VertexLayout::POSITION.data_type,
                                 VertexLayout::POSITION.relative_offset);

        m_VAO->enable_attrib(VertexLayout::TEXCOORD.attribindex);
        m_VAO->set_attrib_binding(VertexLayout::TEXCOORD.attribindex, 0);
        m_VAO->set_attrib_format(VertexLayout::TEXCOORD.attribindex,
                                 VertexLayout::TEXCOORD.vertex_size,
                                 VertexLayout::TEXCOORD.data_type,
                                 VertexLayout::TEXCOORD.relative_offset);
    }

    void Mesh2D::destroy()
    {
        m_vertices.clear();
        m_indices.clear();
        m_VAO.reset();
        m_VBO.reset();
        m_EBO.reset();
    }

} // namespace gl_renderer
