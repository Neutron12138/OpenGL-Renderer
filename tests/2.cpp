#include <iostream>
#define GLFW_WRAPPER_ENABLE_GL_DEBUG true
#include <glfw_wrapper/glfw_wrapper.hpp>
#include <gl_wrapper/gl_wrapper.hpp>
#include "../gl_renderer/gl_renderer.hpp"

class MainLoop : public glfw_wrapper::MainLoop
{
private:
    gl_renderer::DefaultRendererRef renderer;
    gl_renderer::SpriteRef sprite;
    glm::mat4 MVP;

protected:
    void _initialize() override
    {
        gl_wrapper::GLLoader();
        gl_wrapper::DebugMessageCallback::get_instance();
        glViewport(0, 0, 1152, 648);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        renderer = std::make_shared<gl_renderer::DefaultRenderer>();

        sprite = std::make_shared<gl_renderer::Sprite>();
        sprite->load_image("assets/wall.jpg");

        MVP = glm::ortho(0.0f, 1152.0f, 648.0f, 0.0f);
        renderer->get_default_sprite_material()->as<gl_renderer::DefaultSpriteMaterial>()->set_MVP(MVP);
    }

    void _draw() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        renderer->draw(*sprite);
    }
};

int main()
{
    MainLoop app;
    app.run();
    return app.get_exit_code();
}

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
