#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int> adj[], int dp[], bool vis[]) {
    
    vis[node] = true;

   
    for (int i = 0; i < adj[node].size(); i++) {
        
        if (!vis[adj[node][i]])
            dfs(adj[node][i], adj, dp, vis);

        
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}


void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}


int findLongestPath(vector<int> adj[], int n) {
   
    int dp[n + 1];
    memset(dp, 0, sizeof dp);

    
    bool vis[n + 1];
    memset(vis, false, sizeof vis);

    
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, adj, dp, vis);
    }

    int ans = 0;

    
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
