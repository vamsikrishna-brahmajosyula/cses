#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

  long long n;

  cin >> n;

  long long sum = (n * (n + 1)) / 2;
  
  if (sum % 2 == 0) {
    cout << "YES" << endl;

    unordered_set <long long> firstGroup;
    unordered_set <long long> secondGroup ;

    long long begin = n;

    long long halfSum = sum / 2;
    
    while (begin > 0) {
      if (begin <= halfSum) {
	firstGroup.insert(begin);
	halfSum = halfSum - begin;
      } else {
	secondGroup.insert(begin);
      }
      begin--;
    }

   

    unordered_set<long long> :: iterator itr;

    cout << firstGroup.size() << endl;
    
    for (itr = firstGroup.begin(); itr != firstGroup.end(); itr++)
      cout << (*itr) << " ";

    cout << endl;
    
    cout << secondGroup.size() << endl;

    for (itr = secondGroup.begin(); itr != secondGroup.end(); itr++)
      cout << (*itr) << " ";

    cout << endl;
   
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
