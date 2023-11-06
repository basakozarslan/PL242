//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#ifndef CNG242_BRANCH_H
#define CNG242_BRANCH_H


#include "Vehicle.h"

class Branch {
private:
    int branchID;
    char* city;
    Vehicle* vehicles[30];
    int numOfVehicles;
public:
    Branch();
    Branch(int,char*);
    Branch(Branch&);
    ~Branch();
    void operator=(Branch&);
    int getBranchID();
    char* getCity();
    int getNumOfVehicles();
    void setBranchID(int id);
    void setCity(char* city);
    void setNumOfVehicles(int numOfVehicles);
    void addVehicle(Vehicle&);
    void printBranch();
    void printVehicles();
    void printVehiclesByType(int);
    void printTypeStatistics();
    void printVehiclesBySeat(int);
    float printAnnualCost();


};


#endif //CNG242_BRANCH_H