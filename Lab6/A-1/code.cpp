#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> ans;
        int indegree[V] = {0};
        queue<int> q;

        // Calculate indegree for each vertex
        for (int i = 0; i < V; i++) {
            for (auto x : adj[i]) {
                indegree[x]++;
            }
        }

        // Push vertices with 0 indegree to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sorting
        while (!q.empty()) {
            int p = q.front();
            ans.push_back(p);
            q.pop();
            for (auto it : adj[p]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

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

    int V;
    inputFile >> V;

    vector<int> adj[V];
    int u, v;
    while (inputFile >> u >> v) {
        adj[u].push_back(v);
    }

    Solution obj;
    vector<int> sortedVertices = obj.topoSort(V, adj);

    // Writing sorted vertices to output file
    for (auto vertex : sortedVertices) {
        outputFile << vertex << " ";
    }

    inputFile.close();
    outputFile.close();

    cout << "Topological sorting result has been written to output.txt" << endl;

    return 0;
}
