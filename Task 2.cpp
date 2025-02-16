#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Property {
private:
    T owner;
    T address;
    int bedrooms;
    long price;

public:
    void getInput() {
        cout << "Enter Owner: ";
        getline(cin, owner);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Number Of Bedrooms: ";
        cin >> bedrooms;
        cin.ignore();
        cout << "Price: ";
        cin >> price;
        cin.ignore();
    }
    void printValues() {
        cout << "\n" << owner << "\t" << address << "\t" << bedrooms << "\t" << price << endl;
    }
    T getAddress() {
        return address;
    }
    int getBedrooms() {
        return bedrooms;
    }
    float getPrice() {
        return price;
    }
};

int main() {
    const int MAX_HOUSES = 100;
    Property<string> houses[MAX_HOUSES];
    int numHouses = 0;
    while (true) {
        cout << "\n1. Add house";
        cout << "\n2. Search by price";
        cout << "\n3. Search by bedrooms";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            if (numHouses < MAX_HOUSES) {
                houses[numHouses].getInput();
                numHouses++;
            }
            else {
                cout << "Maximum number of houses reached!" << endl;
            }
        }
        else if (choice == 2) {
            float price;
            cout << "Enter maximum price: ";
            cin >> price;
            cin.ignore();
            for (int i = 0; i < numHouses; i++) {
                if (houses[i].getPrice() <= price) {
                    houses[i].printValues();
                }
            }
        }
        else if (choice == 3) {
            int bedrooms;
            cout << "Enter minimum number of bedrooms: ";
            cin >> bedrooms;
            cin.ignore();
            for (int i = 0; i < numHouses; i++) {
                if (houses[i].getBedrooms() >= bedrooms) {
                    houses[i].printValues();
                }
            }
        }
        else if (choice == 4) {
            break;
        }
    }
    cout << "\nOwner\tAddress\tBedrooms\tPrice" << endl;
    for (int i = 0; i < numHouses; i++) {
        houses[i].printValues();
    }
    return 0;
}