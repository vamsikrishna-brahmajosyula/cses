#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
    long long n;

    cin >> n;

    long long i = n - 1;

    long long sum = (n * (n + 1)) / 2;

    long long num = 0;

    while(i > 0) {
      cin >> num;
      sum = sum - num;
      i--;
    }

    cout << sum << endl;
    return 0;
}
