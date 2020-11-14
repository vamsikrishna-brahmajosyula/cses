#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc, char* argv[]) {

  ll n, m, k;
  ll result;
  vector<ll> a;
  vector<ll> b;

  ll element;
  ll i;

  cin >> n >> m >> k;
  
  for (i = 0; i < n; i++) { 
    cin >> element;
    a.push_back(element);
  }


  for (i = 0; i < m; i++) { 
    cin >> element;
    b.push_back(element);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());


  vector<ll>::iterator aiter = a.begin();
  vector<ll>::iterator biter = b.begin();
  result = 0;

  while (aiter != a.end() && biter != b.end()) {
    ll applicant = *aiter;
    ll house = *biter;

    if ( applicant - k <= house && house <= applicant + k) {
      aiter++;
      biter++;
      result++;
    } else if (house < applicant) {
      biter++;
    } else {
      aiter++;
    }
  }

  cout << result << endl;
  return 0;
}
