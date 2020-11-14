#include <iostream>


using namespace std;

int main(int argc, const char* argv[])
{
    long long n;

    cin >> n;

    if (n == 1) {
      cout << 1;
      return 0;
    }

    
    
    if (n <= 3) {
      cout << "NO SOLUTION" << endl;
    } else {

      long long i = 2;
      
      while (i <= n) {
	cout << i << " ";
	i = i + 2;
      }


      i = 1;
      while (i <= n) {
	cout << i << " ";
	i = i + 2;
      }
     
    }

    cout << endl;
    return 0;
}
