#pragma once

#include <limits>
#include <base/core/type.hpp>
#include "visual.hpp"
#include "../matrix/transform_2d.hpp"

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

    public:
        inline Visual2D() = default;
        inline ~Visual2D() = default;

    protected:
        /// @brief 当Z索引改变时
        /// @param old_z_index 旧Z索引
        /// @param new_z_index 新Z索引
        virtual void _on_z_index_changed(base::Int16 old_z_index, base::Int16 new_z_index) {}

    public:
        inline Transform2D &get_transform() { return m_transform; }
        inline const Transform2D &get_transform() const { return m_transform; }
        inline void set_transform(const Transform2D &transform) { m_transform = transform; }
        inline base::Int16 get_z_index() const { return m_z_index; }
        void set_z_index(base::Int16 z_index)
        {
            if (m_z_index == z_index)
                return;

            base::Int16 old_z_index = m_z_index;
            m_z_index = z_index;
            _on_z_index_changed(old_z_index, m_z_index);
        }
    };

} // namespace gl_renderer
