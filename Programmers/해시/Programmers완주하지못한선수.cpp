#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> dic;
    string answer="";
    for (int i = 0; i < participant.size(); i++) {
        if (dic.find(participant[i]) != dic.end()) {
            dic[participant[i]]++;
            continue;
        }
        dic.insert(make_pair(participant[i], 1));
    }
    for (int i = 0; i < completion.size(); i++) {
        dic[completion[i]]--;
    }
    map<string, int>::iterator it;
    for (it = dic.begin(); it != dic.end(); it++) {
        if (it->second == 1) {
            answer = it->first;
            break;
        }
    }
    return answer;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<string> a;
    vector<string> b;

    a.emplace_back("marina");
    a.emplace_back("josipa");
    a.emplace_back("nikola");
    a.emplace_back("vinko");
    a.emplace_back("ana");
    a.emplace_back("ana");

    b.emplace_back("josipa");
    b.emplace_back("nikola");
    b.emplace_back("ana");
    b.emplace_back("marina");
    b.emplace_back("vinko");

    cout << solution(a, b);
    return 0;
}