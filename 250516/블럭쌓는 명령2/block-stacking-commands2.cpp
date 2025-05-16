#include <iostream>
#include <vector>

using namespace std;

int N, K;
int A[100], B[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
    }

    // Please write your code here.
    vector<int> grid(N, 0);
    for (int i = 0; i < K; ++i) {
        if (A[i] >= B[i]) {
            for (; A[i] >= B[i]; --A[i]) {
                grid[A[i]]++;
            }
        }

        else {
            for (; B[i] >= A[i]; --B[i]) {
                grid[B[i]]++;
            }
        }
    }

    int max_val = 0;
    for (int i = 0; i < N; ++i) {
        if (max_val < grid[i]) max_val = grid[i];
    }

    cout << max_val;

    return 0;
}