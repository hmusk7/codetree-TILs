#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define WHITE 0
#define BLACK 1

using namespace std;

int n;
int x[1000];
char dir[1000];
struct Section {
    int left = 0;
    int right = 0;
};
struct Vec3 : vector<int> {
    Vec3() : vector<int>(3,0) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    // Please write your code here.
    // 0에서 출발한다고 가정
    int pos = 0;
    int prev_turn = -1;
    Section white, black;
    unordered_map<int, Vec3> mp;

    for (int i = 0; i < n; ++i) {
        if (dir[i] == 'L') {
            if (prev_turn == BLACK) white.right = max(pos, white.right);
            pos = pos - x[i] + 1;
            white.left = pos;
            prev_turn = WHITE;

            for (int i = white.left; i <= white.right; ++i) {
                mp[i][WHITE]++;
                mp[i][2] = WHITE;
            }
        }

        else {
            if (prev_turn == WHITE) black.left = min(pos, black.left);
            pos = pos + x[i] - 1;
            black.right = pos;
            prev_turn = BLACK;

            for (int i = black.left; i <= black.right; ++i) {
                mp[i][BLACK]++;
                mp[i][2] = BLACK;
            }
        }
    }
    int white_count = 0, black_count = 0, gray_count = 0;
    for (auto v : mp) {
        if (v.second[0] >= 2 && v.second[1] >=2) gray_count++;
        else if (v.second[2] == WHITE) white_count++;
        else black_count++;
    }

    /*
    int left = min(white.left, black.left);
    int right = max(white.right, black.right);
    for (int i = left; i <= right; ++i) {
        if (mp[i][0] >= 2 && mp[i][1] >= 2) gray_count++;
        else if (mp[i][2] == WHITE) white_count++;
        else if (mp[i][2] == BLACK) black_count++;
    }*/

    cout << white_count << " " << black_count << " " << gray_count;

    return 0;
}