//
// Created by basak on 17.05.2023.
//

/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#ifndef CNG242_COMPANY_H
#define CNG242_COMPANY_H

#include "Branch.h"


class Company {
private:
    char* name;
    Branch* branches[10];
    int numOfBranches;
public:
    Company();
    Company(const char*);
    Company(Company&);
    ~Company();
    void operator=(Company&);
    char* getName();
    int getNumOfBranches();
    void setName(char* name);
    void setNumOfBranches(int numOfBranches);
    void addBranch (Branch&);
    void findBranchAddVehicle(int,Vehicle&);
    void printBranches();
    void printVehicles();
    void printVehiclesByType(int);
    void printTypeStatistics();
    void printVehiclesBySeat(int);
    void printAnnualCost();
    bool isFoundBranch(int);
};


#endif //CNG242_COMPANY_H
