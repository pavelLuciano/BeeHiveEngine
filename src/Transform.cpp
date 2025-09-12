#include <Transform.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

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

void Transform::setPitch(float _pitch)          { rotation.pitch = _pitch;  }
void Transform::setHead(float _head)            { rotation.head  = _head;   }
void Transform::setRoll(float _roll)            { rotation.roll  = _roll;   }

void Transform::rotateX_Global(float _angle) {rotation.pitch += _angle;}
void Transform::rotateY_Global(float _angle) {rotation.head += _angle; }
void Transform::roteteZ_Global(float _angle) {rotation.roll += _angle; }
void Transform::rotateX_Local(float _angle)
{
    zAxis_Local = glm::rotate(zAxis_Local, glm::radians(_angle), xAxis_Local);
    yAxis_Local = glm::rotate(yAxis_Local, glm::radians(_angle), xAxis_Local);
}
void Transform::rotateY_Local(float _angle)
{
    xAxis_Local = glm::rotate(xAxis_Local, glm::radians(_angle), yAxis_Local);
    zAxis_Local = glm::rotate(zAxis_Local, glm::radians(_angle), yAxis_Local);
}
void Transform::rotateZ_Local(float _angle)
{
    yAxis_Local = glm::rotate(yAxis_Local, glm::radians(_angle), zAxis_Local);
    zAxis_Local = glm::rotate(zAxis_Local, glm::radians(_angle), zAxis_Local);
}

void Transform::rotateAround(float _angle, glm::vec3 _vec)
{
    xAxis_Local = glm::rotate(xAxis_Local, glm::radians(_angle), _vec);
    yAxis_Local = glm::rotate(yAxis_Local, glm::radians(_angle), _vec);
    zAxis_Local = glm::rotate(zAxis_Local, glm::radians(_angle), _vec);
}

glm::vec3 Transform::getLocalXAxis() {return xAxis_Local;};
glm::vec3 Transform::getLocalYAxis() {return yAxis_Local;};
glm::vec3 Transform::getLocalZAxis() {return zAxis_Local;};

void Transform::updateAxles()
{

}
void Transform::updateRotationValues()
{
    //esta funcion asume que la matriz de rotacion utilizada es EulerXYZ
    rotation.head   = glm::degrees(std::asin(-getLocalXAxis()[2]));
    rotation.pitch = glm::degrees(std::atan2(getLocalYAxis()[2],getLocalZAxis()[2]));
    rotation.roll  = glm::degrees(std::atan2(getLocalXAxis()[1],getLocalXAxis()[0]));
}

glm::mat4 Transform::getRotationMatrix()
{
    glm::mat4 rotation = glm::mat4(1.0f);
    rotation[0] = glm::vec4(xAxis_Local, 0.0f);
    rotation[1] = glm::vec4(yAxis_Local, 0.0f);
    rotation[2] = glm::vec4(zAxis_Local, 0.0f);
    return rotation;
}