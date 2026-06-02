#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    
    // Mảng lưu giới hạn tốc độ và tốc độ Bessie tại mỗi dặm
    int roadLimit[100] = {};
    int bessieSpeed[100] = {};
    
    // Đọc N đoạn đường
    int pos = 0;
    for (int i = 0; i < N; i++) {
        int length, limit;
        cin >> length >> limit;
        // Điền giới hạn tốc độ cho từng dặm thuộc đoạn này
        for (int j = pos; j < pos + length; j++) {
            roadLimit[j] = limit;
        }
        pos += length;
    }
    
    // Đọc M đoạn Bessie đi
    pos = 0;
    for (int i = 0; i < M; i++) {
        int length, speed;
        cin >> length >> speed;
        // Điền tốc độ Bessie cho từng dặm thuộc đoạn này
        for (int j = pos; j < pos + length; j++) {
            bessieSpeed[j] = speed;
        }
        pos += length;
    }
    
    // Tìm mức vượt tốc độ tối đa
    int maxOver = 0;
    for (int i = 0; i < 100; i++) {
        int over = bessieSpeed[i] - roadLimit[i];
        if (over > maxOver) {
            maxOver = over;
        }
    }
    
    cout << maxOver << endl;
    
    return 0;
}
