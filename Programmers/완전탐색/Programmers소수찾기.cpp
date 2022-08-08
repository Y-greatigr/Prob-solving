#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int answer = 0;
int k[10000000];
bool visited[10000000];

void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}
void permutation(string data, int depth, int n, int r)
{
    if (depth == r)
    {
        string a = "";
        for (int i = 0; i < r; i++)
            a += data[i];
        if (k[stoi(a)] == 0 && !visited[stoi(a)]) {
            answer++;
            visited[stoi(a)] = true;
        }
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(data[depth], data[i]);   // 스왑
        permutation(data, depth + 1, n, r);  // ⭐재귀
        swap(data[depth], data[i]);  // 다시 원래 위치로 되돌리기
    }
}
int solution(string numbers) {
    memset(k, 0, sizeof(k));
    k[0] = 1; k[1] = 1;
    for (int i = 2; i < 5000000; i++) {
        for (int j = 2; j <= 100000; j++) {
            if (i * j >= 10000000)
                break;
            k[i * j] = 1;
        }
    }
    for (int i = 1; i <= numbers.size(); i++) {
        permutation(numbers, 0, numbers.size(), i);
    }
    return answer;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    string a = "011";
    cout << solution(a);
    return 0;
}