#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};
bool compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
int solution(vector<vector<int>> jobs) {
    int answer = 0, index = 0, cur = 0;
    sort(jobs.begin(), jobs.end(), compare);
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    while (index < jobs.size() || !pq.empty()) {
        if (index<jobs.size() && jobs[index][0] <= cur) {
            pq.push(jobs[index++]); continue;
        }
        if (pq.empty()) {
            cur = jobs[index][0]; continue;
        }
        vector<int> a = pq.top(); pq.pop();
        int start = a[0]; int time = a[1];
        cur += time;
        answer += (cur - start);
    }
    return answer / jobs.size();
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<vector<int>> v = { {0,3}, {1, 9},{2,6} };
    cout << solution(v);
    return 0;
}