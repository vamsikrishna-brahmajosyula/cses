#include <iostream>

using namespace std;

int count = 0;
bool reserved[8][8];
bool cols[16], diag1[16], diag2[16];

void solve(int i) {
  if (i == 8) {
    count++;
    return;
  }

  for (int j = 0; j < 8; j++) {
    if (cols[j] || diag1[i+j] || diag2[i-j+7] || reserved[i][j])
      continue;
    cols[j] = diag1[i+j] = diag2[i-j+7] = true;
    solve(i+1);
    cols[j] = diag1[i+j] = diag2[i-j+7] = false;
  }

}

int main(int argc, char* argv[]) {
    char x;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> x;
            if (x == '*') {
              reserved[i][j] = true;
            } else {
              reserved[i][j] = false;
            }
        }
    }
    count = 0;
    solve(0);
    cout << count << endl;
    return 0;
}
