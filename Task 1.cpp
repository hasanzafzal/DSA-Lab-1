#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Property {
private:
    T Owner;
    T Address;
    int Bedrooms;
    long Price;
public:
    void getInput() {
        cout << "Enter Owner: ";
        getline(cin, Owner);
        cout << "Enter Address: ";
        getline(cin, Address);
        cout << "Number of Bedrooms?: ";
        cin >> Bedrooms;
        cin.ignore();
        cout << "Price: ";
        cin >> Price;
        cin.ignore();
    }
    void printValues() const {
        cout << "\n" << Owner << "\t\t" << Address << "\t\t" << Bedrooms << "\t\t" << Price << endl;
    }
};

class RealEstateManager {
private:
    Property<string> properties[100];
    const int MAX_HOUSES;
    int numHouses;
public:
    RealEstateManager(int maxHouses) : MAX_HOUSES(maxHouses), numHouses(0) {}
    void addProperty() {
        if (numHouses < MAX_HOUSES) {
            properties[numHouses].getInput();
            numHouses++;
        }
        else {
            cout << "Maximum number of houses reached!" << endl;
        }
    }
    void displayProperties() const {
        cout << "\nOwner\t\tAddress\t\tBedrooms\t\tPrice" << endl;
        for (int i = 0; i < numHouses; i++) {
            properties[i].printValues();
        }
    }
    bool canAddMore() const {
        return numHouses < MAX_HOUSES;
    }
};

int main() {
    const int MAX_HOUSES = 100;
    RealEstateManager manager(MAX_HOUSES);
    char choice;
    do {
        if (manager.canAddMore()) {
            manager.addProperty();
        }
        else {
            break;
        }
        cout << "Enter another house? (Y/N) ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'Y' || choice == 'y');
    manager.displayProperties();
    return 0;
}