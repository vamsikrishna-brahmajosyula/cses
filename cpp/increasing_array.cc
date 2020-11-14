#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
  long long prev;
  long long n;
  long long count = 0;
  cin >> n;

  cin >> prev;

  for (int i = 1; i < n; i++) {
    long long curr;

    cin >> curr;

    if (curr < prev) {

      long long diff = prev - curr;

      count = count + diff;
      
      curr = curr + diff;
      
    }

    prev = curr;

  }



  cout << count;

  return 0;

}
