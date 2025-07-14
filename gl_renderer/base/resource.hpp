#pragma once

#include <base/misc/resource.hpp>

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Resource);

    /// @brief 资源基类
    class Resource : public base::Resource
    {
    public:
        /// @brief 资源类型
        enum class ResourceType
        {
            /// @brief 无
            None,
            /// @brief 材质
            Material,
            /// @brief 网格
            Mesh,
            /// @brief 纹理
            Texture,
            /// @brief 视口
            Viewport,
        };

    public:
        inline Resource() = default;
        inline ~Resource() override = default;
        BASE_DELETE_COPY_FUNCTION(Resource);
    };

} // namespace gl_renderer
