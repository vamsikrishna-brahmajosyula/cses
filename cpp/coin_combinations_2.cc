#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

  int n;
  int x;

  cin >> n >> x;

  vector<int> coins;

  int dp[n+1][x+1];

  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    coins.push_back(c);
  }
  

  // dp[i][c] = dp[i-1][c] + dp[i][c-ci]

  cout << dp[n][x];
  return 0;
}
