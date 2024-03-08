#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    bool DFS(int i, int visited[], vector<int> adj[], int stack[]) {
        visited[i] = 1;
        stack[i] = 1;
        for (auto it : adj[i]) {
            if (!visited[it]) {
                if (DFS(it, visited, adj, stack)) {
                    return true;
                }
            } else if (stack[it]) {
                return true;
            }
        }
        stack[i] = 0;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int visited[V] = {0};
        int stack[V] = {0};

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFS(i, visited, adj, stack)) {
                    return true;
                }
            }
        }
        return false;
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

int main() {
    ifstream inputFile("input2.txt");
    ofstream outputFile("output2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Failed to open the files." << endl;
        return 1;
    }

    int V;
    inputFile >> V;

    vector<int> adj[V];
    int u, v;
    while (inputFile >> u >> v) {
        addEdge(adj, u, v);
    }

    Solution obj;
    if (obj.isCyclic(V, adj)) {
        outputFile << "Cycle Detected" << "\n";
    } else {
        outputFile << "No Cycle Detected";
    }

    inputFile.close();
    outputFile.close();

    cout << "Output has been written to output.txt" << endl;

    return 0;
}
