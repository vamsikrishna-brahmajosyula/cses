#include <iostream>

using namespace std;

int count = 0;

bool visited[7][7];

void solve(string line, int move, int row, int col) {
    
    if (row == 0 && col == 0) {
        count ++;
        return;
    }

    if (row < 0 || row > 6) {
        return;
    }

    if (col < 0 || col > 6) {
        return;
    }

    if (move > 48) {
        return;
    }

    if (visited[row][col]) {
        return;
    }

    visited[row][col] = true;

    cout << "Row: " << row << " Col: " << col << " Move: "<< move << " Count: " << count << endl;

    char c = line[move];

    if (c == 'U' || c == '?') {
        solve(line, move + 1, row - 1, col);
    }

    if (c == 'D' || c == '?') {
        solve(line, move + 1, row + 1, col);
    }

    if (c == 'R' || c == '?') {
        solve(line, move + 1, row, col + 1);
    }

    if (c == 'L' || c == '?') {
        solve(line, move + 1, row, col - 1);
    }

    visited[row][col] = false;
}

int main(int argc, char* argv[]) {

    string line;
    getline(cin, line);
    
    solve(line, 1, 6, 0);    
    
    cout << count << endl;
}