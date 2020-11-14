#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char* argv[]) {

  long long n;

  cin >> n;

  long long i = 1;
  long long tenCount = 0;
  long long fiveCount = 0;
  long long twoCount = 0;
  
  while (i <= n) {
    if (i % 10 == 0) {
      tenCount++;
    } else if (i % 5 == 0) {
      fiveCount++;
    } else if (i % 2 == 0) {
      twoCount++;
    }

    i++;
  }

  long long result = tenCount + (long long) min(fiveCount, twoCount);

  cout << result << endl;

}
