#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)        for(int i=a;i<b;i++)
#define rev(i,a,b)        for(int i=a;i>b;i--)
 

int main(){
    int n;cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];


   for (int curr=1; curr<=n-1; curr *= 2){

       for (int lf=0; lf<n-1; lf += 2*curr){

            int mid = min(lf + curr - 1, n-1);
 
            int rt = min(lf + 2*curr - 1, n-1);
 
           // Mergint the Subarrays
            int l=lf,m=mid,r=rt;
            int x = m - l + 1;
            int y =  r - m;
         
            int L[x], R[y];

            rep(i,0,x) L[i] = a[l + i];
            rep(j,0,y) R[j] = a[m + 1+ j];

            int i=0, j=0, k=l;

            while (i < x && j < y){
                if (L[i] <= R[j]){
                    a[k] = L[i];
                    i++;
                }
                else{
                    a[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < x){
                a[k] = L[i];
                i++;
                k++;
            }
            while (j < y){
                a[k] = R[j];
                j++;
                k++;
            }
       }
   }
 
    cout <<"Sorted array :"<<endl;
    rep(i,0,n) cout<<a[i]<<" ";

    return 0;
}