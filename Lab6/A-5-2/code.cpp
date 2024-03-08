#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int timer = 1;

    void DFS(int i, int parent, int visited[], int low[], int tin[], vector<int> adj[], vector<vector<int>>& ans) {
        visited[i] = 1;
        low[i] = tin[i] = timer;
        timer++;
        for (auto it : adj[i]) {
            if (it == parent) {
                continue;
            }
            if (!visited[it]) {
                DFS(it, i, visited, low, tin, adj, ans);
                low[i] = min(low[i], low[it]);
                if (low[it] > tin[i]) {
                    ans.push_back({min(i, it), max(i, it)});
                }
            } else {
                low[i] = min(low[i], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;

        vector<int> adj[n];
        for (auto x : connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int low[n];
        int tin[n];
        int visited[n];
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }
        DFS(0, -1, visited, low, tin, adj, ans);
        return ans;
    }
};

int main() {
    ifstream inputFile("input2.txt");
    ofstream outputFile("output2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Failed to open the files." << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    vector<vector<int>> connections;
    for (int i = 0; i < n; ++i) {
        int u, v;
        inputFile >> u >> v;
        connections.push_back({u, v});
    }

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);
    for (auto it : bridges) {
        outputFile << "[" << it[0] << ", " << it[1] << "] ";
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();

    cout << "Output has been written to output.txt" << endl;

    return 0;
}
