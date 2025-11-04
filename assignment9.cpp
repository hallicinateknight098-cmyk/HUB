#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Function to perform BFS (shortest path)
void BFS(map<char, vector<char>> graph, char start, char goal) {
    queue<vector<char>> q;
    q.push({start});
    cout << "\nBFS Traversal (Shortest Path):\n";

    while (!q.empty()) {
        vector<char> path = q.front();
        q.pop();
        char last = path.back();

        if (last == goal) {
            cout << "Shortest path found: ";
            for (char node : path) cout << node << " ";
            cout << endl;
            return;
        }

        for (char neighbor : graph[last]) {
            vector<char> newPath = path;
            newPath.push_back(neighbor);
            q.push(newPath);
        }
    }
    cout << "No path found.\n";
}

// Function to perform DFS (any path)
void DFS(map<char, vector<char>> graph, char start, char goal) {
    stack<vector<char>> s;
    s.push({start});
    cout << "\nDFS Traversal (Any Path):\n";

    while (!s.empty()) {
        vector<char> path = s.top();
        s.pop();
        char last = path.back();

        if (last == goal) {
            cout << "Path found: ";
            for (char node : path) cout << node << " ";
            cout << endl;
            return;
        }

        for (char neighbor : graph[last]) {
            vector<char> newPath = path;
            newPath.push_back(neighbor);
            s.push(newPath);
        }
    }
    cout << "No path found.\n";
}

int main() {
    // Representing the city map as an adjacency list
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D'}},
        {'C', {'E'}},
        {'D', {'E'}},
        {'E', {}}
    };

    cout << "City Map Locations:\n";
    cout << "A = Home\nB = Park\nC = School\nD = Hospital\nE = Restaurant\n";

    // Start from Home (A), find path to Hospital (D)
    BFS(graph, 'A', 'D');
    DFS(graph, 'A', 'D');

    return 0;
}
