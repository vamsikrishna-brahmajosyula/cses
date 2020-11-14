#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;



int main(int argc, char* argv[]) {

    vector<ll> sticks;

    ll i = 0;

    ll n = 0;

    cin >> n;

    ll e = 0;
    
    while(i < n) {
        cin >> e;
        sticks.push_back(e);
        i++;
    }

    sort(sticks.begin(), sticks.end());

    ll median = n % 2 == 0 ? (sticks[n/2 - 1] + sticks[n/2]) / 2 : sticks[n/2];
    
    ll ans = 0;

    for (auto stick : sticks) {
        ans += abs(stick - median);
    }

    cout << ans << endl;
}

