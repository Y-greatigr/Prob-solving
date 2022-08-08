#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[50];
bool config(string target, vector<string> words){
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == target)
            return true;
    }
    return false;
}
bool config2(string k, string a) {
    int cnt = 0;
    for (int j = 0; j < a.length(); j++) {
        if (k[j] != a[j]) cnt++;
        if (cnt > 1) return false;
    }
    return true;
}
int solution(string begin, string target, vector<string> words) {
    
    int answer = 0;
    if (!config(target, words)) return answer;
    
    queue<pair<string, int>>q;
    q.push({ begin, 0 });
    while (!q.empty()) {
        string a = q.front().first; 
        int count = q.front().second; q.pop();
        if (a == target)
            return count;
        for (int i = 0; i < words.size(); i++) {
            if (visited[i])
                continue;
            if (!config2(words[i], a)) continue;
            visited[i] = 1;
            q.push({ words[i],count + 1 });
        }
    }
    return answer;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<string> v = { "hot", "dot", "dog", "lot", "log", "cog" };
    cout << solution("hit", "cog", v);
    return 0;
}