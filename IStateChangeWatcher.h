#ifndef IStateChangeWatcher_h
#define IStateChangeWatcher_h

class IStateChangeWatcher
{
    public:
        //virtual void VoltageChanged(double voltage, double chargePortion);
        virtual void IsConnectedChanged(bool isConnected);
};

#endif