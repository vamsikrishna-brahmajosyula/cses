#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {

    long x, n;

    cin >> x >> n;

    multiset<long> positions;
    multiset<long> lengths;

    positions.insert(0);
    positions.insert(x);

    lengths.insert(x);

    for (long i = 0; i < n; i++) {

        long pos;
        cin >> pos;

        auto nextItr = positions.upper_bound(pos);

        long nextPos = *nextItr;
        long prevPos = *prev(nextItr, 1);

        long diff = nextPos - prevPos;

        lengths.erase(lengths.find(diff));

        lengths.insert(pos - prevPos);
        lengths.insert(nextPos - pos);

        positions.insert(pos);

        cout << *lengths.rbegin() << " ";
    }

    return 0;
}