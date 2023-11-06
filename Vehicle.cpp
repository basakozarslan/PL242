//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#include "Vehicle.h"
#include <iostream>
#include <string.h>
using namespace std;

Vehicle::Vehicle() {
    this->vehicleID =-1;
    this->brand = new char[50];
    strcpy(this->brand, "Undefined");
    this->model = new char[50];
    strcpy(this->model, "Undefined");
    this->plateNo = new char[50];
    strcpy(this->plateNo, "Undefined");
}

Vehicle::Vehicle(int id, char* brand, char* model, char* plateNo) {
    this->vehicleID =id;
    this->brand = new char[50];
    strcpy(this->brand, brand);
    this->model = new char[50];
    strcpy(this->model, model);
    this->plateNo = new char[50];
    strcpy(this->plateNo, plateNo);
}

Vehicle::Vehicle(Vehicle& v) {
    this->vehicleID = v.vehicleID;
    this->brand = new char[50];
    strcpy(this->brand, v.brand);
    this->model = new char[50];
    strcpy(this->model, v.model);
    this->plateNo = new char[50];
    strcpy(this->plateNo, v.plateNo);
}

Vehicle::~Vehicle() {
    delete[] this->brand;
    delete[] this->model;
    delete[] this->plateNo;
}

//getters
int Vehicle::getVehicleID() {
    return this->vehicleID;
}

char* Vehicle::getBrand() {
    return this->brand;
}

char * Vehicle::getModel() {
    return this->model;
}

char * Vehicle::getPlateNo() {
    return this->plateNo;
}

//setters
void Vehicle::setVehicleID(int id) {
    this->vehicleID = id;
}

void Vehicle::setBrand(char *brand) {
    strcpy(this->brand, brand);
}

void Vehicle::setModel(char *model) {
    strcpy(this->model, model);
}

void Vehicle::setPlateNo(char *plateNo) {
    strcpy(this->plateNo, plateNo);
}

void Vehicle::printVehicle() {
    cout<<"Vehicle No:" << this->vehicleID;
    cout<<"Brand:" << this->brand;
    cout<<"Model" << this->model;
    cout<<"Plate No" << this->plateNo;
}

bool Vehicle::checkSuitability(int) {
    return true;
}

float Vehicle::annualCost() {
    return true;
}

char Vehicle::returnVehicleType() {
    return 'v';
}

//assignment operator overload
void Vehicle::operator=(Vehicle& v){
    vehicleID = v.vehicleID;
    strcpy(brand, v.brand);
    strcpy(model, v.model);
    strcpy(plateNo, v.plateNo);
}