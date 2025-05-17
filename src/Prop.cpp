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
    Model* mod = new Model(filePath);
    model = (IDrawable*) mod;
    Attributes.push_back((EntityAttribute*) mod);
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
{
    BeeHive::Graphic::defaultShader.use();
    //hay que setear projeccion y perspectiva?
    draw(BeeHive::Graphic::defaultShader);
}
void Prop::draw(Shader& shader) const
{
    //shader.use();
    glm::mat4 transMatrix = glm::mat4(1.0f);
    transMatrix = glm::translate(transMatrix, transform->pos);
    //rotacion cuidado con el orden;
    transMatrix = glm::rotate(transMatrix, transform->rotation.head, glm::vec3(0,1,0));
    transMatrix = glm::rotate(transMatrix, transform->rotation.pitch, glm::vec3(1,0,0));
    transMatrix = glm::rotate(transMatrix, transform->rotation.roll, glm::vec3(0,0,1));
    //sclae
    shader.setMat4("model", transMatrix);
    model->draw(shader);
}

void Prop::logData()
{
    ((Mesh*)model)->logData();
    std::cout <<( ((Mesh*)model)-> VAO )<< std::endl;
}