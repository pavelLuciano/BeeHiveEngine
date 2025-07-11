#ifndef _PROP_H_
#define _PROP_H_
#include <Entity.h>
//atributes
#include <Transform.h>
#include <Model.h>
//interfaces
#include <IDrawable.h>

class Prop: Entity, IDrawable
{
public:
    Transform* transform;
    IDrawable* model;
    Prop();
    Prop(const std::string&);
    ~Prop();
    void draw() const override;
    void draw(Shader&) const override;
    void logData();
};
#endif