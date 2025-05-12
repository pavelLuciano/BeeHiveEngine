#ifndef _I_DRAWABLE_H_
#define _I_DRAWABLE_H_
#include <Shader.h>
class IDrawable
{
public:
    virtual void draw() const = 0;
    virtual void draw(Shader&) const = 0;
};
#endif