#include <Prop.h>
#include <BeeHiveEngine.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Prop::Prop()
{
    transform = new Transform();
    model = NULL;
    Attributes.push_back((EntityAttribute*)transform);
    std::cout <<"["<< entityID <<"] " << "Prop Creado" << std::endl;
}
Prop::Prop(const std::string& filePath)
{
    transform = new Transform();
    Attributes.push_back((EntityAttribute*)transform);
    //la clase creada debe ser EntityAtribute e IDrawable al mismo tiempo
    model =  new Model(filePath);
    Attributes.push_back((EntityAttribute*) model);
    std::cout <<"["<< entityID <<"] " << "Prop Creado" << std::endl;
}
Prop::~Prop()
{
    //como hay que borrar idrawable?
    //delete transform;
    //delete model; ?
    std::cout <<"["<< entityID <<"] " << "Destruyendo Prop" << std::endl;
}
void Prop::draw() const
{/*
    glm::mat4 transMatrix = glm::mat4(1.0f);
    transMatrix = glm::translate(transMatrix, transform->pos);
    transMatrix = glm::rotate(transMatrix, transform->rotation.head, glm::vec3(0,1,0));
    transMatrix = glm::rotate(transMatrix, transform->rotation.pitch, glm::vec3(1,0,0));
    transMatrix = glm::rotate(transMatrix, transform->rotation.roll, glm::vec3(0,0,1));
    transMatrix = glm::scale(transMatrix, transform->scale);
    model->_shader->setMat4("model", transMatrix);
    model->draw();*/
}
void Prop::draw(Shader& _shader) const
{
    glm::mat4 transMatrix = glm::mat4(1.0f);
    transMatrix = glm::translate(transMatrix, transform->pos);
    transMatrix = glm::rotate(transMatrix, transform->rotation.head, glm::vec3(0,1,0));
    transMatrix = glm::rotate(transMatrix, transform->rotation.pitch, glm::vec3(1,0,0));
    transMatrix = glm::rotate(transMatrix, transform->rotation.roll, glm::vec3(0,0,1));
    transMatrix = glm::scale(transMatrix, transform->scale);
    _shader.setMat4("model", transMatrix);
    model->draw();
}

void Prop::logData()
{
    //((Mesh*)model)->logData();
    //std::cout <<( ((Mesh*)model)-> VAO )<< std::endl;
}