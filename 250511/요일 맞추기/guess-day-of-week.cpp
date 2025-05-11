#include <iostream>
#include <string>

using namespace std;

int m1, d1, m2, d2;
constexpr int days_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int prefix_days[13] = {};
string name_of_days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};


int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    // Please write your code here.
    for (int i = 1; i < 13; ++i) {
        prefix_days[i] = prefix_days[i - 1] + days_of_month[i];
    }

    int days = prefix_days[m2 - 1] + d2 - prefix_days[m1 - 1] - d1;
    if (days < 0) days += 6;
    cout << name_of_days[days % 7];

    return 0;
}