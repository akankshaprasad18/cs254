#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
     vector<int> prev(W+1,0);
       for(int i=0;i<=W;i++){
           if(wt[0]<=i){
               prev[i]=val[0];
           }
           else{
               prev[i]=0;
           }
       }
       for(int i=1;i<n;i++){
           for(int j=W;j>=0;j--){
               int nottake=prev[j];
        int take=INT_MIN;
        if(wt[i]<=j){
        take=val[i]+prev[j-wt[i]];
        }
         prev[j]=max(take,nottake);
           }
          
       }
       
       return prev[W];

}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile || !outfile) {
        cerr << "Error: Unable to open input or output file!" << endl;
        return 1;
    }

    int n, W;
    infile >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) {
        infile >> wt[i] >> val[i];
    }

    int maxVal = knapsack(wt, val, n, W);

    outfile << "The Maximum value of items the thief can steal is " << maxVal << endl;

    infile.close();
    outfile.close();

    return 0;
}
