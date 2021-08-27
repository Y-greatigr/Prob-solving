#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool rule(string s, int acnt) {
    if (s == "a")
        return true;
    if (s[0] == 'a')
        return rule(s.substr(1), acnt - 1);
    if (s[s.size() - 1] == 'a')
        return rule(s.substr(0, s.size() - 1), acnt - 1);
    if (s[0] == 'b' && s[s.size() - 1] == 'b') {
        if (!acnt)return false;
        for (int i = 0; i < acnt; i++) {
            if (s[i] != 'b')return false;
            if (s[s.size() - 1 - i] != 'b')return false;
        }
        return rule(s.substr(acnt, s.size() - 2 * acnt), acnt);
    }
    return false;
}
vector<bool> solution(vector<string> a) {
    vector<bool> answer;
    for (int i = 0; i < a.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < a[i].length(); j++) {
            if (a[i][j] == 'a')cnt++;
        }
        answer.push_back(rule(a[i], cnt));
    }
    return answer;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<string> v = { {"abab","bbaa","bababa","bbbabababbbaa", "abababa"} };
    vector<bool> a = solution(v);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}