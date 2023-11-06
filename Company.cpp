//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#include <iostream>
#include <string.h>
#include "Company.h"
using namespace std;

//Default constructor
Company::Company() {
    this->name = new char[50];
    strcpy(this->name, "Undefined");
    this->numOfBranches = 0;

    //Branch branches[10]; İÇİN BİR SEY YAZMIYOR MUYUZ??
}

//Constructor with argument
Company::Company(const char* name1) {
    this->name = new char[50];
    strcpy(this->name, name1);
    this->numOfBranches = 0;
}
//Copy constructor
Company::Company(Company& c) {
    int i;
    this->name = new char[50];
    strcpy(this->name, c.name);
    this->numOfBranches= c.numOfBranches;
    for(i=0; i<c.numOfBranches; i++){
        this->branches[i]=c.branches[i];
    }
}

//Destructor
Company::~Company() {
    int i;
    delete[] this->name;
    for (i = 0; i < numOfBranches; i++)
        delete this->branches[i];
}

//getters
char* Company::getName() {
    return this->name;
}

int Company::getNumOfBranches() {
    return this->numOfBranches;
}

//setters
void Company::setName(char *name) {
    strcpy(this->name, name);
}

void Company::setNumOfBranches(int numOfBranches) {
    this->numOfBranches = numOfBranches;
}


void Company::addBranch (Branch& branch){
    this->branches[numOfBranches++] = &branch;
}

void Company::findBranchAddVehicle(int id, Vehicle &v) {
    int i = 0;
    while (id != branches[i]->getBranchID()) {
        i++;
    }
    branches[i]->addVehicle(v);
}

void Company::printBranches() {
    int i;
    for(i=0; i<numOfBranches ;i++){
        cout<< "City: " << this->branches[i]->getCity();
        cout<< ", Number of Vehicles: " << this->branches[i]->getNumOfVehicles() << endl;
    }
}

void Company::printVehicles() {
    int i;
    for(i=0; i<numOfBranches ;i++){
        this->branches[i]->printVehicles();
    }
}


bool Company::isFoundBranch(int branchID) {
    int i;
    for(i=0;i<numOfBranches;i++){
        if(branchID == this->branches[i]->getBranchID()){
            return true;
        }

    }
    return false;
}
void Company::printTypeStatistics() {
    int i;
    for(i=0;i<numOfBranches;i++) {
        cout<< "At Branch with ID: " << branches[i]->getBranchID() << " there are:" << endl;
        this->branches[i]->printTypeStatistics();
    }
}

void Company::printVehiclesByType(int choice) {
    int i;
    for(i=0;i<numOfBranches;i++) {
        this->branches[i]->printVehiclesByType(choice);
    }
}

void Company::printAnnualCost() {
    float total=0.0;
    int i;
    for(i=0; i<numOfBranches; i++) {
        cout<< "Vehicles at Branch with ID " << branches[i]->getBranchID() << ":" << endl;
        total += this->branches[i]->printAnnualCost();
    }
    cout<<"Total Annual Cost for Quick Transport is "<< total << endl;
}

void Company::printVehiclesBySeat(int seat) {
    int i;
    for(i=0; i<numOfBranches ;i++){
        this->branches[i]->printVehiclesBySeat(seat);
    }
}

//assignment operator overload
void Company::operator=(Company& c){
    strcpy(name, c.name);
    numOfBranches = c.numOfBranches;
}
