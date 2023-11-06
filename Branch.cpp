//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#include "Branch.h"
#include "Car.h"
#include "Bus.h"
#include "Vehicle.h"
#include <iostream>
#include <string.h>
using namespace std;


//Default constructor
Branch::Branch(){
    this->branchID=-1;
    this->city = new char[50];
    strcpy(this->city, "Undefined");
    this->numOfVehicles=0;

}
//Constructor with argument
Branch::Branch(int id1,char* city1){
    this->branchID=id1;
    this->city = new char[50];
    strcpy(this->city, city1);
    this->numOfVehicles=0;
}

//Copy constructor
Branch::Branch(Branch& b){
    int i;
    this->branchID=b.branchID;
    this->city = new char[50];
    strcpy(this->city, b.city);
    this->numOfVehicles= b.numOfVehicles;
    for(i=0; i<b.numOfVehicles; i++){
        this->vehicles[i]= b.vehicles[i];
    }
}

//Destructor
Branch::~Branch(){

    delete[] this->city;

}

//getters
int Branch::getBranchID() {
    return this->branchID;
}

char* Branch::getCity() {
    return this->city;
}

int Branch::getNumOfVehicles() {
    return this->numOfVehicles;
}

//setters
void Branch::setBranchID(int id) {
    this->branchID = id;
}

void Branch::setCity(char *city) {
    strcpy(this->city, city);
}

void Branch::setNumOfVehicles(int numOfVehicles) {
    this->numOfVehicles = numOfVehicles;
}

void Branch::addVehicle(Vehicle& vehicle) {
    if(this->numOfVehicles<30){
        this->vehicles[numOfVehicles++]= &vehicle;
    }
}

void Branch::printBranch() {
    cout<< "Branch ID:" << this->branchID << endl;
    cout << "City:" << this->city << endl;
    cout<< "Number of Vehicles:" << this->numOfVehicles << endl;
}

void Branch::printVehicles() {
    cout<< "Vehicles in Branch:" << this->branchID << "." << endl;
    int i;
    for(i=0; i< this->numOfVehicles ; i++){
        vehicles[i]->printVehicle();
        cout<<"\n";
    }
}

void Branch::printVehiclesByType(int choice) {
    cout<< "Vehicle at Branch with ID:" << this->branchID << endl;
    if(choice==0){   //Bus
        int i;
        for(i=0; i< this->numOfVehicles ; i++){
            if (vehicles[i]->returnVehicleType() == 'b') {
                vehicles[i]->printVehicle();
            }
            cout << "\n";
        }
    }
    else if(choice==1){  //Car
        int i;
        for(i=0; i< this->numOfVehicles ; i++){
            if (vehicles[i]->returnVehicleType() == 'c') {
                vehicles[i]->printVehicle();
            }
            cout << "\n";
        }
    }
    else{
        cout<<"Enter valid choice!" << endl;
    }
}

void Branch::printTypeStatistics() {
    int i;
    int countCar =0;
    int countBus =0;
    for(i=0; i< this->numOfVehicles ; i++){
        if (vehicles[i]->returnVehicleType() == 'c'){
           countCar++;
        }
        else if(vehicles[i]->returnVehicleType() == 'b'){
            countBus++;
        }
    }
    cout<< countBus <<" bus(es)" << endl;
    cout<< countCar << " car(s)" << endl;
}

void Branch::printVehiclesBySeat(int seat) {
    cout<< "Vehicles in Branch:" << this->branchID << "." << endl;
    int i;
    for(i=0; i< this->numOfVehicles ; i++){
        if (vehicles[i]->returnVehicleType() == 'c'){
            if(vehicles[i]->checkSuitability(seat)){
                vehicles[i]->printVehicle();
                cout<<"\n";
            }
        }
        else if(vehicles[i]->returnVehicleType() == 'b'){
            if(vehicles[i]->checkSuitability(seat)){
                vehicles[i]->printVehicle();
                cout<<"\n";
            }
        }
    }
}

float Branch::printAnnualCost() {
    float total =0.0;
    int i;
    for(i=0; i< this->numOfVehicles ; i++){
        cout<<"Vehicle" << (i+1) << ":" << endl;
        if (vehicles[i]->returnVehicleType() == 'c'){
            total += vehicles[i]->annualCost();
        }
        else if(vehicles[i]->returnVehicleType() == 'b'){
            total+= vehicles[i]->annualCost();
        }
    }
    cout<<"Total Annual Cost for Branch with ID: " << this->branchID << " is " << total << endl ;
    return total;
}

//assignment operator overload
void Branch::operator=(Branch& b){
    branchID = b.branchID;
    strcpy(city, b.city);
    numOfVehicles = b.numOfVehicles;
}



