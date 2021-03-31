#ifndef IStateChangeWatcher_h
#define IStateChangeWatcher_h

class IStateChangeWatcher
{
    public:
        virtual void VoltageChanged(float voltage, float chargePortion);
        virtual void IsConnectedChanged(bool isConnected);
};

#endif