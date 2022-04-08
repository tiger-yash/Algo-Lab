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
#define all(x)            (x).begin(),(x).end()
typedef pair<int, int> parii;
typedef vector<parii> vpii;
const int N=1e9+7;

vec<pair<int,parii>> adj;

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

int B2kruskal(int n,int m){
	DSU mst(n);
	vi MST;int minCost=0;
	rep(i,0,m){
		int w = adj[i].fr;
		int u = adj[i].sc.fr; int v = adj[i].sc.sc;
		if(!mst.same(u,v)){
			mst.Union(u,v);
			MST.pb(i);
			minCost+=w;
		}
	}

	int B2minCost = N,edg = 0, sum = 0;

	rep(j,0,MST.size()){
		DSU mst2(n);
		rep(i,0,m){
			if(i==MST[j]) continue;
			int w = adj[i].fr;
			int u = adj[i].sc.fr; int v = adj[i].sc.sc;
			if(!mst2.same(u,v)){
				sum+=w;
				mst2.Union(u,v);
				++edg;
			}
		}
		if(edg==n-1 && B2minCost>sum && sum>minCost) B2minCost = sum;
		sum = 0,edg = 0;
	}
	
	return B2minCost;
}


signed main(){
	// cout<<"Enter the no. of vertices and edges : ";
	int n,m;cin>>n>>m;
	// cout<<"Enter the edges with the weight 'u v w' : "<<endl;

	rep(i,0,m){
		int u,v,w;cin>>u>>v>>w;
		adj.pb({w,{u,v}});
	}
	sort(all(adj));

	int B2minCost = B2kruskal(n,m);
	cout<<"Cost of 2nd Minimum Spanning Tree is : ";
	cout<<B2minCost;

	return 0;
}
