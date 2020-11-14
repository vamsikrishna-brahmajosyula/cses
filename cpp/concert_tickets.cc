#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

int main(int argc, char* argv[]) {
  ll n, m;

  cin >> n >> m;

  multiset<ll, greater<ll>> tickets;

  ll i = 0;
  ll e = 0;
  while (i < n) {
    cin >> e;
    tickets.insert(e);
    i++;
  }

  i = 0;
  
  while(i < m) {
    cin >> e;
    multiset<ll>::iterator itr = tickets.lower_bound(e);

    if (itr == tickets.end()) {
      cout << -1 << endl;
    } else {
      cout << *itr << endl;
      tickets.erase(itr);
    }
    
    i++;
  }

  return 0;
}
