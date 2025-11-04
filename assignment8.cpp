#include <iostream>
#include <string>
using namespace std;

// Node structure for BST
struct Node {
    string name;
    Node* left;
    Node* right;

    Node(string val) {
        name = val;
        left = right = nullptr;
    }
};

// Function to insert a new contact
Node* insert(Node* root, string name) {
    if (root == nullptr) {
        return new Node(name);
    }
    if (name < root->name) {
        root->left = insert(root->left, name);
    } else if (name > root->name) {
        root->right = insert(root->right, name);
    }
    // duplicate ignored
    return root;
}

// Function to search for a contact
bool search(Node* root, string name) {
    if (root == nullptr) return false;
    if (root->name == name) return true;
    if (name < root->name) return search(root->left, name);
    return search(root->right, name);
}

// Helper function to find minimum node in a subtree
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a contact
Node* deleteNode(Node* root, string name) {
    if (root == nullptr) return root;

    if (name < root->name) {
        root->left = deleteNode(root->left, name);
    } else if (name > root->name) {
        root->right = deleteNode(root->right, name);
    } else {
        // Case A: no child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case B: one child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case C: two children
        Node* temp = findMin(root->right);
        root->name = temp->name;
        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

// Inorder traversal to display contacts in sorted order
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->name << endl;
    inorder(root->right);
}

// Menu-driven program
int main() {
    Node* root = nullptr;
    int choice;
    string name;

    do {
        cout << "\n---- Contact List Menu ----\n";
        cout << "1. Insert Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Display All Contacts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name to insert: ";
                cin >> name;
                root = insert(root, name);
                cout << "Contact inserted.\n";
                break;

            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                if (search(root, name))
                    cout << "Contact found.\n";
                else
                    cout << "Contact not found.\n";
                break;

            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                root = deleteNode(root, name);
                cout << "Contact deleted if it existed.\n";
                break;

            case 4:
                cout << "All contacts (sorted):\n";
                inorder(root);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);

    return 0;
}
