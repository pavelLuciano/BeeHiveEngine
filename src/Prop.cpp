#include <Prop.h>

Prop::Prop()
{
    transform = new Transform();
    model = NULL;
    Attributes.push_back((EntityAttribute*)transform);
}
Prop::Prop(const std::string& filePath)
{
    transform = new Transform();
    Attributes.push_back((EntityAttribute*)transform);
    //la clase creada debe ser EntityAtribute e IDrawable al mismo tiempo
    Mesh* mod = new Mesh(filePath);
    model = (IDrawable*) mod;
    Attributes.push_back((EntityAttribute*) mod);
}
Prop::~Prop()
{
    //como hay que borrar idrawable?
    //delete transform;
    //delete model; ?
}
void Prop::draw() const
{
    model->draw();
}