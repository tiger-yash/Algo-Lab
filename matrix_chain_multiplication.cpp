#include <bits/stdc++.h>
using namespace std;

const int inf=1e6;

int dp[1000][1000];


int mcm_dp(int a[] ,int l ,int r){
    if( l== r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = inf;
    int cnt=0;
    for(int i=l;i<r;i++) dp[l][r]=min(dp[l][r],mcm_dp(a,l,i)+mcm_dp(a,i+1,r)+(a[l-1]*a[i]*a[r]));
    return dp[l][r];
}

int rec(int a[],int l,int r){
    if( l == r) return 0;
    int minn = inf;
    int cnt=0;
    for(int i=l;i<r;i++){
        cnt = rec(a,l,i)+ rec(a,i+1,r)+ (a[l-1]*a[i]*a[r]);
        minn=min(cnt,minn);
    }
    return minn;
}

 
int main(){
    int n;
    cin>>n;
    n++;
    int a[n+1]={0};
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp, -1, sizeof(dp));
    cout<<"Min. multiplication for dp : "<<mcm_dp(a,1,n-1)<<"\n";
    cout<<"Min. multiplication for recursion : "<<rec(a,1,n-1);
    return 0;
}