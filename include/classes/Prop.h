#ifndef _PROP_H_
#define _PROP_H_
#include <Entity.h>
//atributes
#include <Transform.h>
#include <Mesh.h>
//interfaces
#include <IDrawable.h>

class Prop: Entity, IDrawable
{
private:
    Transform* transform;
    IDrawable* model;
public:
    Prop();
    Prop(const std::string&);
    ~Prop();
    void draw() const override;
};
#endif