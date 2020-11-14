#include <iostream>
#include <map>
#include <vector>
#include <cmath>
 
typedef long long ll;
 
using namespace std;
 
int main(int argc, char* argv[]) {
 
    ll n = 0;
    ll result = 0;
    ll i = 0, j = 0;
    ll e = 0;
    
    cin >> n;
    vector<ll> songs;
    map<ll,bool> freq;

    while (i < n) {
      cin >> e;
      songs.push_back(e);
      i++;
    }


    for (i = 0, j = 0 ; i < n ; i++) {
      while (j < n && !freq[songs[j]]) {
	freq[songs[j]] = true;
	j++;
      }
      result = max(result, j - i);
      freq[songs[i]] = false;
    }
   
    cout << result << endl;
}
