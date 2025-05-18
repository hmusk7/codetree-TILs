#include <iostream>
#include <algorithm>
#include <unordered_map>

#define WHITE 0
#define BLACK 1

using namespace std;

int n;
int x[1000];
char dir[1000];
struct Window {
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
    int curr_pos = 0;
    int prev_pos;
    Window white, black;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; ++i) {
        if (dir[i] == 'L') {
            white.right = max(curr_pos, white.right);
            prev_pos = curr_pos;
            curr_pos = curr_pos - x[i] + 1;
            white.left = curr_pos;

            for (int j = white.left; j <= prev_pos; ++j) {
                mp[j] = WHITE;
            }
        }

        else {
            black.left = min(curr_pos, black.left);
            prev_pos = curr_pos;
            curr_pos = curr_pos + x[i] - 1;
            black.right = curr_pos;

            for (int j = prev_pos; j <= black.right; ++j) {
                mp[j] = BLACK;
            }
        }
    }

    int white_count = 0, black_count = 0;
    for (auto m : mp) {
        if (m.second == WHITE) white_count++;
        else black_count++;
    }

    cout << white_count << " " << black_count;


    return 0;
}