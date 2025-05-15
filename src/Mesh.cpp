#include <Mesh.h>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <iostream>

Mesh::Mesh()
{

}
Mesh::Mesh(const std::string& filePath)
{
    setupMesh(filePath);
    std::cout << VAO << std::endl;
}
Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
void Mesh::draw() const 
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
void Mesh::draw(Shader& shader) const
{
    draw();
}
void Mesh::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()* sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoords));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()*sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void Mesh::setupMesh(const std::string& filePath)
{
    loadFile(filePath);
    setupMesh();
}
void Mesh::loadFile(const std::string& filePath)
{
    enum Mode
    {
        VERTICES = 0, COLORS, INDICES
    };
    std::ifstream vertex_data_file(filePath.c_str());
    std::string line;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> colors;

    Mode current_mode = INDICES;
    while(getline(vertex_data_file, line))
    {
        if (line.find("VERTICES") != std::string::npos) 
        {
            current_mode = VERTICES;
            getline(vertex_data_file, line);
        }
        if (line.find("COLORS")  != std::string::npos)
        {
            current_mode = COLORS;
            getline(vertex_data_file, line);
        }
        if (line.find("INDICES")  != std::string::npos)
        {
            current_mode = INDICES;
            getline(vertex_data_file, line);
        }
        switch (current_mode)
        {
            case VERTICES:
            {
                std::istringstream iss(line);
                std::string x, y, z;
                iss >> x;
                iss >> y;
                iss >> z;
                vertices.push_back(glm::vec3(std::stof(x), std::stof(y), std::stof(z)));
            }
            break;
            case COLORS:
            {
                std::istringstream iss(line);
                std::string R, G, B;
                iss >> R;
                iss >> G;
                iss >> B;
                colors.push_back (glm::vec3(std::stof(R), std::stof(G), std::stof(B)));
            }
            break;
            case INDICES:
            {
                std::istringstream iss(line);
                std::string ind;
                while(iss >> ind) this->indices.push_back(std::stoi(ind));
            }
            break;
        }
    }
    for (long unsigned int i = 0; i< vertices.size(); i++)
    {
        this->vertices.push_back({vertices[i], colors[i], glm::vec2(0.0f,0.0f)});
    }
    vertex_data_file.close();
}
void Mesh::logData()
{
    for (Vertex v: vertices) std::cout << v.position.x << " " << v.position.y << " " << v.position.z << "|" << v.color.r << " " << v.color.g << " " << v.color.b << std::endl;
    for (unsigned int i = 0; i < indices.size(); )
    {
        std::cout << indices[i++] << " " << indices[i++] << " " << indices[i++] << std::endl;
    }
}