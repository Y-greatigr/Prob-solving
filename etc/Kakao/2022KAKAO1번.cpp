#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	map<string, int> list;
	map<pair<string, string>, int> de;
	map<string, int> email;
	for (int i = 0; i < report.size(); i++) {
		string a = report[i];
		int ind = a.find(" ");
		string b = a.substr(0, ind);
		string c = a.substr(ind + 1);
		if (de[{b, c}])continue; // 만약 이미 신고를 동일하게 했던 사람이라면
		list[{c}]++; // 신고당한 리스트에서 횟수 + 1
		de[{b, c}] = 1; // 신고자와 신고당한 사람 리스트 = 1
	}
	map<pair<string, string>, int>::iterator it;
	for (it = de.begin(); it != de.end(); it++) {
		string b = it->first.first;
		string c = it->first.second;
		if (list[c] < k)continue; // 만약 신고를 충분히 받지 않았다면
		email[b]++; // 만약 신고에 성공한 사람이라면 이메일 갯수 + 1
	}
	for (int i = 0; i < id_list.size(); i++) answer.push_back(email[id_list[i]]);
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<string> a = { "muzi", "frodo", "apeach", "neo" };
	vector<string> b = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
	vector<int> c = solution(a, b, 2);
	
	/*vector<string> a = { "con", "ryan" };
	vector<string> b = { "ryan con", "ryan con", "ryan con", "ryan con" };
	vector<int> c = solution(a, b, 3);
	*/
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << endl;
	return 0;
}