#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[])
{

  int n;

  cin >> n;

  ll total_count = 0;

  vector<ll> items;

  int i = 0;

  while (i < n)
  {
    ll e;
    cin >> e;
    items.push_back(e);
    total_count += e;
    i++;
  }

  ll min_diff = numeric_limits<ll>::max();
  
  ll local_count = 0;
  for (int i = 0; i < (int) pow(2, n); i++)
  {
    local_count = 0;
    for (int k = 0; k < n; k++)
    {
      if (i & (1 << k) != 0)
      {
        local_count += items[k];
      }
    }
    min_diff = min(min_diff, abs(total_count - 2 * local_count));
  }

  cout << min_diff << endl;

  return 0;
}
