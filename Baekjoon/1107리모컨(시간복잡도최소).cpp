#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
bool broken[10];
int can_push(int N) {
    int ret = 0;
    do {
        ret++;
        if (broken[N % 10])
            return 0;
        N /= 10;
    } while (N != 0);
    return ret;
}
int up(int N) {
    int ret = 0, len;
    while (N < 999900 && (len = can_push(N)) == 0) {
        ret++;
        N++;
    }
    if (N == 999900)
        return 987654321;
    return ret + len;
}
int down(int N) {
    int ret = 0, len;
    while (N >= 0 && (len = can_push(N)) == 0) {
        ret++;
        N--;
    }
    if (N < 0)
        return 987654321;
    return ret + len;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    while (M--) {
        int button; cin >> button;
        broken[button] = true;
    }

    cout << min({ up(N), down(N), abs(N - 100) }) << '\n';
}