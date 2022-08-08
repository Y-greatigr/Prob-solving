#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    while (pq.top() < K) {
        int a = pq.top(); pq.pop();
        if (pq.empty()) {
            answer = -1; break;
        }
        int b = pq.top(); pq.pop();
        pq.push(a + 2 * b);
        answer++;
    }
    return answer;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v = { 1, 2, 3, 9, 10, 12 };
    cout << solution(v, 7);
    return 0;
}