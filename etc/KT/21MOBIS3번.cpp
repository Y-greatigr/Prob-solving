#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int print(vector<int> a) {
    queue<pair<vector<int>,int>> q;
    q.push({ a, 0 });
    while(!q.empty()) {
        vector<int> b = q.front().first;
        int cnt = q.front().second; q.pop();
        int k = b[0];
        for (int i = 1; i < b.size(); i++) k = (k & b[i]);
        if (!k)return cnt;
        for (int i = 0; i < b.size(); i++) {
            if (!b[i])continue;
            b[i] -= 1;
            q.push({ b,cnt + 1 });
            b[i] += 1;
        }
    }
}
vector<int> solution(vector<int> m, vector<int> b) {
    vector<int> answer;
    vector<vector<int>> tmp;
    int st = 0;
    for (int i = 0; i < m.size(); i++) {
        int a = m[i];
        vector<int> d(b.begin() + st, b.begin() + st + a);
        st += a;
        tmp.push_back(d);
    }
    for (int i = 0; i < tmp.size(); i++) answer.push_back(print(tmp[i]));
    return answer;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> p = { 2,2 };
    vector<int> q = { 3,2,1,2};

    vector<int> a = solution(p, q);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}