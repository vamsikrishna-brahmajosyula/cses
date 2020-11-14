#include <iostream>
#include <map>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

int main(int argc, char * argv[]) {

  string str;
  
  map<char, ll> freq;
  priority_queue<pair<ll, char> > pq;
  getline(cin, str);

  for (char & c : str) {
    freq[c]++;
  }

  ll odd_count = 0;
  for (pair<char, ll> p: freq) {
    pq.push(make_pair(p.second, p.first));
    if (p.second % 2 == 1) {
      odd_count++;
    }
  }

  ll n = str.length();

  if (n % 2 == 1) { 
     if (odd_count > 1) {
      cout << "NO SOLUTION" << endl;
      return 0;
    }
  } else {
    if (odd_count > 0) {
      cout << "NO SOLUTION" << endl;
      return 0;
    }
  }

  vector<char> chars(str.length());
  
  ll i, j;
  
  i = 0;
  j = str.length() - 1;
  
  while (pq.size() > 0) {
    pair<ll, char> p = pq.top();
    char c = p.second;
    ll count = p.first;
    
    if (i == j && count == 1) {
      chars[i] = c;
      count = 0;
    }

    while (count >= 2) {
      chars[i] = c;
      chars[j] = c;
      count -= 2;
      i++;
      j--;
    }
    pq.pop();

    if (count == 1) {
      pq.push(make_pair(1, c));
    }
    
  }

  for (auto c : chars) {
    cout << c;
  }

  cout << endl;  
  return 0;
}
