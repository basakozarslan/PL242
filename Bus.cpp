//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#include "Bus.h"
#include <iostream>
#include <string.h>

using namespace std;

Bus::Bus():Vehicle() {
    this->numOfSeats = 0;
}

Bus::Bus(int id, char* brand, char* model, char* plateNo, int numOfSeats ): Vehicle(id, brand, model, plateNo) {
    this->numOfSeats = numOfSeats;
}


bool Bus::checkSuitability(int numOfPeople) {
    return numOfPeople <= this->numOfSeats;
}

float Bus::annualCost() {
    float cost;
    int numOfServices;
    cout<<"Enter the maintenance cost:" ;
    cin>>cost;
    cout<<"Enter the number of times bus has been serviced:";
    cin>>numOfServices;
    return (cost * numOfServices);
}

void Bus::printVehicle() {
    cout<< "Vehicle ID:" << this->vehicleID << endl;
    cout<< "Brand:" << this->brand << endl;
    cout<< "Model:" << this->model << endl;
    cout<< "Plate Number:" << this->plateNo << endl;
    cout<< "Car Type: Bus" << endl;
    cout<< "Number of Seats:" << this->numOfSeats << endl;
}

char Bus::returnVehicleType() {
    return 'b';
}