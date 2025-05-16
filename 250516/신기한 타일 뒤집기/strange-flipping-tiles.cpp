#include <iostream>
#include <deque>

#define WHITE 0
#define BLACK 1

using namespace std;


int n;
int x[1000];
char dir[1000];
deque<int> dq;

void flip_to_right(int i) {
    int pop_count = 0, push_count = 0;

    for (int j = 0; j < x[i]; ++j) {
        if (dq.empty()) {
            dq.push_front(BLACK);
            push_count++;
        }
        else if (dq.front() == WHITE) {
            dq.pop_front();
            pop_count++;
        }
    }

    for (int j = push_count; j < x[i]; ++j) {
        dq.push_front(BLACK);
    }
}

void flip_to_left(int i) {
    int pop_count = 0, push_count = 0;
    
    for (int j = 0; j < x[i]; ++j) {
        if (dq.empty()) {
            dq.push_back(WHITE);
            push_count++;
        }
        else if (dq.back() == BLACK) {
            dq.pop_back();
            pop_count++;
        }
    }
    for (int j = push_count; j < x[i]; ++j) {
        dq.push_back(WHITE);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    // Please write your code here.    
    for (int i = 0; i < n; ++i) {
        if (dir[i] == 'R') {
            flip_to_right(i);
        }

        else {
            flip_to_left(i);
        }
    }

    int white_count = 0, black_count = 0;
    for (auto tile : dq) {
        if (tile == BLACK) black_count++;
        else white_count++;
    }

    cout << white_count << " " << black_count;

    return 0;
}