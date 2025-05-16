#include <iostream>
#include <unordered_map>

#define WHITE 1
#define BLACK 2

using namespace std;

int n;
int x[1000];
char dir[1000];
struct Section {
    int left = 0;
    int right = 0;
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
    int prev_turn = 0;
    Section white, black;
    unordered_map<int, pair<int, int>> mp;

    for (int i = 0; i < n; ++i) {
        if (dir[i] == 'L') {
            if (prev_turn == BLACK) white.right = pos;
            pos = pos - x[i] + 1;
            white.left = pos;
            prev_turn = WHITE;

            for (int i = white.left; i <= white.right; ++i) {
                if (mp[i].second == BLACK) mp[i].first++;
                mp[i].second = WHITE;
            }
        }

        else {
            if (prev_turn == WHITE) black.left = pos;
            pos = pos + x[i] - 1;
            black.right = pos;
            prev_turn = BLACK;

            for (int i = black.left; i <= black.right; ++i) {
                if (mp[i].second == WHITE) mp[i].first++;
                mp[i].second = BLACK;
            }
        }
    }

    int left = (white.left <= black.left) ? white.left : black.left;
    int right = (black.right <= white.right) ? white.right : black.right;
    int white_count = 0, black_count = 0, gray_count = 0;
    for (int i = left; i <= right; ++i) {
        if (mp[i].first >= 3) gray_count++;
        else if (white.left <= i && i <= white.right) white_count++;
        else black_count++;
    }

    cout << white_count << " " << black_count << " " << gray_count;

    return 0;
}