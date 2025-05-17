#ifndef _MESH_H_
#define _MESH_H_
#include <vector>
#include <string>
#include <IDrawable.h>
#include <glm/glm.hpp>


#define MAX_BONE_INFLUENCE 4
struct Vertex
{
    glm::vec3 position;
    //glm::vec3 color;
    glm::vec3 normal;
    glm::vec2 textureCoords;
    //revisar para que sirve esto
    
    glm::vec3 tangent;
    glm::vec3 bitangent;
	int m_BoneIDs[MAX_BONE_INFLUENCE];
	float m_Weights[MAX_BONE_INFLUENCE];
};
struct Texture
{
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh : IDrawable
{
public:
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures;
    unsigned int VAO;

    Mesh();
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    Mesh(const std::string&);
    ~Mesh();

    void setupMesh(const std::string&);
    void setupMesh();
    void loadFile(const std::string&);
    void logData();

    void draw() const override;
    void draw(Shader&) const override;
private:
    unsigned int EBO, VBO;
};
#endif