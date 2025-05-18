#include <iostream>
#include <algorithm>

using namespace std;

int x1[3], y1_[3];
int x2[3], y2[3];

int main() {
    cin >> x1[0] >> y1_[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1_[1] >> x2[1] >> y2[1];
    cin >> x1[2] >> y1_[2] >> x2[2] >> y2[2];

    // Please write your code here.
    int grid[2001][2001] = {};
    int area = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = x1[i] + 1000; j < x2[i] + 1000; ++j) {
            for (int k = y1_[i] + 1000; k < y2[i] + 1000; ++k) {
                grid[j][k] = 1;
                area++;
            }
        }
    }

    for (int i = x1[2] + 1000; i < x2[2] + 1000; ++i) {
        for (int j = y1_[2] + 1000; j < y2[2] + 1000; ++j) {
            if (grid[i][j] == 1) area--;
        }
    }

    cout << area;

    return 0;
}