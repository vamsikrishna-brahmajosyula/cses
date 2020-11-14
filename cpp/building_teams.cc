#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    long noOfPupils;
    map<long, vector<long>> pupils;

    Graph(long n, map<long, vector<long>> p) {
        noOfPupils = n;
        pupils = p;
    }

    void buildTeams();
};


void Graph::buildTeams() {

    vector<long> colors(noOfPupils + 1, 0);
    queue<long> q;

    for (long i = 1; i <= noOfPupils; i++) {
        if (colors[i] == 0) {
            colors[i] = 1;
        }
        
        q.push(i);

        while (!q.empty()) {
            long student = q.front();
            q.pop();
            long color = colors[student];
            long friendColor = color == 1 ? 2 : 1;

            for (auto f: pupils[student]) {
                if (colors[f] == color) {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                } else if (colors[f] == 0) {
                    colors[f] = friendColor;
                    q.push(f);
                }

            }

        }

    }


    for (long i = 1; i <= noOfPupils; i++) {
        long color = colors[i];

        if (color == 0 || color == 1) {
            cout << 1;
        } else {
            cout << 2;
        }

	if (i != noOfPupils) {
            cout << " ";
	}

    }

}


int main(int argc, char *argv[]) {

    long n, m;
    map<long, vector<long>> p;

    cin >> n >> m;

    for (long i = 0; i < m; i++) {

        long a, b;

        cin >> a >> b;

        p[a].push_back(b);
        p[b].push_back(a);
    }

    Graph graph(n, p);
    graph.buildTeams();
    return 0;
}
