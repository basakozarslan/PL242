//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#include "Car.h"
#include <iostream>
#include <string.h>

using namespace std;

Car::Car():Vehicle() {
    this->Cartype = carType::None;
}

Car::Car(int id, char* brand, char* model, char* plateNo, carType ct): Vehicle(id, brand, model, plateNo) {
    this->Cartype = ct;
}

int Car::getSeats() {
    if(this->Cartype == carType::Sedan){
        return 5;
    }
    else if(this->Cartype == carType::Hatchback){
        return 5;
    }
    else if(this->Cartype == carType::Limousine){
        return 6;
    }
    else{
        cout<< "None!" << endl;
        return 0;
    }

}

bool Car::checkSuitability(int numOfPeople) {
    return numOfPeople <= getSeats();
}

float Car::annualCost() {
    float km;
    cout<<"Enter the kilometres driven:";
    cin>>km;
    return (10.0*km);
}

void Car::printVehicle() {
    cout<< "Vehicle ID:" << this->vehicleID << endl;
    cout<< "Brand:" << this->brand << endl;
    cout<< "Model:" << this->model << endl;
    cout<< "Plate Number:" << this->plateNo << endl;
    if(this->Cartype == carType::Sedan){
        cout << "Car Type: Sedan"  << endl;
    }
    else if(this->Cartype == carType::Hatchback){
        cout << "Car Type: Hatchback"  << endl;
    }
    else if(this->Cartype == carType::Limousine){
        cout << "Car Type: Limousine"  << endl;
    }
    cout<< "Number of Seats:" << getSeats() << endl;
}

char Car::returnVehicleType() {
    return 'c';
}

