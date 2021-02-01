#ifndef VolumeMode_h
#define VolumeMode_h

#include "IMode.h"

class VolumeMode: public IMode
{
    protected:
        ~VolumeMode(){};
    public:
        VolumeMode()
        {
            name = "volume";
            encoderAction = VolumeEncoder;
            secondaryEncoderAction = VolumeEncoder;
        };

        Action ActionNameForButton(int buttonPin)
        {
            switch (buttonPin)
            {
            case 35:
                return StartModeSelection;
                break;
            
            default:
                return None;
                break;
            }
        };
};

#endif
