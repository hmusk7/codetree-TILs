#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    // Please write your code here.
    vector<int> section(201, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = x1[i] + 100; j < x2[i] + 100; ++j) {
            section[j]++;
        }
    }

    int max_val = *max_element(section.begin(), section.end());

    cout << max_val;

    return 0;
}