#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glfw_wrapper/glfw_wrapper.hpp>
#include <gl_wrapper/gl_wrapper.hpp>
#include "../gl_renderer/gl_renderer.hpp"

class MainLoop : public glfw_wrapper::MainLoop
{
private:
    gl_renderer::DefaultSpriteMaterialRef material;
    gl_wrapper::Texture2DRef texture;
    gl_renderer::QuadMeshRef mesh;
    glm::mat4 MVP = glm::ortho(0.0f, 1152.0f, 648.0f, 0.0f);
    int width, height;

private:
    void _load_texture()
    {
        stbi_uc *pixels = stbi_load("assets/wall.jpg", &width, &height, nullptr, 0);
        if (!pixels)
            throw "Failed to load image";

        texture = std::make_shared<gl_wrapper::Texture2D>();
        texture->create();
        texture->set_wrap_s();
        texture->set_wrap_t();
        texture->set_min_filter();
        texture->set_mag_filter();
        texture->set_storage(1, gl_wrapper::InternalFormat::RGB8, width, height);
        texture->set_sub_image(0, width, height, gl_wrapper::BaseFormat::RGB,
                               gl_wrapper::DataType::UnsignedByte, pixels);

        stbi_image_free(pixels);
    }

protected:
    void _initialize() override
    {
        gl_wrapper::GLLoader();
        auto &gl_debug_message_callback = gl_wrapper::DebugMessageCallback::get_instance();
        glViewport(0, 0, 1152, 648);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        _load_texture();

        material = std::make_shared<gl_renderer::DefaultSpriteMaterial>();
        mesh = std::make_shared<gl_renderer::QuadMesh>(glm::vec2(width, height));
    }

    void _draw() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        material->bind();
        material->set_uniform("u_MVP", MVP);
        mesh->bind();
        texture->bind();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

public:
    MainLoop() { m_is_opengl_debug_context_enabled = true; }
};

int main()
{
    constexpr gl_renderer::Vertex2D v({}, {});
    std::cout << "Vertex2D is trivial: " << std::is_trivial_v<gl_renderer::Vertex2D> << std::endl
              << "size of Vertex2D: " << (sizeof(gl_renderer::Vertex2D) == 2 * sizeof(glm::vec2)) << std::endl;

    MainLoop app;
    app.run();
    return app.get_exit_code();
}
