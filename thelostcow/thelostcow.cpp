#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    long long x, y;
    cin >> x >> y;

    long long totalDist = 0;
    long long currentPos = x;
    long long stepSize = 1;   // Distance from x for this turn point
    int direction = 1;        // +1 = right, -1 = left (starts going right: x+1)

    while (true) {
        // Next turn point in the zig-zag pattern
        long long nextPos = x + direction * stepSize;

        // Check if Bessie is on this leg of the journey
        // "On this leg" means y is between currentPos and nextPos (inclusive)
        bool bessieFound = (direction == 1)
            ? (y >= currentPos && y <= nextPos)   // moving right
            : (y <= currentPos && y >= nextPos);  // moving left

        if (bessieFound) {
            // FJ reaches Bessie before (or at) the turn point
            totalDist += abs(y - currentPos);
            break;
        }

        // Bessie not on this leg — travel the full leg to the turn point
        totalDist += abs(nextPos - currentPos);
        currentPos = nextPos;

        // Prepare next leg: double the step, flip direction
        stepSize *= 2;
        direction *= -1;
    }

    cout << totalDist << endl;
    return 0;
}