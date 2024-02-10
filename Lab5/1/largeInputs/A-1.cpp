#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
#include <cstring>
using namespace std;

#define ROW 100
#define COL 100


int isSafe(int M[][COL], int row, int col, bool visited[][COL]) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}


void DFS(int M[][COL], int row, int col, bool visited[][COL], int& count) {
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    visited[row][col] = true;
    for (int k = 0; k < 8; ++k) {
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited)) {
            count++;
            DFS(M, row + rowNbr[k], col + colNbr[k], visited, count);
        }
    }
}


int largestRegion(int M[][COL]) {
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    int result = INT_MIN;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (M[i][j] && !visited[i][j]) {
                int count = 1;
                DFS(M, i, j, visited, count);
                result = max(result, count);
            }
        }
    }
    return result;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    
    int M[ROW][COL];
    
    
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            infile >> M[i][j];
        }
    }
    
   
    int largest = largestRegion(M);
    
   
    outfile << "Largest region length: " << largest << endl;
    
    infile.close();
    outfile.close();
    
    return 0;
}
