#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Contact { string name, phone; };

int main() {
    int n; cout << "Enter number of contacts: "; cin >> n;
    vector<Contact> pb(n); cin.ignore();
    for (auto &c : pb) {
        cout<<"Enter the Name: \n";
        getline(cin, c.name);
        cout<<"Enter the Number: \n";
         getline(cin, c.phone); }

    sort(pb.begin(), pb.end(), [](auto &a, auto &b){ return a.name < b.name; });

    string s; cout << "Enter name to search: "; getline(cin, s);
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (pb[m].name == s) { cout << pb[m].name << " - " << pb[m].phone; return 0; }
        (pb[m].name < s) ? l = m + 1 : r = m - 1;
    }
    cout << "Contact not found";
}
