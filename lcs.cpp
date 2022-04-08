#include <bits/stdc++.h>
using namespace std;



/***********************************************************/
 
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    int cur[m+1]={},pre[m+1]={};

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s2[j-1]==s1[i-1]){
                cur[j]=1+pre[j-1];
            }
            else{
                cur[j]=max(cur[j-1],pre[j]);
            }
        }
        for(int j=0;j<=m;j++){
            pre[j]=cur[j];
        }
    }

    cout<<cur[m]<<"\n";
    return 0;
}