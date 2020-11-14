#include <iostream>
#include <vector>
#include <cmath>
#include <limits>


using namespace std;

int main(int argc, char* argv[]) {

    int n, x;

    int intmax = numeric_limits<int>::max();

    cin >> n >> x;

    vector<int> coins(n, 0);

    vector<int> cache(x + 1);

    cache[0] = 0;

    int coin;

    for (int i = 0; i < n; i++) {
        cin >> coin;
        coins[i] = coin;
    }

    for (int k = 1; k <= x; k++) {
        cache[k] = intmax;
        
        for (auto c : coins) {
            if (k - c >= 0 && cache[k -c] != intmax) {
                cache[k] = min(cache[k], 1 + cache[k - c]);
            }
        }
    }
    
    if (cache[x] == intmax) {
        cout << -1 << endl;
    } else {
        cout << cache[x] << endl;
    }
}