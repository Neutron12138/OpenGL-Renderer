#include <stb_image.h>
#include "sprite.hpp"
#include "../../renderer/renderer.hpp"
#include "../../material/shader_material.hpp"
#include "../../material/default_materials/default_sprite_material.hpp"

namespace gl_renderer
{
    void Sprite::_draw(const Renderer &renderer) const
    {
        if (!m_texture || !m_mesh)
            throw BASE_MAKE_RUNTIME_ERROR("Sprite has not been created yet");

        if (m_material)
            m_material->bind();
        else
            renderer.get_default_sprite_material()->bind();

        m_texture->bind();
        m_mesh->bind();
        m_mesh->get_VAO()->draw_arrays(GL_TRIANGLE_STRIP, 4);
    }

    void Sprite::load_image(const std::string &filename)
    {
        int width, height;
        stbi_uc *pixels = stbi_load(filename.data(), &width, &height, nullptr, 0);
        if (!pixels)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to load image: \"", filename, "\"");

        m_texture = std::make_shared<gl_wrapper::Texture2D>();
        m_texture->set_wrap_s();
        m_texture->set_wrap_t();
        m_texture->set_min_filter();
        m_texture->set_mag_filter();
        m_texture->set_storage(1, GL_RGB8, width, height);
        m_texture->set_sub_image(0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

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
