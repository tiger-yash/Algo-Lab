#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)        for(int i=a;i<b;i++)
#define rev(i,a,b)        for(int i=a;i>b;i--)

void toh(int n, char src, char dst, char mid) { 
    if (n == 0) return;
    toh(n - 1, src, mid, dst); 
    cout <<"Disk "<<n<<" -> " <<src<<" to "<<dst<<endl; 
    toh(n - 1, mid, dst, src); 
} 

// Driver code
int main() { 
    int n;cin>>n;

    // L -> Left Most Rod (Source - src)
    // M -> Middle Rod (mid)
    // R -> Right Most Rod (Destination - dst)
    
    toh(n, 'L', 'M', 'R'); 

    return 0; 
} 