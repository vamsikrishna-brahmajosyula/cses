#include <bits/stdc++.h>
#include <iostream>
#include <tuple>
#include <queue>

#define VALID(x, y, n, m) ((x >= 0 && x < n) && (y >= 0 && y < m) && building[x][y] != '#' && !visited[x][y])

using namespace std;

char building[1000][1000];
bool visited[1000][1000];
bool found = false;
string shortPath = "";
void traverse_room(int x, int y, int tX, int tY, int n, int m, string path);
int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	int startX, startY, endX, endY;

	char c;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			building[i][j] = c;
			visited[i][j] = false;
			if (c == 'A')
			{
				startX = i;
				startY = j;
			}
			else if (c == 'B')
			{
				endX = i;
				endY = j;
			}
		}
	}

	traverse_room(startX, startY, endX, endY, n, m, "");

	if (!found)
	{
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		cout << shortPath.length() << endl;
		cout << shortPath << endl;
	}

	return 0;
}

void traverse_room(int x, int y, int tX, int tY, int n, int m, string path)
{
	if (x == tX && y == tY)
	{
		if (shortPath == "" || shortPath.length() > path.length()) {
			shortPath = path;
			found = true;
		}
		
		return;
	}

	visited[x][y] = true;

	if (shortPath != "" && path.length() >= shortPath.length()) {
		return;
	}
	
	// go UP
	if (VALID(x - 1, y, n, m))
		traverse_room(x - 1, y, tX, tY, n, m, path + 'U');
	// go DOWN
	if (VALID(x + 1, y, n, m))
		traverse_room(x + 1, y, tX, tY, n, m, path + 'D');
	// go LEFT
	if (VALID(x, y - 1, n, m))
		traverse_room(x, y - 1, tX, tY, n, m, path + 'L');
	// go RIGHT
	if (VALID(x, y + 1, n, m))
		traverse_room(x, y + 1, tX, tY, n, m, path + 'R');
}