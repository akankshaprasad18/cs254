#include <bits/stdc++.h>
using namespace std;
#define V 4


int travllingSalesmanProblem(int graph[][V], int s)
{
	
 vector<int> v;
 for (int i = 0; i < V; i++)
  if (i != s)
   v.push_back(i);

	
 int min_path = INT_MAX;
 do {

  
  int current = 0;

	
  int k = s;
  for (int i = 0; i < v.size(); i++) {
   current += graph[k][v[i]];
   k = v[i];
  }
  current+= graph[k][s];

  
  min_path = min(min_path, current);

 } while (
  next_permutation(v.begin(), v.end()));

 return min_path;
}


int main()
{
	
 int graph[][V] = { { 0, 20, 42, 35},
     { 20, 0, 30, 34 },
     { 42, 30, 0, 12 },
     { 35, 34, 12, 0 } };
 int s = 0;
 cout << travllingSalesmanProblem(graph, s) << endl;
 return 0;
}