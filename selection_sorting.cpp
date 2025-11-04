#include <iostream>
#include <vector>
using namespace std;

struct Product {
    string name;
    float price;
    float rating;
};

void selectionSort(vector<Product> &products, bool sortByPrice) {
    int n = products.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            bool condition = sortByPrice ? (products[j].price < products[minIndex].price)
                                         : (products[j].rating < products[minIndex].rating);
            if (condition) minIndex = j;
        }
        swap(products[i], products[minIndex]);
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

    selectionSort(products, false); // sort by rating
    cout << "Selection Sort by Rating:\n";
    display(products);

    return 0;
}
