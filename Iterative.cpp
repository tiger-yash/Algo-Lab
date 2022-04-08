#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)        for(int i=a;i<b;i++)
#define rev(i,a,b)        for(int i=a;i>b;i--)
const int N=-1e5;


void printMove(char st, char dst, int disk){
    cout <<"Disk " << disk <<" -> " << st << " to "<< dst << endl;
}

void moveDisks(stack<int> &src,stack<int> &dst,char s, char d) {
    int L_top,M_top;
    if(!src.empty()) {L_top=src.top();src.pop();}
    else L_top=N;
    if(!dst.empty()) {M_top = dst.top();dst.pop();}
    else M_top=N;
 
    // When src pole is empty
    if (L_top == N) {
    	src.push(M_top);
        printMove(d, s, M_top);
    }
 
    // When dst pole is empty
    else if (M_top == N) {
    	dst.push(L_top);
        printMove(s, d, L_top);
    }
 
    // When top disk of src > top disk of dst
    else if (L_top> M_top){
    	src.push(L_top);
    	src.push(M_top);
        printMove(d, s, M_top);
    }
 
    // When top disk of src < top disk of dst
    else{
    	dst.push(M_top);
    	dst.push(L_top);
        printMove(s, d, L_top);
    }
}
 
 
// Driver Program
int main(){
   
    int n;cin>>n;

 	stack <int> src;
	stack <int> dst;
	stack <int> mid;

    // L -> Left Most Rod (Source - src)
    // M -> Middle Rod (mid)
    // R -> Right Most Rod (Destination - dst)

    int i, total_shifts;
    char l = 'L', m = 'M', r = 'R';

    //interchange dst,mid
    if (n % 2 == 0){
        char temp = r;
        r = m;
        m = temp;
    }
    total_shifts = pow(2, n) - 1;
 
    // pushing larger disk
    rev(i,n,0) src.push(i);
       
 
    rep(i,1,total_shifts+1){
        if (i % 3 == 1) moveDisks(src,dst,l, r);
        else if (i % 3 == 2) moveDisks(src,mid,l,m);
        else if (i % 3 == 0) moveDisks(mid,dst, m, r);
    }

    return 0;
}