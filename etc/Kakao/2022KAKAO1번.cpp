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
		if (de[{b, c}])continue; // ���� �̹� �Ű� �����ϰ� �ߴ� ����̶��
		list[{c}]++; // �Ű���� ����Ʈ���� Ƚ�� + 1
		de[{b, c}] = 1; // �Ű��ڿ� �Ű���� ��� ����Ʈ = 1
	}
	map<pair<string, string>, int>::iterator it;
	for (it = de.begin(); it != de.end(); it++) {
		string b = it->first.first;
		string c = it->first.second;
		if (list[c] < k)continue; // ���� �Ű� ����� ���� �ʾҴٸ�
		email[b]++; // ���� �Ű� ������ ����̶�� �̸��� ���� + 1
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