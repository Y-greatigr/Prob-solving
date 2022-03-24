#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<pair<string, double >, pair<int, int>> a, pair<pair<string, double >, pair<int, int>> b) {
    if (a.first.second == b.first.second) {
        if (a.second.first == b.second.first)
            return a.second.second < b.second.second;
        return a.second.first > b.second.first;
    }
    return a.first.second > b.first.second;
}
string solution(string character, vector<string> monsters) {
    string answer = "";
    int ind = character.find(" ");
    int player_p = stoi(character.substr(0, ind));
    int player_a = stoi(character.substr(ind, character.find(" ", ind + 1)));
    ind = character.find(" ", ind + 1);
    int player_d = stoi(character.substr(ind + 1));
    //cout << player_p << " " << player_a << " " << player_d << endl;

    vector < pair<pair<string, double >, pair<int,int>>> v;
    for (int i = 0; i < monsters.size(); ++i) {
        ind = monsters[i].find(" ");
        string monster_name = monsters[i].substr(0, ind);
        int monster_e = stoi(monsters[i].substr(ind, monsters[i].find(" ", ind+1)));
        ind = monsters[i].find(" ", ind+1);
        int monster_p = stoi(monsters[i].substr(ind, monsters[i].find(" ", ind + 1)));
        ind = monsters[i].find(" ", ind+1);
        int monster_a = stoi(monsters[i].substr(ind, monsters[i].find(" ", ind + 1)));
        ind = monsters[i].find(" ", ind + 1);
        int monster_d = stoi(monsters[i].substr(ind, monsters[i].find(" ", ind + 1)));
        //cout << monster_name << " " << monster_e << " " << monster_p << " " << monster_a << " " << monster_d << endl;
        if (monster_p <= player_a - monster_d) {
            v.push_back({ {monster_name, monster_e}, {monster_e, i} });
            continue;
        }
        if (player_p <= monster_a - player_d)continue;
        else {
            if (player_a <= monster_d)continue;

            double cnt = (monster_p % (player_a - monster_d)) ? monster_p / (player_a - monster_d) + 1 : monster_p / (player_a - monster_d);
            double ex_per = monster_e / cnt;
            v.push_back({ { monster_name, ex_per }, { monster_e, i }});
        }
    }
    sort(v.begin(), v.end(), cmp);

    return v[0].first.first;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    string a = "10 5 2";
    cout<<solution(a, { "Knight 3 10 10 3","Wizard 5 10 15 1","Beginner 1 1 15 1" });
    //vector<string> v = { "hot", "dot", "dog", "lot", "log", "cog" };
    //cout << solution("hit", "cog", v);
    return 0;
}