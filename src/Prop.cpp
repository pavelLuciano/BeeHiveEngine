#include <Prop.h>

Prop::Prop()
{
    transform = new Transform();
    Attributes.push_back((EntityAttribute*)transform);
}