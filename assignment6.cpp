#include <iostream>
#include <queue>
using namespace std;

class ServiceDesk {
private:
    queue<int> waitingList;
    int currentToken;

public:
    ServiceDesk() {
        currentToken = 1;
    }

    void giveToken() {
        cout << "Token generated: " << currentToken << endl;
        waitingList.push(currentToken);
        currentToken++;
    }

    void callNext() {
        if (waitingList.empty()) {
            cout << "No one is waiting right now!" << endl;
        } else {
            cout << "Now serving: Token " << waitingList.front() << endl;
            waitingList.pop();
        }
    }

    void showWaitingList() {
        if (waitingList.empty()) {
            cout << "Waiting area is empty." << endl;
        } else {
            cout << "Tokens in waiting: ";
            queue<int> temp = waitingList;
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    ServiceDesk counter;
    int menuChoice = 0;

    while (menuChoice != 4) {
        cout << "\n--- CLUB Service Desk ---\n";
        cout << "1. Get Token\n";
        cout << "2. Serve Next\n";
        cout << "3. Show Waiting Tokens\n";
        cout << "4. Exit\n";
        cout << "Enter your option: ";
        cin >> menuChoice;

        if (menuChoice == 1) {
            counter.giveToken();
        } 
        else if (menuChoice == 2) {
            counter.callNext();
        } 
        else if (menuChoice == 3) {
            counter.showWaitingList();
        } 
        else if (menuChoice == 4) {
            cout << "System closing... Goodbye!" << endl;
        } 
        else {
            cout << "Invalid option! Try again." << endl;
        }
    }

    return 0;
}
