#pragma once

#include <base/core/polymorphic_object.hpp>

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(Visual);
    class Renderer;
    class Camera;

    /// @brief 可视的对象基类
    class Visual : public base::PolymorphicObject
    {
    private:
        /// @brief 是否可见
        bool m_is_visible = true;

    public:
        inline Visual() = default;
        inline ~Visual() override = default;

    protected:
        /// @brief 当可见性改变时
        virtual void _on_visibility_changed() {}

        /// @brief 绘制
        /// @param renderer 渲染器
        virtual void _draw(const Renderer &renderer) const = 0;

    public:
        inline bool is_visible() const { return m_is_visible; }
        inline void show() { set_visibility(true); }
        inline void hide() { set_visibility(false); }
        void set_visibility(bool is_visible)
        {
            if (m_is_visible == is_visible)
                return;

            m_is_visible = is_visible;
            _on_visibility_changed();
        }

    public:
        /// @brief 请求进行绘制
        void request_draw(const Renderer &renderer) const
        {
            if (m_is_visible)
                _draw(renderer);
        }

        /// @brief 获取模型矩阵
        /// @return 模型矩阵
        virtual const glm::mat4 &get_model_matrix() const = 0;

        /// @brief 获取模型视图投影矩阵
        /// @return 模型视图投影矩阵
        virtual const glm::mat4 &get_MVP_matrix() const = 0;

        /// @brief 更新矩阵
        /// @param camera 相机
        virtual void update_matrix(Camera &camera) const = 0;
    };

} // namespace gl_renderer
