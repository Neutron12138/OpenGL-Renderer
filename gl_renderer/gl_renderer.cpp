#pragma once

#ifdef GL_RENDERER_INCLUDE_STB_IMPL
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#undef STB_IMAGE_IMPLEMENTATION
#endif

#include "gl_renderer.hpp"

// matrix

#include "matrix/transform_2d.cpp"

// camera

#include "camera/camera_2d.cpp"

// shader

#include "material/material.cpp"
#include "material/default_material.cpp"
#include "material/shader_material.cpp"
#include "material/default_materials/default_sprite_material.cpp"

// mesh

#include "mesh/mesh.cpp"
#include "mesh/mesh_2d.cpp"
#include "mesh/builtin_meshes/array_mesh_2d.cpp"
#include "mesh/builtin_meshes/quad_mesh.cpp"

// renderer

#include "renderer/renderer.cpp"
#include "renderer/default_2d_renderer.cpp"

// visual

#include "visual/visual.cpp"
#include "visual/visual_2d.cpp"
#include "visual/2d/sprite.cpp"
