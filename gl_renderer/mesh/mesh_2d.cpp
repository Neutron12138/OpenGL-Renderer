#include "mesh_2d.hpp"

namespace gl_renderer
{
    Mesh2D &Mesh2D::operator=(Mesh2D &&from)
    {
        m_vertices = std::move(from.m_vertices);
        m_indices = std::move(from.m_indices);
        m_VAO = std::exchange(from.m_VAO, nullptr);
        m_VBO = std::exchange(from.m_VBO, nullptr);
        m_EBO = std::exchange(from.m_EBO, nullptr);
        return *this;
    }

    bool Mesh2D::is_valid() const
    {
        if (!m_VAO)
            return false;

        return m_VAO->is_valid();
    }

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
        m_VBO = std::make_shared<gl_wrapper::Buffer>(GL_ARRAY_BUFFER);
        m_EBO = std::make_shared<gl_wrapper::Buffer>(GL_ELEMENT_ARRAY_BUFFER);

        m_VBO->set_data(m_vertices);
        m_VAO->bind_vertex_buffer(0, *m_VBO, 0, sizeof(Vertex2D));
        m_EBO->set_data(m_indices);
        m_VAO->bind_element_buffer(*m_EBO);

        m_VAO->enable_attrib(VertexLayout::POSITION.attribindex);
        m_VAO->set_attrib_binding(VertexLayout::POSITION.attribindex, 0);
        m_VAO->set_attrib_format(VertexLayout::POSITION.attribindex,
                                 VertexLayout::POSITION.size,
                                 VertexLayout::POSITION.type,
                                 VertexLayout::POSITION.relativeoffset);

        m_VAO->enable_attrib(VertexLayout::TEXCOORD.attribindex);
        m_VAO->set_attrib_binding(VertexLayout::TEXCOORD.attribindex, 0);
        m_VAO->set_attrib_format(VertexLayout::TEXCOORD.attribindex,
                                 VertexLayout::TEXCOORD.size,
                                 VertexLayout::TEXCOORD.type,
                                 VertexLayout::TEXCOORD.relativeoffset);
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
