#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // Size of the maze
int maze[N][N] = {
    {1, 0, 0, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1}
};

// Directions for moving in the maze (up, right, down, left)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Function to check if a cell is inside the maze and is open (i.e., a 0)
bool isSafe(int x, int y, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && !visited[x][y]);
}

// Function to solve the maze using DFS
bool solveMaze(int x, int y, vector<vector<bool>>& visited) {
    // Base case: If we reached the bottom-right corner
    if (x == N-1 && y == N-1) {
        visited[x][y] = true;
        return true;
    }

    // Mark this cell as visited
    visited[x][y] = true;

    // Try all 4 directions
    for (int dir = 0; dir < 4; ++dir) {
        int newX = x + dx[dir];
        int newY = y + dy[dir];

        // If moving in this direction is safe, explore it
        if (isSafe(newX, newY, visited) && solveMaze(newX, newY, visited)) {
            return true;  // If we found a solution
        }
    }

    // If no move is possible, backtrack
    visited[x][y] = false;
    return false;
}

// Function to print the solution path
void printSolution(vector<vector<bool>>& visited) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) {
                cout << "1 "; // Part of the solution path
            } else {
                cout << "0 "; // Not part of the solution
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    // Start solving from the top-left corner (0, 0)
    if (solveMaze(0, 0, visited)) {
        cout << "Solution path:\n";
        printSolution(visited);
    } else {
        cout << "No solution found.\n";
    }

    return 0;
}
