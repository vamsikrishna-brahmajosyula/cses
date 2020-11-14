#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

  long n,m;
  map<long, vector<long>> computers;
  
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    long a, b;
    cin >> a >> b;
    computers[a].push_back(b);
    computers[b].push_back(a);
  }
  
  vector<bool> visited(n + 1, false);
  vector<bool> queued(n + 1, false);
  
  vector<long> path(n+1, 0);
  queue<long> q;

  // start here
  q.push(1);
  path[1] = 0;

  while(!q.empty()) {

    long computerId = q.front();
    q.pop();

    visited[computerId] = true;

    if (computerId == n) {
      // found , so back track
      list<long> result;
      long nav = computerId;
      long count = 0;
      while(nav != 0) {
	result.push_front(nav);
	nav = path[nav];
	count++;
      }

      cout << count << endl;
      for (auto id: result) {
	cout << id << " ";
      }

      return 0;
    }

    vector<long> connections = computers[computerId];

    for (auto connection: connections) {
      if (!visited[connection] && !queued[connection]) {
	path[connection] = computerId;
	queued[connection] = true;
	q.push(connection);
      }
    }
  }


  cout << "IMPOSSIBLE" << endl;

  return 0;
}
