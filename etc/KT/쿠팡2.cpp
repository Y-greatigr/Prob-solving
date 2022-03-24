#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> s;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<string> record = {"john share", "mary share", "jay share", "james comment", "lee share", "check noti", "sally comment", "laura comment", "check", "will share", "ruby share", "check"};
	vector<string>answer;
	vector<string> note;
	int flag = 0;
	int size = 0;
	for (int i = 0; i < record.size(); i++) {

		if (record[i].find("share") != string::npos) {
			int index = record[i].find(" ");
			string a = "";
			for (int j = 0; j < index; j++)
				a += record[i][j];
			if (size>0) {
				if (note[note.size() - 1].find("share") != string::npos) {
					if (note[note.size() - 1].find("and") != string::npos) {
						string wow = note[note.size() - 1];
						note.pop_back();
						int k = wow.find(" ");
						string b = "";
						for (int p = 0; p < k; p++) {
							b += wow[p];
						}
						int d = wow.find(" ", k + 1);
						if (isdigit(wow[d + 1]) != 0) {
							string cnt = "";
							int e = wow.find(" ", d + 1);
							cnt = wow.substr(d + 1, e - d - 1);
							int c = stoi(cnt) + 1;
							b += " and " + to_string(c) + " others shared your post";
						}
						else {
							b += " and 2 others shared your post";
						}
						note.push_back(b);
					}
					else {
						string wow = note[note.size() - 1];
						note.pop_back();
						int k = wow.find(" ");
						string b = "";
						for (int p = 0; p < k; p++) {
							b += wow[p];
						}
						b += " and " + a + " shared your post";
						note.push_back(b);
					}
				}
				else {
					a += " shared your post";
					note.push_back(a);
					size++;
				}
			}
			else {
				a += " shared your post";
				note.push_back(a);
				size++;
			}
			flag = 1;
		}
		else if (record[i].find("comment") != string::npos) {
			int index = record[i].find(" ");
			string a = "";
			for (int j = 0; j < index; j++)
				a += record[i][j];
			if (size>0) {
				if (note[note.size() - 1].find("comment") != string::npos) {
					if (note[note.size() - 1].find("and") != string::npos) {
						string wow = note[note.size() - 1];
						note.pop_back();
						int k = wow.find(" ");
						string b = "";
						for (int p = 0; p < k; p++) {
							b += wow[p];
						}
						int d = wow.find(" ", k + 1);
						if (isdigit(wow[d + 1]) != 0) {
							int e = wow.find(" ", d + 1);
							string cnt = "";
							cnt = wow.substr(d + 1, e - d - 1);
							int c = stoi(cnt) + 1;
							b += " and " + to_string(c) + " others commented your post";
						}
						else {
							b += " and 2 others commented your post";
						}
						note.push_back(b);
					}
					else {
						string wow = note[note.size() - 1];
						note.pop_back();
						int k = wow.find(" ");
						string b = "";
						for (int p = 0; p < k; p++) {
							b += wow[p];
						}
						b += " and " + a + " commented your post";
						note.push_back(b);
					}
				}
				else {
					a += " commentd your post";
					note.push_back(a);
					size++;
				}
			}
			else {
				a += " commentd your post";
				note.push_back(a);
				size++;
			}
			flag = 2;
		}
		else {
			string a = note[note.size() - 1];
			note.pop_back();
			answer.push_back(a);
			flag = 0;
			size--;
		}
	}
	for (int d = 0; d < answer.size(); d++) {
		cout << answer[d] << endl;
	}
	return 0;
}