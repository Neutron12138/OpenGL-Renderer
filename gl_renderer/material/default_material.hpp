#pragma once

#include <string>
#include <unordered_map>
#include "material.hpp"

namespace gl_renderer
{
    BASE_DECLARE_REF_TYPE(DefaultMaterial);

    /// @brief 默认材质
    class DefaultMaterial : public Material
    {
    public:
        /// @brief 统一变量位置
        enum class UniformLocation : GLint
        {
            MVP,
            Texture,
        };

        const std::unordered_map<std::string, GLint> UNIFORM_HASH_MAP =
            {
                {"u_MVP", static_cast<GLint>(UniformLocation::MVP)},
                {"u_texture", static_cast<GLint>(UniformLocation::Texture)},
            };

    protected:
        /// @brief 着色器程序
        gl_wrapper::Program m_program;

    protected:
        DefaultMaterial(const std::string &vsource, const std::string &fsource);

    public:
        ~DefaultMaterial() override = default;

    public:
        bool is_valid() const override;
        void bind() const override;
        void set_MVP_matrix(const glm::mat4 &MVP) override;

        template <typename T>
        void set_uniform(const std::string &name, const T &value)
        {
            auto iter = UNIFORM_HASH_MAP.find(name);
            if (iter == UNIFORM_HASH_MAP.cend())
                throw BASE_MAKE_RUNTIME_ERROR("\"", name, "\" is not a valid uniform name");

            m_program.set_uniform(iter->second, value);
        }
    };

} // namespace gl_renderer
