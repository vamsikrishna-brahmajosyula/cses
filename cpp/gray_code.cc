#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{

    int n;

    cin >> n;

    vector<string> vec(pow(2, n), "");

    for (int outer = 1; outer <= n; outer++)
    {

        if (outer == 1)
        {
            vec[0] = "0";
            vec[1] = "1";
        }
        else
        {

            int dec = pow(2, (outer - 1)) - 1;
            int inc = dec + 1;

            while (dec >= 0)
            {
                vec[inc] = vec[dec];
                inc++;
                dec--;
            }

            for (int start = 0; start < inc; start++)
            {
                if (start < inc / 2)
                {
                    vec[start] = "0" + vec[start];
                }
                else
                {
                    vec[start] = "1" + vec[start];
                }
            }
        }
    }

    for (auto &element : vec)
    {
        cout << element << endl;
    }
}
