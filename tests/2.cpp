#include <iostream>
#define GLFW_WRAPPER_ENABLE_GL_DEBUG true
#include <glfw_wrapper/glfw_wrapper.hpp>
#include <gl_wrapper/gl_wrapper.hpp>
#include "../gl_renderer/gl_renderer.hpp"

class MainLoop : public glfw_wrapper::MainLoop
{
private:
    gl_renderer::Default2DRendererRef renderer;
    gl_renderer::SpriteRef sprite;
    gl_renderer::Camera2DRef camera;

protected:
    void _initialize() override
    {
        gl_wrapper::GLLoader();
        gl_wrapper::DebugMessageCallback::get_instance();
        glViewport(0, 0, 1152, 648);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        camera = std::make_shared<gl_renderer::Camera2D>();
        camera->set_screen_size(glm::vec2(1152, 648));
        camera->update();

        renderer = std::make_shared<gl_renderer::Default2DRenderer>();
        renderer->set_camera(camera);

        sprite = std::make_shared<gl_renderer::Sprite>();
        sprite->load_image("assets/wall.jpg");
        sprite->get_transform().set_origin(glm::vec2(512.0f, 512.0f));
        sprite->update_matrix(*camera);
    }

    void _update(double delta) override
    {
        sprite->get_transform().rotate(delta);
        sprite->get_transform().update();
        sprite->update_matrix(*camera);
    }

    void _draw() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        renderer->draw(*sprite);
    }

public:
    MainLoop() { m_is_opengl_debug_context_enabled = true; }
};

int main()
{
    MainLoop app;
    app.run();
    return app.get_exit_code();
}
