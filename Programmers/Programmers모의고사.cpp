#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[5] = { 1,2,3,4,5 };
    int b[8] = { 2,1,2,3,2,4,2,5 };
    int c[10] = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> wow(3);
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == a[i % 5]) wow[0]++;
        if (answers[i] == b[i % 8]) wow[1]++;
        if (answers[i] == c[i % 10]) wow[2]++;
    }
    int max = *max_element(wow.begin(), wow.end());
    for (int i = 0; i < 3; i++) {
        if (wow[i] == max)
            answer.push_back(i + 1);
    }
    return answer;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v = { 1,2,3,4,5 };
    vector<int> a = solution(v);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}