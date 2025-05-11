#include <iostream>

using namespace std;

int a, b, c;

int date_to_min(int day, int hour, int min) {
    if (day < 11 || (day < 11 && hour < 11) || (day < 11 && hour < 11 && min < 11)) return 0;
    return day * 24 * 60 + hour * 60 + min;
}

int main() {
    cin >> a >> b >> c;

    // Please write your code here.
    int total_min = date_to_min(a, b, c);
    if (total_min) cout << total_min - date_to_min(11, 11, 11);;
    else cout << -1;

    return 0;
}