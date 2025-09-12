#ifndef _DEBUG_CAMERA_H_
#define _DEBUG_CAMERA_H_

#include "Camera.h"

class DebugCamera:  public Camera
{
public:
    virtual void update() override;
};

#endif