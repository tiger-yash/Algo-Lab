#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)        for(int i=a;i<b;i++)
#define rev(i,a,b)        for(int i=a;i>b;i--)


int main(){
    int n;cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];
    int stack[n];
    int top = 0,l=0,r=n-1;;
    stack[top] = l;
    ++top;
    stack[top] = r;
 

    while (top >= 0) {
        r = stack[top];--top;
        l = stack[top];--top;
 
        // to set Pivot
        int x = a[r];
        int i = (l - 1);
     
        for (int j = l; j <= r - 1; j++) {
            if (a[j] <= x) {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);

        //pivot
        int piv = i+1;


        if (piv - 1 > l) {
            stack[++top] = l;
            stack[++top] = piv - 1;
        }
 
        if (piv + 1 < r) {
            stack[++top] = piv + 1;
            stack[++top] = r;
        }
    }
    
    cout<<"Sorted Array : "<<endl;
    rep(i,0,n) cout<<a[i]<<" ";

    return 0;
}