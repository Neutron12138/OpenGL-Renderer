#pragma once

#include <vector>
#include <gl_wrapper/base/gl_loader.hpp>
#include "../base/resource.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Mesh);

    using VertexIndex = GLuint;
    using VertexIndexArray = std::vector<VertexIndex>;
    using VertexIndexConstIterator = VertexIndexArray::const_iterator;

    /// @brief 网格基类
    class Mesh : public Resource
    {
    public:
        inline Mesh() = default;
        inline ~Mesh() override = default;
        BASE_DELETE_COPY_FUNCTION(Mesh);

    public:
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Mesh); }

    public:
        /// @brief 绑定网格
        virtual void bind() const = 0;

        /// @brief 是否支持3D
        /// @return 是否支持3D
        virtual bool is_support_3d() const = 0;

        /// @brief 是否有顶点索引
        /// @return 是否有顶点索引
        virtual bool has_vertex_indices() const = 0;

        /// @brief 获取原始顶点数据
        /// @return 原始顶点数据
        virtual const void *get_raw_vertices() const = 0;

        /// @brief 获取原始索引数据
        /// @return 原始索引数据
        virtual const void *get_raw_indices() const = 0;

        /// @brief 获取顶点总数
        /// @return 顶点总数
        virtual base::Size get_vertex_count() const = 0;

        /// @brief 获取索引总数
        /// @return 索引总数
        virtual base::Size get_index_count() const = 0;
    };

} // namespace gl_renderer
