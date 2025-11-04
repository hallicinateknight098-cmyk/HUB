#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
};

class PhoneDirectory {
private:
    static const int TABLE_SIZE = 10;
    list<Contact> table[TABLE_SIZE];

    int hashFunction(string name) {
        int sum = 0;
        for (char c : name)
            sum += int(c);  
        return sum % TABLE_SIZE;
    }

public:
    void addContact(string name, string phone) {
        int index = hashFunction(name);

        // Check if contact already exists
        for (auto &contact : table[index]) {
            if (contact.name == name) {
                contact.phone = phone;
                cout << "Contact updated successfully!\n";
                return;
            }
        }

        // Add new contact if not found
        Contact newContact = {name, phone};
        table[index].push_back(newContact);
        cout << "Contact added successfully!\n";
    }

    // Search Contact
    void searchContact(string name) {
        int index = hashFunction(name);
        for (auto &contact : table[index]) {
            if (contact.name == name) {
                cout << "Found: " << contact.name << " - " << contact.phone << endl;
                return;
            }
        }
        cout << "Contact not found!\n";
    }

    // Delete Contact
    void deleteContact(string name) {
        int index = hashFunction(name);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->name == name) {
                table[index].erase(it);
                cout << "Contact deleted successfully!\n";
                return;
            }
        }
        cout << "Contact not found!\n";
    }

    // Display all contacts
    void displayContacts() {
        cout << "\nPhone Directory:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].empty()) {
                cout << "Bucket " << i << ": ";
                for (auto &contact : table[i]) {
                    cout << "[" << contact.name << ": " << contact.phone << "] ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    PhoneDirectory directory;
    int choice;
    string name, phone;

    do {
        cout << "\n=== Phone Directory Menu ===\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Display All Contacts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Phone Number: ";
            cin >> phone;
            directory.addContact(name, phone);
            break;
        case 2:
            cout << "Enter Name to Search: ";
            cin >> name;
            directory.searchContact(name);
            break;
        case 3:
            cout << "Enter Name to Delete: ";
            cin >> name;
            directory.deleteContact(name);
            break;
        case 4:
            directory.displayContacts();
            break;
        case 5:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
