#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n;
  set<long long> tracker;
  long long element;

  cin >> n;

  int i = 0;

  while (i < n) {
    cin >> element; 
    tracker.insert(element);
    i++;
  }

  cout << tracker.size() << "\n";
  return 0;
}
