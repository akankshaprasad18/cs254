#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int V = 1000;


bool isBipartiteUtil(vector<vector<int>>& G, int src, vector<int>& colorArr)
{
    colorArr[src] = 1;

    
    queue<int> q;
    q.push(src);

    
    while (!q.empty())
    {
        
        int u = q.front();
        q.pop();

       
        for (int v = 0; v < V; ++v)
        {
           
            if (G[u][v] && colorArr[v] == -1)
            {
                
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

           
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

   
    return true;
}


bool isBipartite(vector<vector<int>>& G)
{
    
    vector<int> colorArr(V, -1);

  
    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (isBipartiteUtil(G, i, colorArr) == false)
                return false;

    return true;
}


bool canBeDividedinTwoCliques(vector<vector<int>>& G)
{
    
    vector<vector<int>> GC(V, vector<int>(V));
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            GC[i][j] = (i != j) ? !G[i][j] : 0;

    
    return isBipartite(GC);
}

int main()
{
    ifstream input("input2.txt");
    ofstream output("output2.txt");

    vector<vector<int>> G(V, vector<int>(V));

   
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            input >> G[i][j];

    input.close();

   
    bool result = canBeDividedinTwoCliques(G);

  
    output << (result ? "Yes" : "No") << endl;

    output.close();

    return 0;
}
