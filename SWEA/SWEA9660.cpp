#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int ar[5000];
bool visited[5001]={false, };
long long ans=0;
void dfs(int cur, int lim){
    if(cur==lim-1){
        for(int i=1;i<=lim;i++){
            if(ar[cur]!=i && !visited[i])
                ans++;
        }
        return;
    }
    for(int i=1;i<=lim;i++){
        if(ar[cur]==i || visited[i])continue;
        visited[i]=true;
        dfs(cur+1, lim);
        visited[i]=false;
    }
}
int main(){
    FastIO;
    int T;cin>>T;
    for(int i=1;i<=T;i++){
        ans=0;
        int n;cin>>n;
        for(int j=0;j<n;j++)cin>>ar[j];
        for(int j=1;j<=n;j++){
            if(ar[0]==j)continue;
            visited[j]=true;
            dfs(1,n);
            visited[j]= false;
        }
        cout<<'#'<<i<<" "<<ans%1'000'000'007<<'\n';
    }
    return 0;
}

/**
* #include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
using lld = long long int;
using pii = pair<int, int>;
using pil = pair<int, lld>;
using pli = pair<lld, int>;
using pll = pair<lld, lld>;
using llz = long long int;
using lf = long double;
#define M 1000000007
int n, m;
lld f[100009];
int a[100009];
void inil() {
    f[0] = 1;
    for (int i = 1; i <= 5000; i++) {
        f[i] = (f[i - 1] * i) % M;
    }
}
lld d[2][5009];
int main() {
    inil();
    int t = 1, tv = 0;
    int i, j, k, l;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (i = 0; i < n; i++) {
            if (a[i] > n)break;
        }
        m = i;
        lld res = f[n];
        int cur = 0;
        int nxt = 1;
        for (i = 0; i <= m + 1; i++) {
            d[0][i] = d[1][i] = 0;
        }
        d[0][0] = 1;
        int tm = 1;
        for (i = 0; i < m;) {
            for (j = i; j < m; j++) {
                if (a[i] != a[j])break;
            }
            d[nxt][0] = 1;
            for (k = 1; k <= tm; k++) {
                d[nxt][k] = (d[cur][k] + (j-i)*d[cur][k-1])%M;
            }
            tm++;
            i = j;
            cur ^= 1;
            nxt ^= 1;
        }
        for (i = 1; i < tm; i++) {
            lld ss = d[cur][i] * f[n - i] % M;
            if (i & 1) {
                res = (res + M - ss) % M;
            }
            else {
                res = (res + ss) % M;
            }
        }

        printf("#%d %lld\n", ++tv, res);
    }
}
*/