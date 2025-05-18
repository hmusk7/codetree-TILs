#include <iostream>

using namespace std;

int N;
int x1[10], y1[10];
int x2[10], y2[10];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    // Please write your code here.
    int grid[201][201] = {};
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = x1[i] + 100; j < x2[i] + 100; ++j) {
            for (int k = y1[i] + 100; k < y2[i] + 100; ++k) {
                if (grid[j][k] == 1) continue;
                else {
                    grid[j][k] = 1;
                    count++;
                }
            }
        }
    }

    cout << count;
    
    return 0;
}