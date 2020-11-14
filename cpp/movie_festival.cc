#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;

using namespace std;

bool sortinrev(const pair<ll,ll> &a,  
               const pair<ll,ll> &b) { 
       return (a.first > b.first); 
} 

int main(int argc, char* argv[]) {

  ll n;

  cin >> n;

  ll i = 0;
  ll start = 0;
  ll end = 0;

  vector<pair<ll, ll>> times; 
  
  while(i < n) {
    cin >> start;
    cin >> end;
    times.push_back(make_pair(end, start));
    i++;
  }

  sort(times.begin(), times.end());

  ll result = 0;
  ll curr_end = 0;

  for (auto ele : times) {
    if (ele.second >= curr_end) {
      curr_end = ele.first;
      result++;
    }
  }

  
  cout << result << endl;
}
