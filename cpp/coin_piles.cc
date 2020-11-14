#include <iostream>

typedef long long ll;

using namespace std;

void solve(ll a, ll b);

int main(int argc, char* argv[]) {

  ll t;
  ll a;
  ll b;
  cin >> t;

  for (ll i = 0; i < t; i++) {
    cin >> a >> b;
    solve(a, b);
  }

}

void solve(ll a, ll b) {
  ll q = 0;
  if ((a + b) % 3 == 0) {
    q = (a + b) / 3;
    if (a - q >= 0 && b - q >= 0) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}
