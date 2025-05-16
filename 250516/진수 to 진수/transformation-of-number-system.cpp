#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a, b;
string n;

int main() {
    cin >> a >> b;
    cin >> n;

    // Please write your code here.
    int num10 = 0;
    for (char c : n) {
        num10 = num10 * a + (c - '0');
    }

    string ans;
    if (num10 == 0) {
        ans == "0";
    }
    else {
        while (num10 > 0) {
            int digit = num10 % b;
            ans.push_back(digit + '0');
            num10 /= b;
        }
        reverse(ans.begin(), ans.end());
    }

    cout << ans;

    return 0;
}