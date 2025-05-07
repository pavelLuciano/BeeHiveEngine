#ifndef _PROP_H_
#define _PROP_H_
#include <Entity.h>
//atributes
#include <Transform.h>
//interfaces
#include <IDrawable.h>

class Prop: Entity, IDrawable
{
private:
    Transform* transform;
    
public:
    Prop();
    ~Prop();

};
#endif