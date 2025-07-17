#pragma once

#include "material.hpp"

namespace gl_renderer
{
    base::Int64 Material::get_resource_type() const
    {
        return static_cast<base::Int64>(ResourceType::Material);
    }

} // namespace gl_renderer
