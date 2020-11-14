#include <bits/stdc++.h>
#include <iostream>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

string format(int x, int y)
{
	stringstream ss;
	ss << x << "_" << y;
	return ss.str();
}

#define VALID(x, y, n, m)                             \
	((x >= 0 && x < n) && (y >= 0 && y < m) &&        \
	 building[x][y] != '#' && path[x][y] == 'N' && \
	 !queued[x][y])

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	pair<int, int> start, end;
	queue<tuple<int, int, char>> items;
	char building[1000][1000];
	char path[1000][1000];
	bool queued[1000][1000];

	char c;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			building[i][j] = c;
			path[i][j] = 'N';
			queued[i][j] = false;
			if (c == 'A')
			{
				start = make_pair(i, j);
			}
			else if (c == 'B')
			{
				end = make_pair(i, j);
			}
		}
	}

	items.push(make_tuple(start.first, start.second, 'A'));

	while (!items.empty())
	{

		tuple<int, int, char> pos = items.front();
		items.pop();

		int first = get<0>(pos);
		int second = get<1>(pos);
		char third = get<2>(pos);

		int x, y;

		// check if the pos is end
		if (first == end.first && second == end.second)
		{
			cout << "YES" << endl;
			// backtrack and print answer
			stringstream ss;

			c = third;
			x = first;
			y = second;
			while (c != 'A')
			{
				ss << c;
				switch (c)
				{
				case 'L':
					y = y + 1;
					break;
				case 'R':
					y = y - 1;
					break;
				case 'U':
					x = x + 1;
					break;
				case 'D':
					x = x - 1;
					break;
				default:
					break;
				}

				c = path[x][y];
			}

			string response = ss.str();
			reverse(response.begin(), response.end());
			cout << response.length() << endl;
			cout << response << endl;
			return 0;
		}

		// top
		x = first;
		y = second + 1;
		if (VALID(x, y, n, m))
		{
			items.push(make_tuple(x, y, 'R'));
			queued[x][y] = true;
		}
		// down
		x = first;
		y = second - 1;
		if (VALID(x, y, n, m))
		{
			items.push(make_tuple(x, y, 'L'));
			queued[x][y] = true;
		}
		// left
		x = first - 1;
		y = second;
		if (VALID(x, y, n, m))
		{
			items.push(make_tuple(x, y, 'U'));
			queued[x][y] = true;
		}
		// right
		x = first + 1;
		y = second;
		if (VALID(x, y, n, m))
		{
			items.push(make_tuple(x, y, 'D'));
			queued[x][y] = true;
		}
		path[first][second] = third;
	}

	cout << "NO" << endl;

	return 0;
}