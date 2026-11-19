#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle() : vehicleID(""), manufacturer(""), model(""), year(0) {
        totalVehicles++;
    }

    Vehicle(string id, string mfg, string mdl, int yr)
        : vehicleID(id), manufacturer(mfg), model(mdl), year(yr) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    string getVehicleID() const { return vehicleID; }
    void setVehicleID(string id) { vehicleID = id; }

    string getManufacturer() const { return manufacturer; }
    void setManufacturer(string mfg) { manufacturer = mfg; }

    string getModel() const { return model; }
    void setModel(string mdl) { model = mdl; }

    int getYear() const { return year; }
    void setYear(int yr) { year = yr; }

    virtual void display() const {
        cout << "\n--- Vehicle Details ---\n";
        cout << "ID           : " << vehicleID << "\n";
        cout << "Manufacturer : " << manufacturer << "\n";
        cout << "Model        : " << model << "\n";
        cout << "Year         : " << year << "\n";
    }
};

int Vehicle::totalVehicles = 0;


class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car() : Vehicle(), fuelType("") {}

    Car(string id, string mfg, string mdl, int yr, string fuel)
        : Vehicle(id, mfg, mdl, yr), fuelType(fuel) {}

    string getFuelType() const { return fuelType; }
    void setFuelType(string fuel) { fuelType = fuel; }

    void display() const override {
        cout << "\n--- Car Details ---\n";
        cout << "ID           : " << vehicleID << "\n";
        cout << "Manufacturer : " << manufacturer << "\n";
        cout << "Model        : " << model << "\n";
        cout << "Year         : " << year << "\n";
        cout << "Fuel Type    : " << fuelType << "\n";
    }
};

class ElectricCar : public Car {
protected:
    double batteryCapacity; // in kWh

public:
    ElectricCar() : Car(), batteryCapacity(0.0) {}

    ElectricCar(string id, string mfg, string mdl, int yr, string fuel, double battery)
        : Car(id, mfg, mdl, yr, fuel), batteryCapacity(battery) {}

    double getBatteryCapacity() const { return batteryCapacity; }
    void setBatteryCapacity(double battery) { batteryCapacity = battery; }

    void display() const override {
        cout << "\n--- Electric Car Details ---\n";
        cout << "ID               : " << vehicleID << "\n";
        cout << "Manufacturer     : " << manufacturer << "\n";
        cout << "Model            : " << model << "\n";
        cout << "Year             : " << year << "\n";
        cout << "Fuel Type        : " << fuelType << "\n";
        cout << "Battery Capacity : " << batteryCapacity << " kWh\n";
    }
};

class Aircraft {
protected:
    double flightRange; // in km

public:
    Aircraft() : flightRange(0.0) {}
    Aircraft(double range) : flightRange(range) {}

    double getFlightRange() const { return flightRange; }
    void setFlightRange(double range) { flightRange = range; }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() : Car(), Aircraft(0.0) {}

    FlyingCar(string id, string mfg, string mdl, int yr, string fuel, double range)
        : Car(id, mfg, mdl, yr, fuel), Aircraft(range) {}

    void display() const override {
        cout << "\n--- Flying Car Details ---\n";
        cout << "ID           : " << vehicleID << "\n";
        cout << "Manufacturer : " << manufacturer << "\n";
        cout << "Model        : " << model << "\n";
        cout << "Year         : " << year << "\n";
        cout << "Fuel Type    : " << fuelType << "\n";
        cout << "Flight Range : " << flightRange << " km\n";
    }
};

class SportsCar : public ElectricCar {
private:
    double topSpeed; // in km/h

public:
    SportsCar() : ElectricCar(), topSpeed(0.0) {}

    SportsCar(string id, string mfg, string mdl, int yr, string fuel, double battery, double speed)
        : ElectricCar(id, mfg, mdl, yr, fuel, battery), topSpeed(speed) {}

    double getTopSpeed() const { return topSpeed; }
    void setTopSpeed(double speed) { topSpeed = speed; }

    void display() const override {
        cout << "\n--- Sports Car Details ---\n";
        cout << "ID               : " << vehicleID << "\n";
        cout << "Manufacturer     : " << manufacturer << "\n";
        cout << "Model            : " << model << "\n";
        cout << "Year             : " << year << "\n";
        cout << "Fuel Type        : " << fuelType << "\n";
        cout << "Battery Capacity : " << batteryCapacity << " kWh\n";
        cout << "Top Speed        : " << topSpeed << " km/h\n";
    }
};

class Sedan : public Car {
private:
    int seatingCapacity;

public:
    Sedan() : Car(), seatingCapacity(5) {}

    Sedan(string id, string mfg, string mdl, int yr, string fuel, int seats = 5)
        : Car(id, mfg, mdl, yr, fuel), seatingCapacity(seats) {}

    int getSeatingCapacity() const { return seatingCapacity; }
    void setSeatingCapacity(int seats) { seatingCapacity = seats; }

    void display() const override {
        cout << "\n--- Sedan Details ---\n";
        cout << "ID               : " << vehicleID << "\n";
        cout << "Manufacturer     : " << manufacturer << "\n";
        cout << "Model            : " << model << "\n";
        cout << "Year             : " << year << "\n";
        cout << "Fuel Type        : " << fuelType << "\n";
        cout << "Seating Capacity : " << seatingCapacity << "\n";
    }
};

class SUV : public Car {
private:
    bool hasAWD;

public:
    SUV() : Car(), hasAWD(true) {}

    SUV(string id, string mfg, string mdl, int yr, string fuel, bool awd = true)
        : Car(id, mfg, mdl, yr, fuel), hasAWD(awd) {}

    bool getHasAWD() const { return hasAWD; }
    void setHasAWD(bool awd) { hasAWD = awd; }

    void display() const override {
        cout << "\n--- SUV Details ---\n";
        cout << "ID           : " << vehicleID << "\n";
        cout << "Manufacturer : " << manufacturer << "\n";
        cout << "Model        : " << model << "\n";
        cout << "Year         : " << year << "\n";
        cout << "Fuel Type    : " << fuelType << "\n";
        cout << "AWD          : " << (hasAWD ? "Yes" : "No") << "\n";
    }
};

class VehicleRegistry {
private:
    static const int MAX_VEHICLES = 100;
    Vehicle* vehicles[MAX_VEHICLES];
    int count;

public:
    VehicleRegistry() : count(0) {
        for (int i = 0; i < MAX_VEHICLES; i++) {
            vehicles[i] = nullptr;
        }
    }

    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehicles[i];
            vehicles[i] = nullptr;
        }
    }

    void addVehicle(Vehicle* v) {
        if (count >= MAX_VEHICLES) {
            cout << "Registry full! Vadhu vehicle add nathi thai shakta.\n";
            delete v;
            return;
        }
        vehicles[count++] = v;
        cout << "Vehicle successfully add thai gayu!\n";
    }

    void viewAllVehicles() const {
        if (count == 0) {
            cout << "\nRegistry ma koi vehicle nathi.\n";
            return;
        }
        cout << "\nTotal Vehicles in Registry: " << Vehicle::totalVehicles << "\n";
        for (int i = 0; i < count; i++) {
            vehicles[i]->display();
        }
    }

    void searchByID(const string& id) const {
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                cout << "\nVehicle madi gayu:\n";
                vehicles[i]->display();
                return;
            }
        }
        cout << "\nID '" << id << "' mate koi vehicle nathi malyu.\n";
    }
};

void inputCommonDetails(string& id, string& mfg, string& mdl, int& yr) {
    cout << "Enter Vehicle ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Manufacturer: ";
    getline(cin, mfg);
    cout << "Enter Model: ";
    getline(cin, mdl);
    cout << "Enter Year: ";
    cin >> yr;
    cin.ignore();
}

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "   VEHICLE REGISTRY SYSTEM\n";
        cout << "1. Add a Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "\nSelect Vehicle Type:\n";
            cout << "1. Car\n";
            cout << "2. Electric Car\n";
            cout << "3. Flying Car\n";
            cout << "4. Sports Car\n";
            cout << "5. Sedan\n";
            cout << "6. SUV\n";
            cout << "Enter type: ";
            cin >> type;

            string id, mfg, mdl, fuel;
            int yr;
            inputCommonDetails(id, mfg, mdl, yr);

            if (type == 1) {
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                registry.addVehicle(new Car(id, mfg, mdl, yr, fuel));
            } else if (type == 2) {
                double battery;
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                cout << "Enter Battery Capacity (kWh): ";
                cin >> battery;
                registry.addVehicle(new ElectricCar(id, mfg, mdl, yr, fuel, battery));
            } else if (type == 3) {
                double range;
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                cout << "Enter Flight Range (km): ";
                cin >> range;
                registry.addVehicle(new FlyingCar(id, mfg, mdl, yr, fuel, range));
            } else if (type == 4) {
                double battery, speed;
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                cout << "Enter Battery Capacity (kWh): ";
                cin >> battery;
                cout << "Enter Top Speed (km/h): ";
                cin >> speed;
                registry.addVehicle(new SportsCar(id, mfg, mdl, yr, fuel, battery, speed));
            } else if (type == 5) {
                int seats;
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                cout << "Enter Seating Capacity: ";
                cin >> seats;
                registry.addVehicle(new Sedan(id, mfg, mdl, yr, fuel, seats));
            } else if (type == 6) {
                int awdChoice;
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                cout << "Has AWD? (1 for Yes, 0 for No): ";
                cin >> awdChoice;
                registry.addVehicle(new SUV(id, mfg, mdl, yr, fuel, awdChoice == 1));
            } else {
                cout << "Invalid vehicle type!\n";
            }
        } else if (choice == 2) {
            registry.viewAllVehicles();
        } else if (choice == 3) {
            string searchId;
            cout << "Enter Vehicle ID to search: ";
            cin >> searchId;
            registry.searchByID(searchId);
        } else if (choice == 4) {
            cout << "Exiting program...\n";
        } else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}