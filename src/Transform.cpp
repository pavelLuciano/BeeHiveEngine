#include <Transform.h>

Transform::Transform()
{
    pos =         glm::vec3(0.0f, 0.0f, 0.0f);
    scale =       glm::vec3(1.0f);
    rotation =    {0.0f, 0.0f, 0.0f};
    xAxis_Local = glm::vec3(1.0f, 0.0f, 0.0f);
    yAxis_Local = glm::vec3(0.0f, 1.0f, 0.0f);
    zAxis_Local = glm::vec3(0.0f, 0.0f, 1.0f);
}
Transform::~Transform()
{

}
//Transformations
void Transform::Translate(glm::vec3 translation){ pos += translation;                 }
void Transform::TranslateX(float _x)            { pos += glm::vec3(_x, pos.y, pos.z); }
void Transform::TranslateY(float _y)            { pos += glm::vec3(pos.x, _y, pos.z); }
void Transform::TranslateZ(float _z)            { pos += glm::vec3(pos.x, pos.y, _z); }
void Transform::TranslateTo(glm::vec3 _pos)     { pos = _pos;                         }
void Transform::TranslateXTo(float _x)          { pos = glm::vec3(_x, pos.y, pos.z);  }
void Transform::TranslateYTo(float _y)          { pos = glm::vec3(pos.x, _y, pos.z);  }
void Transform::TranslateZTo(float _z)          { pos = glm::vec3(pos.x, pos.y, _z);  }
void Transform::scaleAll(glm::vec3 _scale)      { scale = _scale;                          }
void Transform::scaleX(float _sx)               { scale = glm::vec3(_sx, scale.y, scale.z);}
void Transform::scaleY(float _sy)               { scale = glm::vec3(scale.x, _sy, scale.z);}
void Transform::scaleZ(float _sz)               { scale = glm::vec3(scale.x, scale.y, _sz);}

void Transform::eulerRotateX_Global(float)
{

}
void Transform::eulerRotateY_Global(float)
{

}
void Transform::eulerRoteteZ_Global(float)
{

}
void Transform::eulerRotateX_Local(float)
{

}
void Transform::eulerRotateY_Local(float)
{

}
void Transform::eulerRotateZ_Local(float)
{

}
void Transform::updateAxles()
{

}
void Transform::updateRotationValues()
{

}