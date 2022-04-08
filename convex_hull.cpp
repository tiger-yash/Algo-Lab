#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)        for(int i=a;i<b;i++)
  
set<pair<int, int>> hull;
  
// relative side of pt. wrt line
int findSide(pair<int,int> p1, pair<int,int> p2, pair<int,int> p){
    int val = (p.second - p1.second) * (p2.first - p1.first) -
              (p2.second - p1.second) * (p.first - p1.first);
  
    if (val > 0) return 1;
    if (val < 0) return -1;
    if(val==0) return 2;
    return 0;
}
  
// dist b/w line & pt.
int lineDist(pair<int, int> p1, pair<int, int> p2, pair<int, int> p){
    return abs ((p.second - p1.second) * (p2.first - p1.first) -
               (p2.second - p1.second) * (p.first - p1.first));
}
  

void solveHull(vector<pair<int,int>> &a, int n, pair<int, int> p1, pair<int, int> p2, int side){
    int ind = -1;
    int max_dist = -1;
  
    // to find farthest pt. from line on specified side
    rep(i,0,n){
        if(a[i]==p1 || a[i]==p2) continue;
        int temp = lineDist(p1, p2, a[i]);
        if (findSide(p1, p2, a[i]) == side && temp > max_dist){
            ind = i;
            max_dist = temp;
        }else if(findSide(p1, p2, a[i])==2 && temp > max_dist){
            ind = i;
            max_dist = temp;
        }
    }
    if(max_dist==0){
        hull.insert(a[ind]);
        ind=-1;
    }

    if (ind == -1){
        hull.insert(p1);
        hull.insert(p2);
        return;
    }
    
    // side 1
    solveHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    // side 2
    solveHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}
  

int main(){
    
    int n;cin>>n;

    vector<pair<int,int>> a;
    rep(i,0,n){
        int x,y;cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());
    if (n < 3){
        cout << "Convex hull is not possible"<<endl;
        return 0;
    }

    // side 1
    solveHull(a, n, a[0], a[n-1], 1);
  
    // side 2
    solveHull(a, n, a[0], a[n-1], -1);
  
    // printing the points
    cout << endl<<"Total Points : ";
    cout<<hull.size()<<endl;
    cout << "The points on the Convex Hull :\n";
    while (!hull.empty()){
        cout <<( *hull.begin()).first <<" "<< (*hull.begin()).second <<endl;
        hull.erase(hull.begin());
    }
    return 0;
}