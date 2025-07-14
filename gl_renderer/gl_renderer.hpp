#pragma once

#include <base/version.hpp>

// base

#include "base/resource.hpp"

// shader

#include "material/material.hpp"
#include "material/shader_material.hpp"
#include "material/default_materials/default_sprite_material.hpp"

#include "material/shader_material.cpp"

// mesh

#include "mesh/vertex_attrib.hpp"
#include "mesh/vertex_layout.hpp"
#include "mesh/vertex_2d.hpp"
#include "mesh/mesh.hpp"
#include "mesh/mesh_2d.hpp"
#include "mesh/builtin_meshes/array_mesh_2d.hpp"
#include "mesh/builtin_meshes/quad_mesh.hpp"

#include "mesh/mesh_2d.cpp"
#include "mesh/builtin_meshes/quad_mesh.cpp"

// renderer

#include "renderer/renderer.hpp"
#include "renderer/default_renderer.hpp"

// visual

#include "visual/visual.hpp"
#include "visual/visual_2d.hpp"
#include "visual/2d/sprite.hpp"

#include "visual/2d/sprite.cpp"
