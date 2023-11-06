//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#include "Vehicle.h"

#ifndef CNG242_CAR_H
#define CNG242_CAR_H
enum class carType {None, Sedan, Hatchback, Limousine};

class Car : public Vehicle{
private:
    carType Cartype;
public:
    Car();
    Car(int,char*,char*,char*,carType);
    int getSeats();
    bool checkSuitability(int);
    float annualCost();
    void printVehicle();
    char returnVehicleType();


};


#endif //CNG242_CAR_H


