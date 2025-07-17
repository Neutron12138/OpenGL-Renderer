#pragma once

#include <string>
#include <unordered_map>
#include "material.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(ShaderMaterial);

    using UniformLocationHashMap = std::unordered_map<std::string, GLint>;

    /// @brief 默认材质
    class ShaderMaterial : public Material
    {
    protected:
        /// @brief 着色器程序
        gl_wrapper::ProgramRef m_program;
        /// @brief 统一变量位置
        mutable UniformLocationHashMap m_locations;

    public:
        ShaderMaterial() = default;
        ShaderMaterial(const gl_wrapper::ProgramRef &program);
        ShaderMaterial(const gl_wrapper::ShaderRef &vshader, const gl_wrapper::ShaderRef &fshader);
        ShaderMaterial(const std::string &vsource, const std::string &fsource);
        ShaderMaterial(ShaderMaterial &&from);
        ~ShaderMaterial() override = default;
        BASE_DELETE_COPY_FUNCTION(ShaderMaterial);

    public:
        ShaderMaterial &operator=(ShaderMaterial &&from);
        const gl_wrapper::ProgramRef &get_program() const;
        const UniformLocationHashMap &get_locations() const;
        bool is_valid() const override;

    public:
        void create(const gl_wrapper::ProgramRef &program);
        void create(const gl_wrapper::ShaderRef &vshader, const gl_wrapper::ShaderRef &fshader);
        void create(const std::string &vsource, const std::string &fsource);
        void destroy();

    public:
        void bind() const override;
        void set_MVP_matrix(const glm::mat4 &MVP) override;
        GLint get_uniform_location(const std::string &name) const;

    public:
        template <typename T>
        void set_uniform(const std::string &name, const T &value)
        {
            GLint location = get_uniform_location(name);
            m_program->set_uniform(location, value);
        }

        template <typename T>
        T get_uniform(const std::string &name) const
        {
            GLint location = get_uniform_location(name);
            return m_program->get_uniform<T>(location);
        }
    };

} // namespace gl_renderer
