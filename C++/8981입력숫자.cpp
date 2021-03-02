#include <iostream>
using namespace std;
int NUM[30];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, from = 0, value;
    cin >> N;
    cin >> value;
    NUM[from] = value;
    for (int i = 1; i < N; i++) {
        from = (from + value) % N;
        while (NUM[from])
            from = (from + 1) % N;
        cin >> value;
        NUM[from] = value;   
    }
    cout << N << '\n';
    for (int i = 0; i < N; i++)
        cout << NUM[i] << " ";
    return 0;
}