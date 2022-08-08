#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int time, int gold, vector<vector<int>> upgrade) {
    vector<int> v(upgrade.size());
    int ind = 0;
    for (int i = 0; i < upgrade.size(); ++i) {
        int t = time;
        int sum = 0;
        for (int j = 0; j < i; ++j) {
            int a = upgrade[j + 1][0];
            int b = upgrade[j + 1][1];
            int k = (a % gold) ? a / gold + 1 : a / gold;
            t = t - k * upgrade[j][1];
            if (t < 0)break;
            sum += (k * gold - a);
            for (int e = j + 1; e < upgrade.size()-1; ++e) {
                if (sum < upgrade[e + 1][0])break;
                sum -= upgrade[e + 1][0];
                j = e;
            }
        }
        v[i] = sum + t / upgrade[i][1] * gold;
    }
    return *max_element(v.begin(), v.end());
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cout << solution(100, 200, { {0,5},{1500, 3},{3000, 1} });
    cout << solution(49, 200, { {0,5},{1500, 3},{1501, 1} });
    cout << solution(11, 1000, { {0,5},{100, 4},{200,3} });

    return 0;
}   