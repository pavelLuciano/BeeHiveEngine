#ifndef _I_CONTROLABLE_H_
#define _I_CONTROLABLE_H_
class IControlable
{
public:
    virtual void processInput()         = 0;
    virtual void processKeyBoardInput() = 0;
    virtual void processMouseInput()    = 0;
    virtual void processJoystickInput() = 0;
};
#endif