#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;
vector<int> visited;
bool cmp(vector<string> a, vector<string> b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a < b;
}
int dfs(string start, vector<vector<string>> tickets, int cnt) {
    if (cnt == tickets.size()) {
        return 1;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start && !visited[i]) {
            answer.push_back(tickets[i][1]);
            visited[i] = 1;
            int a = dfs(tickets[i][1], tickets, cnt + 1);
            if (a) return 1;
            visited[i] = 0;
        }
    }
    answer.pop_back();
    return 0;
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), cmp);
    answer.push_back("ICN");
    visited.resize(tickets.size(), 0);
    dfs("ICN", tickets, 0);
    return answer;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    //vector<vector<string>> v = { {"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"} };
    vector<vector<string>> v = { {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{ "ATL", "SFO"}};
    vector<string> a = solution(v);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}