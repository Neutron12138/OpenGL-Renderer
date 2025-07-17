#pragma once

#include "visual.hpp"

namespace gl_renderer
{
    void Visual::_on_visibility_changed() {}

    bool Visual::is_visible() const { return m_is_visible; }
    void Visual::show() { set_visibility(true); }
    void Visual::hide() { set_visibility(false); }

    void Visual::set_visibility(bool is_visible)
    {
        if (m_is_visible == is_visible)
            return;

        m_is_visible = is_visible;
        _on_visibility_changed();
    }

    void Visual::request_draw(const Renderer &renderer) const
    {
        if (m_is_visible)
            _draw(renderer);
    }

} // namespace gl_renderer
