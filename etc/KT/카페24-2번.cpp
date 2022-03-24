#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<string> solution(vector<int> numArr) {
	vector<string> answer;
	float sum = 0;
	for (int i = 0; i < numArr.size(); ++i)
		sum += numArr[i];
	sum /= 3;
	string ave = to_string(sum);
	if (ave.find(".") == string::npos)answer.push_back(ave);
	else answer.push_back(ave.substr(0, ave.find(".") + 3));
	int avg = round(sum * 100) / 100;
	if (avg >= 90)answer.push_back("A");
	else if (avg >= 80)answer.push_back("B");
	else if (avg >= 80)answer.push_back("C");
	else if (avg >= 80)answer.push_back("D");
	else answer.push_back("F");
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> a=solution({90, 80, 70});
	cout << a[0] << " " << a[1];
	//cout << solution(12);

	return 0;
}