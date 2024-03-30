#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = val[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = dp[ind - 1][cap];
            int taken = INT_MIN;
            if (wt[ind] <= cap) {
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];
            }
            dp[ind][cap] = max(notTaken, taken);
        }
    }

    return dp[n - 1][W];
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
