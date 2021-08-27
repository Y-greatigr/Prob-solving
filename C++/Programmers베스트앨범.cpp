#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
bool compare(pair<pair<string, int>, int> a, pair<pair<string, int>, int> b) {
	if (a.first.first == b.first.first) {
		return a.first.second > b.first.second;
	}
	return a.first.first < b.first.first;
}
bool cmp(pair<string, int> a, pair<string, int> b){
	return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> dic;
	vector<pair<pair<string, int>, int>> tmp;
	for (int i = 0; i < genres.size(); i++) {
		dic[genres[i]] += plays[i];
		tmp.push_back({ { genres[i], plays[i] }, i });
	}
	sort(tmp.begin(), tmp.end(), compare);

	vector<pair<string, int>> v(dic.begin(), dic.end());
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		int r = 0;
		int flag = 0;
		for (int j = 0; j < tmp.size(); j++) {
			if (r == 2) {
				break;
			}
			if (flag == 1 && v[i].first != tmp[j].first.first)
				break;
			if (v[i].first == tmp[j].first.first) {
				flag = 1;
				r++;
				answer.push_back(tmp[j].second);
			}
		}
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<string> b(5);
	b = { "classic", "pop", "classic", "classic", "pop" };
	
	vector<int> c(5);
	c = { 500, 600, 150, 800, 2500 };
	
	vector<int> k = solution(b, c);
	for (int i = 0; i < k.size(); i++)
		cout << k[i] << endl;
	return 0;
}