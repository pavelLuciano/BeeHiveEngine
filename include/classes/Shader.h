#ifndef _SHADER_H_
#define _SHADER_H_
#include <GL/glew.h>
#include <glm.hpp>
#include <string>
#include <vector>
class Shader
{
public:
    GLuint id;

    Shader();
    ~Shader();
    void use() const;
    void setMat4(const std::string&, const glm::mat4&);
    void setMat3(const std::string&, const glm::mat3&);
    void setMat2(const std::string&, const glm::mat2&);
    void setVec4(const std::string&, const glm::vec4&);
    void setVec3(const std::string&, const glm::vec3&);
    void setVec2(const std::string&, const glm::vec2&);
    void setFloat(const std::string&, float);
    void setInt(const std::string&, int);
    void setBool(const std::string&, bool);

private:
    void compileShader(int,const std::string& );
    void compileShaderProgram();
    void checkCompileErrors();

};
#endif