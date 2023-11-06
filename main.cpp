/* Başak Özarslan – 2385623
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */


#include <iostream>
#include "Company.h"
#include "Bus.h"
#include "Car.h"

using namespace std;

void displayMenu() {
    cout << "Options:" << endl;
    cout << "1. Add a new branch to the company." << endl;
    cout << "2. Add a new vehicle (car or bus) to a branch." << endl;
    cout << "3. Print all the branches along with their cities and the number of vehicles." << endl;
    cout << "4. Print the details stored as member variables for the vehicles in each branch." << endl;
    cout << "5. Print the details stored as member variables for the vehicles in each branch whose type is a given type." << endl;
    cout << "6. Print the number of each type of vehicle in each branch." << endl;
    cout << "7. Print the details stored as member variables for the vehicles that can carry a given number of people in each branch." << endl;
    cout << "8. Calculate the total annual cost for the company." << endl;
    cout << "9. Exit" << endl;
}

int main() {
    cout << "Welcome to Quick Transports" << endl;
    Company c1;


    int selection;

    do {
        displayMenu();
        cout << "Your selection: ";
        cin >> selection;

        switch (selection) {
            case 1: {
                Branch* b1 = new Branch();
                int id;
                char city[50];
                cout << "Please enter branch's ID:";
                cin >> id;
                cin.clear();
                cin.ignore(100, '\n');
                b1->setBranchID(id);
                cout << "Please enter the city, where branch is located:";
                cin.getline(city, 100);
                b1->setCity(city);
                c1.addBranch(*b1);
                break;
            }
            case 2: {
                int BranchID;
                int vehicleID;
                int choice;
                char brand[50];
                char model[50];
                char plateNo[50];
                int numOfSeats;

                carType type;
                cout << "Please enter the ID of the Branch:";
                cin >> BranchID;
                if (c1.isFoundBranch(BranchID) == true) {
                    cout << "What kind of vehicle would You like to add?" << endl;
                    cout << "Possible options: (0) Bus, (1) Sedan, (2) Hatchback, (3) Limousine" << endl;
                    cout << "Your choice:";
                    cin >> choice;

                    if (choice == 0) {

                        cout << "Please enter the ID of the vehicle:";
                        cin >> vehicleID;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter the brand of the vehicle:";
                        cin.getline(brand, 100);
                        cout << "Please enter the model of the vehicle:";
                        cin.getline(model, 100);
                        cout << "Please enter the plate number of the vehicle:";
                        cin.getline(plateNo, 100);
                        cout << "Please enter the number of seats on the Bus:";
                        cin >> numOfSeats;

                        c1.findBranchAddVehicle(BranchID,*new Bus(vehicleID, brand, model, plateNo, numOfSeats));

                        cout << "Vehicle is successfully added!" << endl;
                    }
                    if (choice == 1 || choice == 2 || choice == 3) {
                        cout << "Please enter the ID of the vehicle:" << endl;
                        cin >> vehicleID;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter the brand of the vehicle:" << endl;
                        cin.getline(brand, 100);
                        cout << "Please enter the model of the vehicle:" << endl;
                        cin.getline(model, 100);
                        cout << "Please enter the plate number of the vehicle:" << endl;
                        cin.getline(plateNo, 100);
                        if (choice == 1) {
                            type = carType::Sedan;
                        }
                        else if (choice == 2) {
                            type = carType::Hatchback;
                        }
                        else {
                            type = carType::Limousine;
                        }

                        c1.findBranchAddVehicle(BranchID, *new Car(vehicleID, brand, model, plateNo, type));

                        cout << "Vehicle is successfully added!" << endl;
                    }
                }
                else {
                    cout << "There is no branch with ID" << BranchID << " at Quick Transport" << endl;
                }
                break;
            }
            case 3:{
                c1.printBranches();
                break;
            }
            case 4:{
                c1.printVehicles();
                break;
            }
            case 5: {
                int choice;
                cout << "Please select the type of the vehicles, You want to see: (0) Bus, (1) Car" << endl;
                cin >> choice;
                c1.printVehiclesByType(choice);
                break;
            }
            case 6:{
            c1.printTypeStatistics();
                break;
            }
            case 7: {
                int seat;
                cout << "Please enter the number of passengers vehicle should be able to carry:";
                cin >> seat;
                c1.printVehiclesBySeat(seat);
                break;
            }
            case 8:{
                c1.printAnnualCost();
                break;
            }
            case 9:
                cout<<"Good Bye!";
            //default:
                //std::cout << "Invalid choice. Please try again." << endl;
                //break;
        }

        cout << endl;
    } while (selection != 9);

    return 0;
}