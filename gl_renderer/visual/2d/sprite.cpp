#include <stb_image.h>
#include "sprite.hpp"
#include "../../renderer/renderer.hpp"
#include "../../material/shader_material.hpp"
#include "../../material/default_materials/default_sprite_material.hpp"

namespace gl_renderer
{
    const glm::ivec2 &Sprite::get_size() const { return m_size; }
    const gl_wrapper::Texture2DRef &Sprite::get_texture() const { return m_texture; }
    const QuadMeshRef &Sprite::get_mesh() const { return m_mesh; }
    const MaterialRef &Sprite::get_material() const { return m_material; }
    void Sprite::set_material(const MaterialRef &material) { m_material = material; }

    void Sprite::_draw(const Renderer &renderer) const
    {
        if (!m_texture || !m_mesh)
            throw BASE_MAKE_RUNTIME_ERROR("Sprite has not been created yet");

        if (m_material)
        {
            m_material->bind();
            m_material->set_MVP_matrix(m_MVP_cache);
        }
        else
        {
            auto material = renderer.get_default_sprite_material();
            material->bind();
            material->set_MVP_matrix(m_MVP_cache);
        }

        m_texture->bind();
        m_mesh->bind();
        m_mesh->get_VAO()->draw_arrays(gl_wrapper::VertexArray::DrawMode::TriangleStrip, 4);
    }

    void Sprite::load_image(const std::string &filename)
    {
        int width, height;
        stbi_uc *pixels = stbi_load(filename.data(), &width, &height, nullptr, 0);
        if (!pixels)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to load image: \"", filename, "\"");

        m_texture = std::make_shared<gl_wrapper::Texture2D>();
        m_texture->create();
        m_texture->set_wrap_s();
        m_texture->set_wrap_t();
        m_texture->set_min_filter();
        m_texture->set_mag_filter();
        m_texture->set_storage(1, gl_wrapper::InternalFormat::RGB8, width, height);
        m_texture->set_sub_image(0, 0, 0, width, height, gl_wrapper::BaseFormat::RGB,
                                 gl_wrapper::DataType::UnsignedByte, pixels);

        stbi_image_free(pixels);

        m_size = {width, height};
        m_mesh = std::make_shared<QuadMesh>(glm::vec2(width, height));
    }

    void Sprite::destroy()
    {
        m_size = {};
        m_texture.reset();
        m_mesh.reset();
        m_material.reset();
    }

} // namespace gl_renderer
