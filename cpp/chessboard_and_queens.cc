#include <iostream>

using namespace std;

int count = 0;
const int n = 4;
char board[n][n];


bool isValid(int row, int col) {

  int i, j; 
  
  /* Check this row on left side */
  for (i = 0; i < col; i++) 
      if (board[row][i] == 'q') 
          return false; 

  /* Check upper diagonal on left side */
  for (i=row, j=col; i>=0 && j>=0; i--, j--) 
      if (board[i][j] == 'q') 
          return false; 

  /* Check lower diagonal on left side */
  for (i=row, j=col; j>=0 && i< n; i++, j--) 
      if (board[i][j] == 'q') 
          return false; 

  return true;
}

void solve(int i) {
  if (i == n) {
    count++;
    return;
  }

  for (int j = 0; j < n; j++) {
    if (board[i][j] != '*' && isValid(i, j)) {
      board[i][j] = 'q';
	    solve(i+1);
      board[i][j] = '.';
    }
  }

}

int main(int argc, char* argv[]) {
    string line;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        for (int j = 0; j < n; j++) {
            board[i][j] = line[j];
        }
    }
    solve(0);
    cout << count << endl;
    return 0;
}
