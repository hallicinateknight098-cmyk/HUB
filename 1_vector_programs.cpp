#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    vector<int>v;
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

for (string car : cars) {
  cout << car << "\n";
}
    
    return 0;
}