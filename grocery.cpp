#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Item {
    string name;
    int quantity;
    float price;
};

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    cin.ignore();

    vector<Item> inventory(n); // Fixed size vector

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of item " << i + 1 << ": ";
        getline(cin, inventory[i].name);
        cout << "Enter quantity: ";
        cin >> inventory[i].quantity;
        cout << "Enter price per unit: ";
        cin >> inventory[i].price;
        cin.ignore();
    }

    cout << "\n--- Grocery Store Inventory ---\n";
    cout << left << setw(15) << "Item Name" 
         << setw(10) << "Quantity" 
         << setw(10) << "Price" 
         << setw(15) << "Total Value" << endl;
    cout << "--------------------------------------------------------\n";

    float grandTotal = 0;
    for (int i = 0; i < n; i++) {
        float totalValue = inventory[i].quantity * inventory[i].price;
        grandTotal += totalValue;
        cout << left << setw(15) << inventory[i].name 
             << setw(10) << inventory[i].quantity 
             << setw(10) << inventory[i].price 
             << setw(15) << totalValue << endl;
    }

    cout << "\nGrand Total Stock Value: Rs. " << grandTotal << endl;

    return 0;
}
