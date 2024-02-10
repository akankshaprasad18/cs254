
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct queueEntry {
    int v;
    int dist;
};

int getMinDiceThrows(int move[], int N) {
    bool* visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    queue<queueEntry> q;
    visited[0] = true;
    queueEntry s = {0, 0}; 
    q.push(s); 

    queueEntry qe;
    while (!q.empty()) {
        qe = q.front();
        int v = qe.v;

        if (v == N - 1)
            break;

        q.pop();
        for (int j = v + 1; j <= (v + 6) && j < N; ++j) {
            if (!visited[j]) {
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;

                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }

    return qe.dist;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int N;
    infile >> N;
    int moves[N];
    for (int i = 0; i < N; i++)
        moves[i] = -1;

    int ladderStart, ladderEnd;
    while (infile >> ladderStart >> ladderEnd) {
        moves[ladderStart - 1] = ladderEnd - 1;
    }

    int minThrows = getMinDiceThrows(moves, N);
    outfile << "Min Dice throws required is " << minThrows;

    infile.close();
    outfile.close();
    return 0;
}
