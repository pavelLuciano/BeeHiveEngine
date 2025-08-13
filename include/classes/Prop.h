#ifndef _PROP_H_
#define _PROP_H_
#include <Entity.h>
//atributes
#include <Transform.h>
#include <Model.h>

class Prop: public Entity, public IDrawable
{
public:
    Transform* transform;
    Model* model;
    Prop();
    Prop(const std::string&);
    ~Prop();
    void draw() const override;
    void draw(Shader&) const override;
    void logData();
};
#endif