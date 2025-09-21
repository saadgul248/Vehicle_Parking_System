#include<iostream>
using namespace std;

class VehicleParkingSystem {
private:
    int Bike, Car, Bus; 
    int totalExited, bikeExited, carExited, busExited;  
    int amount;  
    int count;  

public:
    // Constructor
    VehicleParkingSystem() {
        Bike = Car = Bus = 0;
        totalExited = bikeExited = carExited = busExited = 0;
        amount = count = 0;
        cout << "Vehicle Parking System initialized!" << endl;  
    }

    // Destructor
    ~VehicleParkingSystem() {
        cout << "Vehicle Parking System terminated!" << endl;  
    }

    void parkVehicle(int vehicleType) {
        if (vehicleType == 1) { // Bike
            if (Bike < 50) {
                Bike++;
                amount += 30;
                count++;
                cout << "\tBike parked. Fee: Rs30" << endl;
            } else {
                cout << "Parking is full for Bike" << endl;
            }
        } else if (vehicleType == 2) { // Car
            if (Car < 50) {
                Car++;
                amount += 50;
                count++;
                cout << "\tCar parked. Fee: Rs50" << endl;
            } else {
                cout << "Parking is full for Car" << endl;
            }
        } else if (vehicleType == 3) { // Bus
            if (Bus < 20) {
                Bus++;
                amount += 100;
                count++;
                cout << "\tBus parked. Fee: Rs100" << endl;
            } else {
                cout << "Parking is full for Bus" << endl;
            }
        } else {
            cout << "Invalid vehicle type!" << endl;
        }
    }

    void vehicleExit(int vehicleType) {
        if (vehicleType == 1 && Bike > 0) {
            Bike--;
            count--;
            totalExited++;
            bikeExited++;
            cout << "\tBike exited. Thank you!" << endl;
        } else if (vehicleType == 2 && Car > 0) {
            Car--;
            count--;
            totalExited++;
            carExited++;
            cout << "\tCar exited. Thank you!" << endl;
        } else if (vehicleType == 3 && Bus > 0) {
            Bus--;
            count--;
            totalExited++;
            busExited++;
            cout << "\tBus exited. Thank you!" << endl;
        } else {
            cout << "No such vehicle parked!" << endl;
        }
    }

    void displayRecords() {
        cout << "\nTotal amount of vehicle fee: Rs" << amount << endl;
        cout << "Total number of vehicles parked: " << count << endl;
        cout << "Total Bikes parked: " << Bike << endl;
        cout << "Total Cars parked: " << Car << endl;
        cout << "Total Buses parked: " << Bus << endl;
        cout << "Total number of vehicles exited: " << totalExited << endl;
        cout << "Total Bikes exited: " << bikeExited << endl;
        cout << "Total Cars exited: " << carExited << endl;
        cout << "Total Buses exited: " << busExited << endl;
    }

    void deleteRecords() {
        Bike = Car = Bus = 0;
        totalExited = bikeExited = carExited = busExited = 0;
        amount = count = 0;
        cout << "\tAll records have been deleted!" << endl;
    }

    void showMenu() {
        int x;
        cout << "\nVEHICLE PARKING TICKET SYSTEM\n";
        cout << "\nTicket Prices:\nBike=Rs30\tCar=Rs50\tBus=Rs100\n";
        cout << "\nPress 1 for Bike\nPress 2 for Car\nPress 3 for Bus\n";
        cout << "Press 4 for Vehicle Exit\nPress 5 to Show Records\n";
        cout << "Press 6 to Delete Records\nPress 7 to Exit\n";
        cout << "\nNOTE: Vehicles Parking Limits:\nBike 50\tCar 50\tBus 20\n";
        cin >> x;

        switch (x) {
            case 1:
            case 2:
            case 3:
                parkVehicle(x);
                break;
            case 4: {
                int vehicleType;
                cout << "Enter vehicle type to exit: \n1.Bike\t2.Car\t3.Bus\n";
                cin >> vehicleType;
                vehicleExit(vehicleType);
                break;
            }
            case 5:
                displayRecords();
                break;
            case 6:
                deleteRecords();
                break;
            case 7:
                cout << "\tThank You!" << endl;
                exit(0);
                break;
            default:
                cout << "You entered an invalid option!" << endl;
                break;
        }
    }
};

int main() {
    VehicleParkingSystem vps;
    while (true) {
        vps.showMenu();
    }
    return 0;
}