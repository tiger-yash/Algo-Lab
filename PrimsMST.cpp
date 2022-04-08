#include "bits/stdc++.h"
using namespace std;

#define vec vector
typedef set<int> si;
typedef vec<int> vi;
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define endl              '\n'
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pb                push_back
typedef pair<int, int> parii;
typedef vector<parii> vpii;
const int N=1e5;

vpii adj[N];
bool marked[N+1];

int prim(int x){
    priority_queue<parii, vpii, greater<parii> > Q;
    int y;
    int minimumCost = 0;
    parii p;

    Q.push(make_pair(0, x));

    while(!Q.empty()){
        
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.sc;

        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.fr;
        marked[x] = true;

        for(int i = 0;i < adj[x].size();++i){
            y = adj[x][i].sc;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main(){
    // cout<<"Enter the no. of vertices and edges : ";
    int n,m;cin>>n>>m;
    // cout<<"Enter the edges with the weight 'u v w' : "<<endl;

    rep(i,0,m){
        int u,v,w;cin>>u>>v>>w;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
    }

    // Selecting 1 as the starting node
    int minimumCost = prim(1);
    cout<<"Cost of Minimum Spanning Tree is : ";
    cout << minimumCost << endl;

    return 0;
}