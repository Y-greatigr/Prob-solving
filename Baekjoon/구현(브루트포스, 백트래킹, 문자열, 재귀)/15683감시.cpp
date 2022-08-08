#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int cnt=0, mini=100, N,M;
int a[8][8];
vector<tuple<int,int,int>> v;

void upp(int cur, queue<int> &qq){
    for(int i=get<1>(v[cur])-1;i>=0;i--){
        if(a[i][get<2>(v[cur])]==6)break;
        qq.push(a[i][get<2>(v[cur])]);
        a[i][get<2>(v[cur])]=1;
    }
}
void rev_upp(int cur, queue<int> &qq){
    for(int i=get<1>(v[cur])-1;i>=0;i--){
        if(a[i][get<2>(v[cur])]==6)break;
        int d=qq.front();qq.pop();
        a[i][get<2>(v[cur])]=d;
    }
}
void downn(int cur, queue<int> &qq){
    for(int i=get<1>(v[cur])+1;i<N;i++){
        if(a[i][get<2>(v[cur])]==6)break;
        qq.push(a[i][get<2>(v[cur])]);
        a[i][get<2>(v[cur])]=1;
    }
}
void rev_downn(int cur, queue<int>& qq){
    for(int i=get<1>(v[cur])+1;i<N;i++){
        if(a[i][get<2>(v[cur])]==6)break;
        int d=qq.front();qq.pop();
        a[i][get<2>(v[cur])]=d;
    }
}
void leftt(int cur, queue<int> &qq){
    for(int i=get<2>(v[cur])-1;i>=0;i--){
        if(a[get<1>(v[cur])][i]==6)break;
        qq.push(a[get<1>(v[cur])][i]);
        a[get<1>(v[cur])][i]=1;
    }
}
void rev_leftt(int cur, queue<int>& qq){
    for(int i=get<2>(v[cur])-1;i>=0;i--){
        if(a[get<1>(v[cur])][i]==6)break;
        int d=qq.front();qq.pop();
        a[get<1>(v[cur])][i]=d;
    }
}
void rightt(int cur, queue<int> &qq){
    for(int i=get<2>(v[cur])+1;i<M;i++){
        if(a[get<1>(v[cur])][i]==6)break;
        qq.push(a[get<1>(v[cur])][i]);
        a[get<1>(v[cur])][i]=1;
    }
}
void rev_rightt(int cur, queue<int> &qq){
    for(int i=get<2>(v[cur])+1;i<M;i++){
        if(a[get<1>(v[cur])][i]==6)break;
        int d=qq.front();qq.pop();
        a[get<1>(v[cur])][i]=d;
    }
}
void dfs(int cur){
    if(cur==cnt){
        int sum=0;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(!a[i][j])sum++;
        mini=min(sum, mini);
        return;
    }
    if(get<0>(v[cur])==1){
        queue<int> q1;
        downn(cur, q1);
        dfs(cur+1);     // 1번 아래쪽
        rev_downn(cur, q1);
        
        queue<int> q2;
        upp(cur, q2);
        dfs(cur+1);     // 1번 위쪽
        rev_upp(cur, q2);

        queue<int> q3;
        leftt(cur, q3);
        dfs(cur+1);     // 1번 왼쪽
        rev_leftt(cur, q3);

        queue<int> q4;
        rightt(cur, q4);
        dfs(cur+1);     // 1번 오른쪽
        rev_rightt(cur, q4);
    }
    else if(get<0>(v[cur])==2){
        queue<int> q1;
        upp(cur, q1);
        downn(cur, q1);
        dfs(cur+1);     // 2번 세로
        rev_upp(cur, q1);
        rev_downn(cur, q1);

        queue<int> q2;
        rightt(cur, q2);
        leftt(cur, q2);
        dfs(cur+1);     // 2번 가로
        rev_rightt(cur, q2);
        rev_leftt(cur, q2);
    }
    else if(get<0>(v[cur])==3){
        queue<int> q1;
        upp(cur, q1);
        rightt(cur, q1);
        dfs(cur+1);     // 3번 위, 오른
        rev_upp(cur, q1);
        rev_rightt(cur, q1);

        queue<int> q2;
        upp(cur, q2);
        leftt(cur, q2);
        dfs(cur+1);     // 3번 위, 왼
        rev_upp(cur, q2);
        rev_leftt(cur, q2);

        queue<int> q3;
        downn(cur, q3);
        rightt(cur, q3);
        dfs(cur+1);     // 3번 아래, 오른
        rev_downn(cur, q3);
        rev_rightt(cur, q3);

        queue<int> q4;
        downn(cur, q4);
        leftt(cur, q4);
        dfs(cur+1);     // 3번 아래, 왼
        rev_downn(cur, q4);
        rev_leftt(cur, q4);
    }
    else if(get<0>(v[cur])==4){
        
        queue<int> q1;
        downn(cur, q1);
        leftt(cur, q1);
        upp(cur, q1);
        dfs(cur+1);     // 4번 아래, 왼, 위
        rev_downn(cur, q1);
        rev_leftt(cur, q1);
        rev_upp(cur, q1); 

        queue<int> q2;
        downn(cur, q2);
        leftt(cur, q2);
        rightt(cur, q2);
        dfs(cur+1);     // 4번 아래, 왼, 오른
        rev_downn(cur, q2);
        rev_leftt(cur, q2);
        rev_rightt(cur, q2);

        queue<int> q3;
        downn(cur, q3);
        rightt(cur, q3);
        upp(cur, q3);
        dfs(cur+1);     // 4번 아래, 오른, 위
        rev_downn(cur, q3);
        rev_rightt(cur, q3);
        rev_upp(cur, q3);

        queue<int> q4;
        rightt(cur, q4);
        leftt(cur, q4);
        upp(cur, q4);
        dfs(cur+1);     // 4번 오른, 왼, 위
        rev_rightt(cur, q4);
        rev_leftt(cur, q4);
        rev_upp(cur, q4);
    }
    else if(get<0>(v[cur])==5){
        queue<int> q;
        downn(cur, q);
        upp(cur, q);
        leftt(cur, q);
        rightt(cur, q);
        dfs(cur+1);     // 5번
        rev_downn(cur, q);
        rev_upp(cur, q); 
        rev_leftt(cur, q);
        rev_rightt(cur, q);
    }
}
int main(){
    FastIO;
    cin>>N>>M;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){cin>>a[i][j];if(a[i][j]>0 && a[i][j]<6){v.push_back(make_tuple(a[i][j],i,j));cnt++;}}
    dfs(0);
    cout<<mini;
    return 0;
}
