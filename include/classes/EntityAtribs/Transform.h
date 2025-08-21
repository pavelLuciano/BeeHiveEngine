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
    void rotateX_Global(float);
    void rotateY_Global(float);
    void roteteZ_Global(float);
    void rotateX_Local(float);
    void rotateY_Local(float);
    void rotateZ_Local(float);
    void scaleAll(glm::vec3);
    void scaleX(float);
    void scaleY(float);
    void scaleZ(float);

    glm::vec3 getLocalXAxis();
    glm::vec3 getLocalYAxis();
    glm::vec3 getLocalZAxis();

    void updateAxles();
    void updateRotationValues();

    glm::mat4 getRotationMatrix();

};
#endif