#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define all(x) (x).begin(), (x).end()
#define compress(x) do { sort(all(x)); (x).erase(unique(all(x)), (x).end()); } while(0)
using namespace std;
int32_t main() {
    fastio;
    string a; cin >> a;
    map<string, int> m;
    for (int i = 0; i <= 25; ++i) {
        char c = 'a' + i;
        string s(1, c);
        m[s] = 1;
    }
    m["c="] = 1; m["c-"] = 1; m["dz="] = 1; m["d-"] = 1; m["lj"] = 1; m["nj"] = 1; m["s="] = 1; m["z="] = 1;
    int cnt = 0;
    for (int i = 0; i < a.length(); ++i) {
        string k(1, a[i]);
        for (int j = i + 1; j < i + 3; ++j) {
            if (j >= a.length())break;
            k += a[j];
        }
        if (m[k]) i += 2;
        else if (m[k.substr(0,2)]) i += 1;
        ++cnt;
    }
    cout << cnt;
    return 0;
}