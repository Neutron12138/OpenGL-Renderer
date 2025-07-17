#pragma once

#include <limits>
#include <base/core/type.hpp>
#include "visual.hpp"
#include "../matrix/transform_2d.hpp"
#include "../camera/camera_2d.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Visual2D);

    /// @brief 2D可视对象
    class Visual2D : public Visual
    {
    public:
        static constexpr base::Int16 Z_INDEX_MIN = std::numeric_limits<std::int16_t>::min();
        static constexpr base::Int16 Z_INDEX_MAX = std::numeric_limits<std::int16_t>::max();
        static constexpr base::Int16 DEFAULT_Z_INDEX = 0;

    private:
        /// @brief Z索引
        base::Int16 m_z_index = DEFAULT_Z_INDEX;

    protected:
        /// @brief 变换
        Transform2D m_transform;
        mutable glm::mat4 m_MVP_cache = glm::mat4(1.0f);

    public:
        Visual2D() = default;
        ~Visual2D() = default;

    protected:
        /// @brief 当Z索引改变时
        /// @param old_z_index 旧Z索引
        /// @param new_z_index 新Z索引
        virtual void _on_z_index_changed(base::Int16 old_z_index, base::Int16 new_z_index);

    public:
        Transform2D &get_transform();
        const Transform2D &get_transform() const;
        void set_transform(const Transform2D &transform);
        base::Int16 get_z_index() const;
        void set_z_index(base::Int16 z_index);

    public:
        const glm::mat4 &get_model_matrix() const override;
        const glm::mat4 &get_MVP_matrix() const override;
        void update_matrix(Camera &camera) const override;
    };

} // namespace gl_renderer
