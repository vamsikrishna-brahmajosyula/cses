#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {

  multiset<ll> tops;

  ll i = 0;
  ll n = 0;
  ll e = 0;
  multiset<ll>::iterator itr;
  cin >> n;

  while (i < n) {
    cin >> e;
    itr = tops.upper_bound(e);

    if (itr == tops.end()) {
      tops.insert(e);
    } else {
      tops.erase(itr);
      tops.insert(e);
    }
    
    i++;
  }

  cout << tops.size() << endl;
  return 0;
}
