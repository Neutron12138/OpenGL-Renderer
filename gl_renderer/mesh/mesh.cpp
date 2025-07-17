#pragma once

#include "mesh.hpp"

namespace gl_renderer
{
    base::Int64 Mesh::get_resource_type() const
    {
        return static_cast<base::Int64>(ResourceType::Mesh);
    }

} // namespace gl_renderer
