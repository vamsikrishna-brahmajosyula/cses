#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

  int n;
  int x;

  cin >> n >> x;

  vector<int> coins;

  vector<int> cache(x+1, 0);

  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    coins.push_back(c);
  }
  cache[0] = 1;

  for (int i = 1; i <= x; i++) {
    int ways = 0;
    for (auto c : coins) {
      if (i - c >= 0) {
	ways = (ways + cache[i- c]) % 1000000007;
      }
    }

    cache[i] = ways;
  }

  cout << cache[x];
  return 0;
}
