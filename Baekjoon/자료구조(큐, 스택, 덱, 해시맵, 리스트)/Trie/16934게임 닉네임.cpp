#include<iostream>
#include<string>

#define ALPHA 26
#define N 100001
#define LNG 10

using namespace std;

int n, idx;

struct Node {
    int finished;
    int point[ALPHA];
    void init() {
        for (int i = 0; i < ALPHA; i++)
            point[i] = 0;
    }
}nodes[N * 3];

Node* newNode() {
    nodes[idx].finished = 0;
    return &nodes[idx++];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;  string input;

    Node* alpha = newNode();

    for (int i = 0; i < n; i++) {
        cin >> input;
        int lng = input.length();
        bool res = false;  string ans;
        Node* cur = alpha;
        for (int i = 0; i < lng; i++) {
            if (!cur->point[input[i] - 'a']) {
                Node* node = newNode();
                cur->point[input[i] - 'a'] = idx - 1;
                if (!res) {
                    res = true;
                    ans = input.substr(0, i + 1);
                }
            }
            cur = &nodes[cur->point[input[i] - 'a']];
        }
        cur->finished++;
        if (!res) {
            if (cur->finished == 1)
                cout << input << '\n';
            else
                cout << input + to_string(cur->finished) << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }
    return 0;
}