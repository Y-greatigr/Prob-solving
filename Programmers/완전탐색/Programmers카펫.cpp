#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for (int i = 3; i <= sum; i++) {
        if (sum % i)
            continue;
        int a = sum / i - 2;
        int b = i - 2;
        if (a * b == yellow) {
            answer.push_back(a + 2);
            answer.push_back(i);
            break;
        }
    }
    return answer;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int brown = 8;
    int yellow = 1;
    vector<int> a = solution(brown, yellow);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}