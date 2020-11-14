#include <iostream>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int main(int argc, char* argv[]) {

  ll n;

  set<pair<ll, int>> times;

  cin >> n;

  ll i = 0;
  ll s;
  ll e;
  
  while (i < n) {
    cin >> s >> e;
    times.insert(make_pair(s, 1));
    times.insert(make_pair(e, -1));
    i++;
  }

  ll ans = 0;
  ll count = 0;

  for (auto currPair : times) {
    count += currPair.second;
    ans = max(count, ans);
  }


  cout << ans << endl;
}
