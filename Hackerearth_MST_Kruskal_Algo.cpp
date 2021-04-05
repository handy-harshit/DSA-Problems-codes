#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a;
    int b;
    int wt;
};

edge arr[100001];
int parent[10001];

bool mycmp(edge a, edge b){
    if(a.wt < b.wt)
        return true;
        
    return false;
}

int find(int a){
    if(parent[a] == -1)return a;
    return parent[a] = find(parent[a]);
}

int main(){
    int n,m;
    cin>> n >> m;
    
    for(int i=1; i<=n; i++)parent[i] = -1; //each node is parent of itself initially
    
    for(int i=0; i<m; i++){
        cin>> arr[i].a >> arr[i].b >> arr[i].wt;
    }
    
    sort(arr,arr+m,mycmp);
    
    int a,b,ans=0;
    for(int i=0,s=0; i<m,s<n-1; i++){
        a = find(arr[i].a);
        b = find(arr[i].b);
    
    
        if(a != b){
            ans+= arr[i].wt;
            parent[a] = b;   //merging
            s++;
        }
    }
    
    cout << ans;
    
    return 0;
}


