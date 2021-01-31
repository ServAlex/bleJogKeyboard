#ifndef ViewModel_h
#define ViewModel_h

class ViewModel
{
    private:
    public:
        ViewModel(){};
        String modeName;
        String nextModeName;
        String previousModeName;
        int32_t modeIndex;
        int32_t modesCount;
        int32_t encoderValue;
        bool isInModeSelectionMode;
};

#endif