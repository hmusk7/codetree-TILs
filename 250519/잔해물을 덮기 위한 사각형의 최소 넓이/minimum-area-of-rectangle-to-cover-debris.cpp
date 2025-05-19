#include <iostream>

using namespace std;

int x1[2], y1[2];
int x2[2], y2[2];

int main() {
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];

    // Please write your code here.
    int grid[2001][2001] = {};
    for (int i = x1[0] + 1000; i < x2[0] + 1000; ++i) {
        for (int j = y1[0] + 1000; j < y2[0] + 1000; ++j) {
            grid[i][j] = 1;
        }
    }

    for (int i = x1[1] + 1000; i < x2[1] + 1000; ++i) {
        for (int j = y1[1] + 1000; j < y2[1] + 1000; ++j) {
            if (grid[i][j] == 1) grid[i][j] = 0;
        }
    }

    int minX = 1e9, maxX = 0, minY = 1e9, maxY = 0;
    for (int i = x1[0] + 1000; i < x2[0] + 1000; ++i) {
        for (int j = y1[0] + 1000; j < y2[0] + 1000; ++j) {
            if (grid[i][j] == 1) {
                if (minX > i) minX = i;
                if (maxX < i) maxX = i;
                if (minY > j) minY = j;
                if (maxY < j) maxY = j;
            }
        }
    }

    cout << (maxX - minX + 1) * (maxY - minY + 1);

    // int i = 0, j = 0;
    // while (grid[i][j] != 1) {
    //     i++; j++;
    // }
    // pair<int, int> dot1;
    // dot1.first = i;
    // dot1.second = j;

    // i = 2000; j = 2000;
    // while (grid[i][j] != 1) {
    //     i--; j--;
    // }
    // pair<int, int> dot2;
    // dot2.first = i;
    // dot2.second = j;

    // cout << (dot2.first - dot1.first - 1) * (dot2.second - dot1.second - 1);


    return 0;
}