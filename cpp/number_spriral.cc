#include <iostream>

using namespace std;

void solve();

int main(int argc, char* argv[]) {

  long long t;

  cin >> t;

  long long i = 0;
  
  for (i = 0; i < t; i++) {
    solve();
  }
}

void solve() {

  long long y, x;

  cin >> y;
  cin >> x;

  long long ans;
  
  if (y > x) {
    if (y % 2 == 0) {
      ans = y*y - x + 1;
    } else {
      ans = (y - 1) * (y - 1) + x;
    }
  } else {
    if (x % 2 == 0) {
      ans = ((x - 1) * (x - 1)) + y;
    } else {
      ans = x*x - y + 1;
    }
  }

  cout << ans << endl;

}
