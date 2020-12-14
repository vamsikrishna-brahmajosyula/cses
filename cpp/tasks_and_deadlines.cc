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

    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        tasks[i] = make_pair(a, b);
    }

    sort(tasks.begin(), tasks.end());

    long end_time = 0;
    long reward = 0;

    for (int i = 0; i < n; i++)
    {
        end_time += tasks[i].first;
        reward += (tasks[i].second - end_time);
    }

    cout << reward << endl;
}