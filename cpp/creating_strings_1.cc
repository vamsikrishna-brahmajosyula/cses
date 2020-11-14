#include <iostream>
#include <set>

using namespace std;

set<string> strings;

void build_strings(string prefix, string left, size_t n);

int main(int argc, char* argv[]) {

  string s;

  getline(cin, s);

  build_strings("", s, s.size());

  cout << strings.size() << endl;

  for (auto str : strings) {
    cout << str << endl;
  }
}

void build_strings(string prefix, string left, size_t n) {

  if (prefix.length() == n) {
    strings.insert(prefix);
    return;
  }

  for (string::size_type i = 0; i < left.size(); i++) {
    char c = left[i];
    string upto_i = ""; 
    if (i > 0) {
      upto_i = left.substr(0, i);
    }
    string after_i = "";

    if (i < left.size() - 1) {
     after_i = left.substr(i + 1, left.size() - i);
    }

    build_strings(prefix + c, upto_i + after_i, n);
  }
}


