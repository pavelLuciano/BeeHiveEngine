#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <vector>
#include <EntityAttribute.h>
class Entity
{
public:
    std::vector<EntityAttribute*> Attributes; 
    Entity();
    ~Entity();

private:

};
#endif