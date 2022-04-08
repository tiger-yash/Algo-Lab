#include "bits/stdc++.h"
using namespace std;

#define vec vector
typedef set<int> si;
typedef vec<int> vi;
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define endl 			  '\n'
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pb                push_back
typedef pair<int, int> parii;
typedef vector<parii> vpii;

set<pair<int,parii>> adj;

class DSU {
	private:
	  vi par, rnk, ln;
	  int c;

	public:
	  DSU(int n) : par(n + 1), rnk(n + 1, 0), ln(n + 1, 1), c(n) {
	    rep(i,1,n+1) par[i] = i;
	  }

	  int get(int a) {
	    return (par[a] == a ? a : (par[a] = get(par[a])));
	  }

	  bool same(int a, int b) {
	    return get(a) == get(b);
	  }

	  int Union(int a, int b) {
	    if ((a = get(a)) == (b = get(b))) return -1;
	    else --c;
	    if (rnk[a] > rnk[b]) swap(a, b);
	    par[a] = b;
	    ln[b] += ln[a];
	    if (rnk[a] == rnk[b]) rnk[b]++;
	    return b;
	  }
};

int kruskal(int n){
	DSU mst(n);
	int minCost=0;
	for(auto it=adj.begin();it!=adj.end();it++){
		int w = (*it).fr;
		int u = (*it).sc.fr; int v = (*it).sc.sc;
		if(!mst.same(u,v)){
			minCost+=w;
			mst.Union(u,v);
		}
	}
	return minCost;
}


signed main(){
	// cout<<"Enter the no. of vertices and edges : ";
	int n,m;cin>>n>>m;
	// cout<<"Enter the edges with the weight 'u v w' : "<<endl;

	rep(i,0,m){
		int u,v,w;cin>>u>>v>>w;
		adj.insert({w,{u,v}});
	}
	int minCost = kruskal(n);
	cout<<"Cost of Minimum Spanning Tree is : ";
	cout<<minCost;
	return 0;
}
