#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;   
    int dead;
    int profit;
};

class Solution {
public:
    static bool comparison(Job a, Job b) {
        return (a.profit > b.profit);
    }

    pair<int, int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comparison);

        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }

        int slot[maxi + 1];
        fill_n(slot, maxi + 1, -1);

        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }

        return make_pair(countJobs, jobProfit);
    }
};

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile || !outfile) {
        cerr << "Error: Unable to open input or output file!" << endl;
        return 1;
    }

    int n;
    infile >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        infile >> jobs[i].id >> jobs[i].dead >> jobs[i].profit;
    }

    Solution ob;
    pair<int, int> ans = ob.JobScheduling(jobs.data(), n);
    outfile << ans.first << " " << ans.second << endl;

    infile.close();
    outfile.close();

    return 0;
}
