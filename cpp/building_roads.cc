#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

void build_roads(ll n, ll m, map<ll, vector<ll>>& cities, vector<ll> &groups);
void traverse(ll i, bool *visited, map<ll, vector<ll>>& cities);

int main(int argc, char *argv[])
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;

  cin >> n >> m;
  map<ll, vector<ll>> cities;
  vector<ll> groups;

  ll from, to;

  for (ll i = 0; i < m; i++)
  {
    cin >> from >> to;
    cities[from].push_back(to);
    cities[to].push_back(from);
  }

  build_roads(n, m, cities, groups);
}

void build_roads(ll n, ll m, map<ll, vector<ll>> &cities, vector<ll> &groups)
{
  bool *visited = new bool[n + 1];
  for (ll i = 1; i <= n; i++)
  {
    visited[i] = false;
  }
  for (ll i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      traverse(i, visited, cities);
      groups.push_back(i);
    }
  }

  cout << groups.size() - 1 << endl;
  ll prevGroup = 0;
  for (auto groupId : groups)
  {
    if (prevGroup != 0)
    {
      cout << prevGroup << " " << groupId << endl;
    }

    prevGroup = groupId;
  }
  delete[] visited;
}

void traverse(ll i, bool *visited, map<ll, vector<ll>> &cities)
{
  if (cities.find(i) == cities.end())
  {
    return;
  }
  else
  {
    vector<ll> city = cities[i];
    visited[i] = true;
    for (auto connectedCity : city)
    {
      if (!visited[connectedCity])
        traverse(connectedCity, visited, cities);
    }
  }
}