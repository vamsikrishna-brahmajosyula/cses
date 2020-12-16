#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long sum = 0;
    long max = 0;

    for (int i = 0; i < n; i++)
    {
        long book;
        cin >> book;
        if (max < book)
        {
            max = book;
        }
        sum = sum + book;
    }

    if (max > sum - max)
    {
        cout <<  2 * max;
    }
    else
    {
        cout << sum;
    }

    return 0;
}