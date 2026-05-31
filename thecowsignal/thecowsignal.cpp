#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("cowsignal.in", "r", stdin);
    // freopen("cowsignal.out", "w", stdout);
    int m, n, k;
    cin >> m >> n >> k;

    vector<string> grid(m);
    for (int i = 0; i < m; i++) cin >> grid[i];

    for (int i = 0; i < m; i++) {
        for (int r = 0; r < k; r++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c < k; c++) {
                    cout << grid[i][j];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
