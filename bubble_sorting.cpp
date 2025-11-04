#include <iostream>
#include <vector>
using namespace std;

struct Product {
    string name;
    float price;
    float rating;
};

void bubbleSort(vector<Product> &products, bool sortByPrice) {
    int n = products.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool condition = sortByPrice ? (products[j].price > products[j+1].price)
                                         : (products[j].rating > products[j+1].rating);
            if (condition) {
                swap(products[j], products[j+1]);
            }
        }
    }
}

void display(const vector<Product> &products) {
    for (auto &p : products) {
        cout << p.name << " - Price: " << p.price << ", Rating: " << p.rating << endl;
    }
    cout << endl;
}

int main() {
    vector<Product> products = {
        {"Shoes", 3000, 4.3},
        {"Backpack", 1800, 4.1},
        {"Watch", 7500, 4.7},
        {"Sunglasses", 2200, 4.0},
        {"Jacket", 5500, 4.5}
    };

    cout << "Original List:\n";
    display(products);

    bubbleSort(products, true); // sort by price
    cout << "Bubble Sort by Price:\n";
    display(products);

    return 0;
}
