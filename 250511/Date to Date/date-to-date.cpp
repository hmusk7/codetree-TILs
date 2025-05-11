#include <iostream>

using namespace std;

int m1, d1, m2, d2;
int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int sum_days(int month) {
    int sum;
    for (int i = month - 1; i > 0; --i) {
        sum += num_of_days[i];
    }
    return sum;
}

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    // Please write your code here.
    cout << sum_days(m2) + d2 - sum_days(m1) - d1 + 1;


    return 0;
}