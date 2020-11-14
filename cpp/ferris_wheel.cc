#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc, char* argv[]) {

  ll n, x;
  ll result;
  cin >> n >> x;

  vector<ll> weights;

  ll i = 0;
  ll w = 0;
  
  while (i < n) {
    cin >> w;
    weights.push_back(w);
    i++;
  }

  sort(weights.begin(), weights.end());

  vector<ll>::iterator left = weights.begin();
  vector<ll>::iterator right = weights.end() - 1;
  
  result = 0;
  while (left <= right) {
    if (*right + *left > x) {
      right--;
    } else {
      left++;
      right--;
    }

    result++;
  }

  cout << result;

  return 0;

}
