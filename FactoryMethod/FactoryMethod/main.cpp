#include <iostream>

using namespace std;


enum VehicleType{
    VT_TwoWheeler, VT_ThreeWheeler, VT_Fourheeler
};

//Library classes
class Vehicle{
public:
    virtual void printVehicle()=0;
    static Vehicle* Create(VehicleType type);
};

class ThreeWheeler : public Vehicle {
public:
    void printVehicle() {
        cout << "I am three wheeler" << endl;
    }
};

class TwoWheeler: public Vehicle{
public:
    void printVehicle(){
        cout<<"I am two wheeler"<<endl;
    }
};

class FourWheeler :public Vehicle{
public:
    void printVehicle(){
        cout<<"I am four wheeler"<<endl;
    }
};


//Factory method to create objects of diffrent types.
//Change is required only in this function to crate o new object type

Vehicle* Vehicle::Create(VehicleType type){
    if (type ==VT_TwoWheeler)
        return new TwoWheeler();
    else if (type ==VT_ThreeWheeler)
        return new ThreeWheeler();
    else if (type == VT_Fourheeler)
        return new FourWheeler();
    else return NULL;
}


//CLient (or user) class

class Client{
public:
    // Client dosen't explicity create objects
    // but passes type to factory methood "Create()"
    Client(){
        VehicleType type =VT_Fourheeler;
        pVehicle =Vehicle::Create(type);
    }
    ~Client() {
        if (pVehicle)
        {
            delete[] pVehicle;
            pVehicle =NULL;
        }
    }

    Vehicle* getVehicle(){
        return pVehicle;
    }
private:
    Vehicle *pVehicle;
};

//Driver program
int main()
{
    Client *pClient = new Client();
    Vehicle* pVehicle = pClient -> getVehicle();
    pVehicle->printVehicle();
    return 0;
}
