#pragma once

#include <gl_wrapper/shader/program.hpp>
#include "../base/resource.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Material);

    /// @brief 材质基类
    class Material : public Resource
    {
    public:
        inline Material() = default;
        inline ~Material() override = default;
        BASE_DELETE_COPY_FUNCTION(Material);

    public:
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Material); }

    public:
        /// @brief 绑定材质
        virtual void bind() const = 0;

        /// @brief 设置MVP矩阵
        /// @param MVP MVP矩阵
        virtual void set_MVP_matrix(const glm::mat4 &MVP) = 0;
    };

} // namespace gl_renderer
