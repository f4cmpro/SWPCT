#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int n, m;
    cin >> n >> n;

    vector<string> roads(n);
    for(int i = 0; i < n; i++) {
        cin >> roads[i];
    }

    vector<string> besties(m);
    for(int i = 0; i < m; i++) {
        cin >> besties[i];
    }
    int cur1 = 0;

    return 0;
}
