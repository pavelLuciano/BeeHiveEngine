#include <Entity.h>
#include <iostream>

unsigned int Entity::entityIDCount = 0x0;
Entity::Entity()
{
    entityID = entityIDCount++; 
    std::cout << "Creando Entidad " << entityID << std::endl; 
}
Entity::~Entity()
{
    for (auto x: Attributes) delete x;
    std::cout << "Destruyendo Entidad " << entityID << std::endl;
}