#ifndef _MESH_H_
#define _MESH_H_
#include <vector>
#include <string>
#include <IDrawable.h>
#include <glm/glm.hpp>
struct Vertex
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 textureCoords;
};
struct Texture
{

};

class Mesh : IDrawable
{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> texture;
    unsigned int VAO;

    Mesh();
    Mesh(const std::string&);
    ~Mesh();

    void draw() const override;
    void setupMesh(const std::string&);
    void setupMesh();
    void loadFile(const std::string&);

    void draw() const override;
private:
    unsigned int EBO, VBO;
};

#endif