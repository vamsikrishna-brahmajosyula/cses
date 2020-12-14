#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

int main(int argc, char *argv[])
{

  ll t;
  long n;

  cin >> n >> t;
  ll time;

  vector<ll> k(n);

  for (long i = 0; i < n; i++)
  {
    cin >> time;
    k[i]= time;
  }

  ll min_time = 0;

  ll start = 0;
  ll end = 1e18;

  while (start <= end) {
    ll mid = (start + end) / 2;

    ll sum = 0;

    for (ll i = 0; i < n; i++) {
      sum += (mid / k[i]);
      if (sum >= t) {
        break;
      }
    }

    if (sum >= t) {
      min_time = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  cout << min_time << endl;
  return 0;
}