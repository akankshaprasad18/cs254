#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

// Function to generate random job data
void generateJobData(const string& filename, int numJobs) {
    ofstream outfile(filename);

    if (!outfile) {
        cerr << "Error: Unable to open output file!" << endl;
        return;
    }

    // Seed for random number generation
    srand(time(0));

    outfile << numJobs << endl; // Writing the number of jobs to the file

    for (int i = 0; i < numJobs; ++i) {
        // Generating random job data
        int id = i + 1;
        int dead = rand() % 20 + 1; // Deadline between 1 and 20
        int profit = rand() % 100 + 1; // Profit between 1 and 100

        // Writing job data to the file
        outfile << id << " " << dead << " " << profit << endl;
    }

    outfile.close();
    cout << "Input file generated successfully: " << filename << endl;
}

int main() {
    const string filename = "input.txt";
    int numJobs = 1000;
    generateJobData(filename, numJobs);
    return 0;
}
