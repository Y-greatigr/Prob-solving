#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

struct Point{
    long long x,y;
    bool operator<=(Point const &k){
        if(x==k.x){
            return y<=k.y;
        }
        return x<=k.x;
    }
};
long long CCW2(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int CCW(Point a,Point b,Point c){
    if(CCW2(a,b,c)<0)return -1;
    else if(CCW2(a,b,c)==0)return 0;
    else return 1;
}
bool check(Point a,Point b,Point c,Point d){
    if(!(CCW(a,b,c) * CCW(a,b,d)) && !(CCW(c,d,a) * CCW(c,d,b))){
        if(b<=a)swap(a,b);
        if(d<=c)swap(c,d);
        return a<=d && c<=b;
    }
    return (CCW(a,b,c) * CCW(a,b,d)<=0 && CCW(c,d,a) * CCW(c,d,b) <=0);
}
int main(){
    FastIO;
    Point a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    cout<<(check(a,b,c,d)?1:0);
    return 0;
}