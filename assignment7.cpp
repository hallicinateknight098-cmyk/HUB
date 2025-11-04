#include <iostream>
#include <limits>
using namespace std;

int readInt(const string &prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) return x;
        // bad input -> clear and retry
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid integer.\n";
    }
}

// ---------- Singly Linked Train ----------
struct SinglyNode {
    int id;
    SinglyNode* next;
    SinglyNode(int x): id(x), next(nullptr) {}
};

class SinglyTrain {
    SinglyNode* head;
public:
    SinglyTrain(): head(nullptr) {}
    ~SinglyTrain() {
        while (head) { SinglyNode* t = head; head = head->next; delete t; }
    }

    void addCoach(int x) {
        SinglyNode* node = new SinglyNode(x);
        if (!head) head = node;
        else {
            SinglyNode* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
        cout << "Coach " << x << " added.\n";
    }

    bool removeCoach(int x) {
        if (!head) return false;
        if (head->id == x) {
            SinglyNode* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        SinglyNode* cur = head;
        while (cur->next && cur->next->id != x) cur = cur->next;
        if (!cur->next) return false;
        SinglyNode* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        return true;
    }

    void forward() const {
        if (!head) { cout << "Train is empty.\n"; return; }
        cout << "Train (front -> back): ";
        SinglyNode* cur = head;
        while (cur) {
            cout << cur->id << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

// ---------- Doubly Linked Train ----------
struct DoublyNode {
    int id;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int x): id(x), next(nullptr), prev(nullptr) {}
};

class DoublyTrain {
    DoublyNode* head;
    DoublyNode* tail;
public:
    DoublyTrain(): head(nullptr), tail(nullptr) {}
    ~DoublyTrain() {
        DoublyNode* cur = head;
        while (cur) { DoublyNode* t = cur; cur = cur->next; delete t; }
    }

    void addCoach(int x) {
        DoublyNode* node = new DoublyNode(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        cout << "Coach " << x << " added.\n";
    }

    bool removeCoach(int x) {
        DoublyNode* cur = head;
        while (cur && cur->id != x) cur = cur->next;
        if (!cur) return false;
        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        else tail = cur->prev;
        delete cur;
        return true;
    }

    void forward() const {
        if (!head) { cout << "Train is empty.\n"; return; }
        cout << "Train (front -> back): ";
        DoublyNode* cur = head;
        while (cur) {
            cout << cur->id << " ";
            cur = cur->next;
        }
        cout << "\n";
    }

    void backward() const {
        if (!tail) { cout << "Train is empty.\n"; return; }
        cout << "Train (back -> front): ";
        DoublyNode* cur = tail;
        while (cur) {
            cout << cur->id << " ";
            cur = cur->prev;
        }
        cout << "\n";
    }
};

// ---------- Circular Linked Train ----------
struct CircularNode {
    int id;
    CircularNode* next;
    CircularNode(int x): id(x), next(nullptr) {}
};

class CircularTrain {
    CircularNode* tail;
public:
    CircularTrain(): tail(nullptr) {}
    ~CircularTrain() {
        if (!tail) return;
        CircularNode* start = tail->next;
        CircularNode* cur = start;
        do {
            CircularNode* nxt = cur->next;
            delete cur;
            cur = nxt;
        } while (cur != start);
        tail = nullptr;
    }

    void addCoach(int x) {
        CircularNode* node = new CircularNode(x);
        if (!tail) {
            tail = node;
            node->next = node;
        } else {
            node->next = tail->next;
            tail->next = node;
            tail = node;
        }
        cout << "Coach " << x << " added.\n";
    }

    bool removeCoach(int x) {
        if (!tail) return false;
        CircularNode* cur = tail->next;
        CircularNode* prev = tail;
        do {
            if (cur->id == x) break;
            prev = cur;
            cur = cur->next;
        } while (cur != tail->next);

        if (cur->id != x) return false; // not found
        if (cur == prev) { // only one node
            delete cur;
            tail = nullptr;
            return true;
        }
        prev->next = cur->next;
        if (cur == tail) tail = prev;
        delete cur;
        return true;
    }

    void forward(int steps) const {
        if (!tail) { cout << "Train is empty.\n"; return; }
        if (steps <= 0) { cout << "Steps must be > 0.\n"; return; }
        cout << "Train (circular, " << steps << " steps): ";
        CircularNode* cur = tail->next;
        for (int i = 0; i < steps; ++i) {
            cout << cur->id << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

// ---------- Main ----------
int main() {
    int choice = readInt("Choose train type:\n1. Singly\n2. Doubly\n3. Circular\nChoice: ");

    if (choice == 1) {
        SinglyTrain t;
        int opt;
        do {
            cout << "\n--- Singly Train Menu ---\n1.Add 2.Remove 3.Forward 4.Exit\n";
            opt = readInt("Choice: ");
            if (opt == 1) {
                int id = readInt("Coach ID to add: ");
                t.addCoach(id);
            } else if (opt == 2) {
                int id = readInt("Coach ID to remove: ");
                cout << (t.removeCoach(id) ? "Coach removed.\n" : "Coach not found.\n");
            } else if (opt == 3) {
                t.forward();
            }
        } while (opt != 4);
    }
    else if (choice == 2) {
        DoublyTrain t;
        int opt;
        do {
            cout << "\n--- Doubly Train Menu ---\n1.Add 2.Remove 3.Forward 4.Backward 5.Exit\n";
            opt = readInt("Choice: ");
            if (opt == 1) {
                int id = readInt("Coach ID to add: ");
                t.addCoach(id);
            } else if (opt == 2) {
                int id = readInt("Coach ID to remove: ");
                cout << (t.removeCoach(id) ? "Coach removed.\n" : "Coach not found.\n");
            } else if (opt == 3) {
                t.forward();
            } else if (opt == 4) {
                t.backward();
            }
        } while (opt != 5);
    }
    else if (choice == 3) {
        CircularTrain t;
        int opt;
        do {
            cout << "\n--- Circular Train Menu ---\n1.Add 2.Remove 3.Forward(steps) 4.Exit\n";
            opt = readInt("Choice: ");
            if (opt == 1) {
                int id = readInt("Coach ID to add: ");
                t.addCoach(id);
            } else if (opt == 2) {
                int id = readInt("Coach ID to remove: ");
                cout << (t.removeCoach(id) ? "Coach removed.\n" : "Coach not found.\n");
            } else if (opt == 3) {
                int steps = readInt("Steps to move forward (positive integer): ");
                t.forward(steps);
            }
        } while (opt != 4);
    } else {
        cout << "Invalid train type. Exiting.\n";
    }

    return 0;
}
