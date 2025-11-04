#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Contact {
    string name;
    string phone;
};

bool compareByName(const Contact &a, const Contact &b) {
    return a.name < b.name;
}

void linearSearch(const vector<Contact> &phonebook, const string &searchName) {
    bool found = false;
    for (const auto &contact : phonebook) {
        if (contact.name == searchName) {
            cout << "Contact Found: " << contact.name << " - " << contact.phone << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Contact not found\n";
}

void binarySearchFunc(vector<Contact> phonebook, const string &searchName) {
    sort(phonebook.begin(), phonebook.end(), compareByName);
    int left = 0, right = phonebook.size() - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (phonebook[mid].name == searchName) {
            cout << "Contact Found: " << phonebook[mid].name << " - " << phonebook[mid].phone << endl;
            found = true;
            break;
        }
        else if (phonebook[mid].name < searchName) left = mid + 1;
        else right = mid - 1;
    }
    if (!found) cout << "Contact not found\n";
}

int main() {
    int n;
    cout << "Enter number of contacts: ";
    cin >> n;

    vector<Contact> phonebook(n);
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Enter name of contact " << i + 1 << ": ";
        getline(cin, phonebook[i].name);
        cout << "Enter phone number of contact " << i + 1 << ": ";
        getline(cin, phonebook[i].phone);
    }

    string searchName;
    cout << "\nEnter name to search: ";
    getline(cin, searchName);

    int choice;
    cout << "\nMenu:\n1. Linear Search\n2. Binary Search\n3. Compare Time\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        linearSearch(phonebook, searchName);
    }
    else if (choice == 2) {
        binarySearchFunc(phonebook, searchName);
    }
    else if (choice == 3) {
        auto start1 = high_resolution_clock::now();
        linearSearch(phonebook, searchName);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<nanoseconds>(stop1 - start1).count();

        auto start2 = high_resolution_clock::now();
        binarySearchFunc(phonebook, searchName);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<nanoseconds>(stop2 - start2).count();

        cout << "\nTime taken by Linear Search: " << duration1 << " ns\n";
        cout << "Time taken by Binary Search: " << duration2 << " ns\n";
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
