#include <Shader.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader()
{

}
Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
    loadFile(vertexPath, fragmentPath);
}
Shader::~Shader()
{

}
std::string Shader::readFile(const std::string& path) const
{
    //TAREA
    //probar que no haya copias innecesarias de strings, imprimiendo las direcciones de memoria
    std::ifstream fileStream;
    std::stringstream code;
    fileStream.open(path.c_str());
    code << fileStream.rdbuf();
    fileStream.close();
    return code.str();
}
GLuint Shader::compileShader(int type, const std::string& shaderSource)
{
    GLuint shader = glCreateShader(type);
    const char* cShaderSrc = shaderSource.c_str();
    glShaderSource(shader, 1, &cShaderSrc, nullptr);
	glCompileShader(shader);
    return shader;
}
GLuint Shader::compileShaderProgram(GLuint vertID, GLuint fragID)
{
    GLuint progID = glCreateProgram();
    glAttachShader(progID, vertID);
    glAttachShader(progID, fragID);
    glLinkProgram(progID);
    return progID;
}
void Shader::loadFile(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vertexShaderSource   = readFile(vertexPath);
    std::string fragmentShaderSource = readFile(fragmentPath);
    GLuint vertexID, fragmentID;
    vertexID   = compileShader(GL_VERTEX_SHADER,   vertexShaderSource);
    fragmentID = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    checkCompileErrors(vertexID, "VERTEX");
    checkCompileErrors(fragmentID, "FRAGMENT");
    id = compileShaderProgram(vertexID, fragmentID);
    checkCompileErrors(id,"PROGRAM");
    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
}
void Shader::checkCompileErrors(GLuint shader, std::string type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}
void Shader::use() const
{
    glUseProgram(id);
}
void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(
        glGetUniformLocation(id, name.c_str()),
        1,
        GL_FALSE,
        &mat[0][0]
    );
}
void Shader::setMat3(const std::string& name, const glm::mat3& mat) const
{
    glUniformMatrix3fv(
        glGetUniformLocation(id, name.c_str()),
        1,
        GL_FALSE,
        &mat[0][0]
    );
}
void Shader::setMat2(const std::string& name, const glm::mat2& mat) const
{
    glUniformMatrix2fv(
        glGetUniformLocation(id, name.c_str()),
        1,
        GL_FALSE,
        &mat[0][0]
    );
}
void Shader::setVec4(const std::string& name , const glm::vec4& vec) const
{
    glUniform4fv(
        glGetUniformLocation(id, name.c_str()),
        1,
        &vec[0]
    );
}
void Shader::setVec3(const std::string& name, const glm::vec3& vec) const
{
    glUniform3fv(
        glGetUniformLocation(id, name.c_str()),
        1,
        &vec[0]
    );
}
void Shader::setVec2(const std::string& name, const glm::vec2& vec) const
{
    glUniform2fv(
        glGetUniformLocation(id, name.c_str()),
        1,
        &vec[0]
    );
}
void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
{
    glUniform4f(
        glGetUniformLocation(id, name.c_str()),
        x,y,z,w
    );
}
void Shader::setVec3(const std::string& name, float x, float y, float z) const
{
    glUniform3f(
        glGetUniformLocation(id, name.c_str()),
        x,y,z
    );
}
void Shader::setVec2(const std::string& name, float x, float y) const
{
    glUniform2f(
        glGetUniformLocation(id, name.c_str()),
        x,y
    );
}
void Shader::setFloat(const std::string& name, float value) const
{
    glUniform1f(
        glGetUniformLocation(id, name.c_str()),
        value
    );
}
void Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(
        glGetUniformLocation(id, name.c_str()),
        value
    );
}
void Shader::setBool(const std::string& name, bool value) const
{
    glUniform1i(
        glGetUniformLocation(id, name.c_str()),
        (int) value
    );
}

void Shader::setCamera(Camera& _cam)
{
    setMat4("projection", _cam.getProjection());
    setMat4("view",       _cam.getView());
}
void Shader::setCamera(Camera* _cam)
{
    setMat4("projection", _cam->getProjection());
    setMat4("view",       _cam->getView());
}