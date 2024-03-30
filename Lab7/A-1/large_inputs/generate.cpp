#include <iostream>
#include <fstream>
#include <random>
using namespace std;

void generateInputFile(string filename, int numItems, int maxWeight) {
    ofstream outfile(filename);

    if (!outfile) {
        cerr << "Error: Unable to open output file!" << endl;
        return;
    }

    // Write number of items and maximum weight at the top of the file
    outfile << numItems << " " << maxWeight << endl;

    // Random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> wt_dist(1, 100);  // Weight range: 1 to 100
    uniform_int_distribution<int> val_dist(1, 50);  // Value range: 1 to 50

    // Generate and write weights and values
    for (int i = 0; i < numItems; ++i) {
        int weight = wt_dist(gen);
        int value = val_dist(gen);
        outfile << weight << " " << value << endl;
    }

    outfile.close();
    cout << "Input file generated successfully: " << filename << endl;
}

int main() {
    int numItems = 1000;
    int maxWeight = 10000;
    generateInputFile("input.txt", numItems, maxWeight);
    return 0;
}
