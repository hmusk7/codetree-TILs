#include <iostream>

using namespace std;

int m1, d1, m2, d2;
int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int prefix_days[13] = {};

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    // Please write your code here.
    for (int i = 1; i < 13; ++i) {
        prefix_days[i] = prefix_days[i - 1] + num_of_days[i];
    }

    cout << prefix_days[m2 - 1] + d2 - prefix_days[m1 - 1] - d1 + 1;


    return 0;
}