#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <vector>
#include <EntityAttribute.h>
class Entity
{
protected:
    std::vector<EntityAttribute*> Attributes; 
    Entity();
    virtual ~Entity();
private:
    static unsigned int entityIDCount;
public:
    unsigned int entityID;
};
#endif