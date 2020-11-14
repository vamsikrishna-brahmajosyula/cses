#include <iostream>

using namespace std;

int count = 0;
void search(int y);

const int n = 4;

bool col[n];
bool diag1[n];
bool diag2[n];

int main(int argc, char* argv[]) {

    search(0);

    cout << count << endl;
}


void search(int y)
{
    if (y == n)
    {
        count++;
        return;
    }
    for (int x = 0; x < n; x++)
    {
        if (col[x] || diag1[x + y] || diag2[x - y + n - 1])
            continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}