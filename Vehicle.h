//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#ifndef CNG242_VEHICLE_H
#define CNG242_VEHICLE_H

class Vehicle {
protected:
    int vehicleID;
    char* brand;
    char* model;
    char* plateNo;
public:
    Vehicle();
    Vehicle(int,char*,char*,char*);
    Vehicle(Vehicle&);
    ~Vehicle();
    void operator=(Vehicle&);
    int getVehicleID();
    char* getBrand();
    char* getModel();
    char* getPlateNo();
    void setVehicleID(int id);
    void setBrand(char* brand);
    void setModel(char* model);
    void setPlateNo(char* plateNo);
    virtual void printVehicle();
    virtual char returnVehicleType();
    virtual bool checkSuitability(int);
    virtual float annualCost();
};


#endif //CNG242_VEHICLE_H
