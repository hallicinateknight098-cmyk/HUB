#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> marks;
    int n, mark;
    int sum = 0;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> mark;
        marks.push_back(mark);
        sum += mark;
    }

    cout << "\nMarks entered:\n";
    for (int m : marks) {
        cout << m << " ";
    }
    cout << "\nAverage Marks = " << (float)sum / n << endl;

    return 0;
}
