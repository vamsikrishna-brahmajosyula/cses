#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{

  int n;

  cin >> n;

  vector<tuple<long, long, long>> customers;

  vector<long> alloted_rooms(n);

  long last_alloted_room = 0;

  priority_queue<pair<long, long>> pq;

  for (int i = 0; i < n; i++)
  {
    long a, b;

    cin >> a >> b;

    customers.push_back(make_tuple(a, b, i));
  }

  sort(customers.begin(), customers.end());

  for (auto customer : customers)
  {
    long pos = get<2>(customer);
    long start = get<0>(customer);
    long end = get<1>(customer);
    long alloted_room = -1;

    if (!pq.empty())
    {
      pair<long, long> availableRoom = pq.top();
      if (-1 * availableRoom.first < start)
      {
        alloted_room = availableRoom.second;
        pq.pop();
      }
    }

    if (alloted_room == -1)
    {
      alloted_room = ++last_alloted_room;
    }

    pq.push(make_pair(-end, alloted_room));
    alloted_rooms[pos] = alloted_room;
  }

  cout << last_alloted_room << endl;

  for (int i = 0; i < n; i++)
  {
    cout << alloted_rooms[i] << " ";
  }

  return 0;
}
