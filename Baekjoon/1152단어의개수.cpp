#include <iostream>
#include <string>
using namespace std;
int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    int wordCnt = 1;
    getline(cin, str);
    if (str[0] == ' ')
        wordCnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ')
            wordCnt++;
    }
    if (str[str.length() - 1] == ' ')
        wordCnt--;

    cout << wordCnt;
}