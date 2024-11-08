// In C++, it is possible to inherit attributes and methods from one class to another. We group the "inheritance concept" into two categories:

// derived class (child) - the class that inherits from another class
// base class (parent) - the class being inherited from
// To inherit from a class, use the : symbol.

// In the example below, the Car class (child) inherits the attributes and methods from the Vehicle class (parent):
#include <iostream>
using namespace std;

class IoTdevice
{
    private:
        string deviceId;
        string name;

    public:
        IoTdevice();
        void setId(string Id){
            deviceId = Id;
        };
        string getId(){
            return deviceId;
        };
        
        void updatetemp(double temp){
    cout << "New Temp is: " << temp <<endl;
};
};

// IoTdevice::IoTdevice(string Newdvice, string newname):deviceId(Newdvice), name(newname){};



int main(){
    
IoTdevice device;
device.updatetemp(34.45);

};