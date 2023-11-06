//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#include "Vehicle.h"
#ifndef CNG242_BUS_H
#define CNG242_BUS_H


class Bus : public Vehicle{
private:
    int numOfSeats;
public:
    Bus();
    Bus(int,char*,char*,char*,int);
    bool checkSuitability(int);
    float annualCost();
    void printVehicle();
    char returnVehicleType();
};


#endif //CNG242_BUS_H
