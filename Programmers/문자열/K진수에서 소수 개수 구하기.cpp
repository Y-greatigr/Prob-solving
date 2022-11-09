#include <bits/stdc++.h>

using namespace std;

string to_k(int n, int k){
    string answer="";
    while(n){
        answer=to_string(n%k)+answer;
        n/=k;
    }
    return answer;
}
bool is_prime(long long k){
    if(k==1)return false;
    for(long long i=2;i*i<=k;i++){
        if(k%i==0)return false;
    }
    return true;
}
long long divide(string s){
    long long sum=0;
    int ind;
    while((ind=s.find("0"))!=string::npos){
        string tmp=s.substr(0,ind);
        if(ind!=0 && is_prime(stol(tmp)))sum++;
        s=s.substr(ind+1);
    }
    if(s.length()!=0 && is_prime(stol(s)))sum++;
    return sum;
}
long long solution(int n, int k) {
    string s=to_k(n,k);
    return divide(s);
}