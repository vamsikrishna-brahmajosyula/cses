#include <vector>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
    long long globalMax = 0;
    long long localMax = 1;

    string str;

    getline(cin, str);


    char prev = str[0];
    
    for (int i = 1; i < str.size(); i++){
      char c = str[i];
      if (c == prev) {
	localMax++;
      } else {
	globalMax = max(localMax, globalMax);
	localMax = 1;
      }

      prev = c;
    }

    globalMax = max(localMax, globalMax);
    cout << globalMax << endl;
    return 0;
}
