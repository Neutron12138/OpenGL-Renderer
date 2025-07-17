#pragma once

#include <glm/glm.hpp>
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
        Visual() = default;
        ~Visual() override = default;

    protected:
        /// @brief 当可见性改变时
        virtual void _on_visibility_changed();

        /// @brief 绘制
        /// @param renderer 渲染器
        virtual void _draw(const Renderer &renderer) const = 0;

    public:
        bool is_visible() const;
        void show();
        void hide();
        void set_visibility(bool is_visible);

    public:
        /// @brief 请求进行绘制
        void request_draw(const Renderer &renderer) const;

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
