#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(int argc, char* argv[]) {

ll n;

cin >> n;

for (ll k = 1; k <=n; k++) {

	cout << ((k*k) * (k*k - 1) / 2) - 4 * (k -1) * (k - 2) << endl;
}

return 0;
}
