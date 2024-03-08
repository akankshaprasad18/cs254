#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;

    void DFS(int i, int parent, int visited[], int mark[], int low[], int tin[], vector<int> adj[], vector<int> &ans) {
        visited[i] = 1;
        low[i] = tin[i] = timer;
        int child = 0;
        timer++;
        for (auto it : adj[i]) {
            if (it == parent) {
                continue;
            }
            if (!visited[it]) {
                DFS(it, i, visited, mark, low, tin, adj, ans);
                low[i] = min(low[i], low[it]);
                if (low[it] >= tin[i] && parent != -1) {
                    mark[i]++;
                }
                child++;
            } else {
                low[i] = min(low[i], tin[it]);
            }
            if (child > 1 && parent == -1) {
                mark[i] = 1;
            }
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> ans;
        int n = V;

        int low[n];
        int tin[n];
        int visited[n];
        int mark[n];

        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            mark[i] = 0;
        }
        DFS(0, -1, visited, mark, low, tin, adj, ans);
        for (int i = 0; i < n; i++) {
            if (mark[i] > 0) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) {
            return {-1};
        }

        return ans;
    }
};

int main() {
    // Input file handling
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> adj[n];
    for (auto it : edges) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> nodes = obj.articulationPoints(n, adj);
    for (auto node : nodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

