#include <iostream>

using namespace std;

char binary[9];

int main() {
    cin >> binary;

    // Please write your code here.
    int num = 0;
    for (int i = 0; binary[i]; ++i) {
        num = num * 2 + (binary[i] - '0');
    }
    cout << num;

    return 0;
}