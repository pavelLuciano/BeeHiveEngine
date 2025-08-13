#include <Entity.h>
#include <BeeHiveEngine.h>
#include <iostream>

unsigned int Entity::entityIDCount = 0x0;
Entity::Entity()
{
    entityID = entityIDCount++; 
    std::cout <<"["<< entityID <<"]" << " Creando Entidad " << std::endl; 
}
Entity::~Entity()
{
    for (auto x: Attributes) delete x;
    std::cout <<"["<< entityID <<"]" <<  " Entidad Destruida" << std::endl;
}