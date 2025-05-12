#ifndef _I_DRAWABLE_H_
#define _I_DRAWABLE_H_
#define DEFAULT_FRAGMENT_SHADER "./resources/shaders/defaultFragment.glsl"
#define DEFAULT_VERTEX_SHADER   "./resources/shaders/defaultVertex.glsl"
class IDrawable
{
public:
    virtual void draw() const = 0;
};
#endif