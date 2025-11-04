#include <iostream>
#include <vector>
using namespace std;

struct Product {
    string name;
    float price;
    float rating;
};

void insertionSort(vector<Product> &products, bool sortByPrice) {
    int n = products.size();
    for (int i = 1; i < n; i++) {
        Product key = products[i];
        int j = i - 1;
        while (j >= 0 && (sortByPrice ? (products[j].price > key.price)
                                      : (products[j].rating > key.rating))) {
            products[j+1] = products[j];
            j--;
        }
        products[j+1] = key;
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

    insertionSort(products, true); // sort by price
    cout << "Insertion Sort by Price:\n";
    display(products);

    return 0;
}
