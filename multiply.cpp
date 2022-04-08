#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b)        for(int i=a;i<b;i++) 
int binToDec(string n){
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
string decToBin(int n){
    string s = bitset<64> (n).to_string();
    const auto loc1 = s.find('1');
    if(loc1 != string::npos)
        return s.substr(loc1);
    return "0";
}



string binAdd( string s1, string s2){
    string result;int carry = 0;
 
    int p=s1.size(),q=s2.size();
    int len = p;
    if (p < q){
        rep(i,0,q-p) s1 = '0' + s1;
        len=q;
    }else if (p > q){
        rep(i,0,p-q) s2 = '0' + s2;
    }
    
    // Addition
    for (int i = len-1 ; i >= 0 ; i--){
        int bit_a = s1.at(i) - '0';
        int bit_b = s2.at(i) - '0';

        int sum = (bit_a ^ bit_b ^ carry)+'0';
 
        result = (char)sum + result;
        carry = (bit_a&bit_b) | (bit_b&carry) | (bit_a&carry);
    }

    if (carry)  result = '1' + result;
    return result;
}
 
int MUL(string a, string b){
    string lft_a,lft_b,rt_a,rt_b;
    int x,y,z;
    int p=a.size(),q=b.size();
    int n=p;

    if (p < q){
        rep(i,0,q-p) a = '0' + a;
        n=q;
    }else if (p > q){
        rep(i,0,p-q) b = '0' + b;
    }

    if (n == 0) return 0;
    if (n == 1) return (a[0] - '0')*(b[0] - '0');
 
    int lft = n/2;  
    int rt = (n-lft); 

    // left part
    lft_a =a.substr(0, lft);
    rt_a =a.substr(lft, rt);

    // right part
    lft_b = b.substr(0, lft);
    rt_b = b.substr(lft, rt);
 
    x = MUL(lft_a, lft_b); y = MUL(rt_a, rt_b);
    z = MUL(binAdd(lft_a, rt_a), binAdd(lft_b, rt_b));
 
    return x*(1<<(2*rt)) + (z - x - y)*(1<<rt) + y;
}
 
int main(){
    string a,b;cin>>a>>b;
    cout<<"1st binary in Decimal : "<<binToDec(a)<<endl;
    cout<<"2nd binary in Decimal : "<<binToDec(b)<<endl<<endl;
    int res=MUL(a,b);
    cout<<"Result : "<<decToBin(res)<<endl;
    cout<<"Result in Decimal : "<<res<<endl;
}