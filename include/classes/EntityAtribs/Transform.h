#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_
#include <EntityAttribute.h>
#include <glm/glm.hpp>
struct Rotation {float pitch, head, roll;};
class Transform : EntityAttribute 
{
public:
    glm::vec3 pos;
    glm::vec3 scale;
    Rotation rotation;
    glm::vec3 xAxis_Local;
    glm::vec3 yAxis_Local;
    glm::vec3 zAxis_Local;

    Transform();
    ~Transform();
    //Transformations
    void Translate(glm::vec3);
    void TranslateX(float);
    void TranslateY(float);
    void TranslateZ(float);
    void TranslateTo(glm::vec3);
    void TranslateXTo(float);
    void TranslateYTo(float);
    void TranslateZTo(float);
    void setPitch(float);
    void setHead(float);
    void setRoll(float);
    void eulerRotateX_Global(float);
    void eulerRotateY_Global(float);
    void eulerRoteteZ_Global(float);
    void eulerRotateX_Local(float);
    void eulerRotateY_Local(float);
    void eulerRotateZ_Local(float);
    void scaleAll(glm::vec3);
    void scaleX(float);
    void scaleY(float);
    void scaleZ(float);

    void updateAxles();
    void updateRotationValues();

};
#endif