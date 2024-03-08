#include <bits/stdc++.h>
using namespace std;

// Function to traverse the DAG
// and apply Dynamic Programming
// to find the longest path
void dfs(int node, vector<int> adj[], int dp[], bool vis[]) {
    // Mark as visited
    vis[node] = true;

    // Traverse for all its children
    for (int i = 0; i < adj[node].size(); i++) {
        // If not visited
        if (!vis[adj[node][i]])
            dfs(adj[node][i], adj, dp, vis);

        // Store the max of the paths
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

// Function that returns the longest path
int findLongestPath(vector<int> adj[], int n) {
    // Dp array
    int dp[n + 1];
    memset(dp, 0, sizeof dp);

    // Visited array to know if the node
    // has been visited previously or not
    bool vis[n + 1];
    memset(vis, false, sizeof vis);

    // Call DFS for every unvisited vertex
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, adj, dp, vis);
    }

    int ans = 0;

    // Traverse and find the maximum of all dp[i]
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    ifstream inputFile("input2.txt");
    ofstream outputFile("output2.txt");
    
    int n;
    inputFile >> n;
    vector<int> adj[n + 1];

    int u, v;
    while (inputFile >> u >> v) {
        addEdge(adj, u, v);
    }

    int longestPath = findLongestPath(adj, n);
    outputFile << "Longest path in the DAG: " << longestPath << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
