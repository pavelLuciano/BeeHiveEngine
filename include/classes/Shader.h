#ifndef _SHADER_H_
#define _SHADER_H_
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

#include <Camera.h>

#define DEFAULT_FRAGMENT_SHADER "./resources/shaders/defaultFragment.glsl"
#define DEFAULT_VERTEX_SHADER   "./resources/shaders/defaultVertex.glsl"
class Shader
{
public:
    GLuint id;

    Shader(const std::string&, const std::string&);
    Shader();
    ~Shader();
    void use() const;
    void loadFile(const std::string&, const std::string&);
    void setMat4(const std::string&, const glm::mat4&) const;
    void setMat3(const std::string&, const glm::mat3&) const;
    void setMat2(const std::string&, const glm::mat2&) const;
    void setVec4(const std::string&, const glm::vec4&) const;
    void setVec3(const std::string&, const glm::vec3&) const;
    void setVec2(const std::string&, const glm::vec2&) const;
    void setVec4(const std::string&, float, float, float, float) const;
    void setVec3(const std::string&, float, float, float) const;
    void setVec2(const std::string&, float, float) const;
    void setFloat(const std::string&,float) const;
    void setInt(const std::string&, int) const;
    void setBool(const std::string&, bool) const;

    void setCamera(Camera&);

private:
    GLuint compileShader(int,const std::string& );
    GLuint compileShaderProgram(GLuint, GLuint);
    void checkCompileErrors(GLuint shader, std::string type);
    std::string readFile(const std::string&) const;
};
#endif