#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

void combinations(ll n)
{

  const unsigned int M = 1000000007;
  
  vector<ll> cache(n + 1, 0);

  cache[0] = 1;

  for (ll i = 1; i <= n; i++)
  {

    ll count = 0;

    for (ll k = 1; k <= 6; k++)
    {
      if (i - k >= 0)
      {
        count = (count + cache[i - k]) % M;
      }
    }

    cache[i] = count;
  }

  cout << cache[n] << endl;
}

int main(int argc, char *argv[])
{

  ll n;

  cin >> n;

  combinations(n);
}
