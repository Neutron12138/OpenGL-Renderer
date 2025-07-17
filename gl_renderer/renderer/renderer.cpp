#pragma once

#include "renderer.hpp"

namespace gl_renderer
{
    void Renderer::draw(const Visual &visual) const
    {
        visual.request_draw(*this);
    }

} // namespace gl_renderer
