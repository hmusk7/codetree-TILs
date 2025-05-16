#include <iostream>
#include <vector>

using namespace std;

const int DAYS_OF_MONTH[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string DAY_OF_WEEK[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int m1, m2, d1, d2;
string A;

int calculate_days() {
    int days = 0;
    for (int i = m1; i < m2; ++i) {
        days += DAYS_OF_MONTH[i];
    }
    days += d2 - d1;

    return days;
}

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    // Please write your code here.
    int ans;
    int days = calculate_days();
    if (days == 0) {
        cout << 0;
        return 0;
    }
    else {
        for (int i = 0; i < 7; ++i) {
            if (A == DAY_OF_WEEK[i]) {
                days -= i;
                ans = days / 7 + 1;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}