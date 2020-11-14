#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>

#define VALID(x, y, n, m) ((x >= 0 && x < n) && (y >= 0 && y < m) && building[x][y] == '.' && !visited[x][y])

using namespace std;

char building[1000][1000];
bool visited[1000][1000];

void traverse_room(int x, int y, int n, int m);

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	char c;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			building[i][j] = c;
			visited[i][j] = false;
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && building[i][j] == '.')
			{
				traverse_room(i, j, n, m);
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}

void traverse_room(int x, int y, int n, int m)
{
	visited[x][y] = true;
	// go left
	if (VALID(x - 1, y, n, m))
		traverse_room(x - 1, y, n, m);
	// go right
	if (VALID(x + 1, y, n, m))
		traverse_room(x + 1, y, n, m);
	// go up
	if (VALID(x, y - 1, n, m))
		traverse_room(x, y - 1, n, m);
	// go down
	if (VALID(x, y + 1, n, m))
		traverse_room(x, y + 1, n, m);
}