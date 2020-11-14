#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {

  long long n;

  cin >> n;

  unsigned long denom = 1000000007;

  long long result = 1;

  for (long long i = 1; i <= n; i++) {
    result = (result * 2) % denom;
  }

  cout << result << endl;
}
