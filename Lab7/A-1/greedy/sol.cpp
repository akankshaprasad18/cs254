#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB; // Sort in non-increasing order of value-to-weight ratio
}

int greedyKnapsack(vector<Item>& items, int limit) {
    sort(items.begin(), items.end(), compare);

    int totalWeight = 0;
    int totalValue = 0;

    for (Item item : items) {
        if (totalWeight + item.weight <= limit) {
            totalWeight += item.weight;
            totalValue += item.value;
        } else {
            break; // Stop if adding this item exceeds the weight limit
        }
    }

    return totalValue;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile || !outfile) {
        cerr << "Error: Unable to open input or output file!" << endl;
        return 1;
    }

    int numItems, limit;
    infile >> numItems >> limit;

    vector<Item> items(numItems);
    for (int i = 0; i < numItems; ++i) {
        infile >> items[i].weight >> items[i].value;
    }

    int maxValue = greedyKnapsack(items, limit);

    outfile << "Maximum value that can be taken: " << maxValue << endl;

    infile.close();
    outfile.close();

    return 0;
}
