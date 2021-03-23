#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], int s, int visited[], int &nc){
    visited[s] = 1;
    nc++;
    for(int child: adj[s]){
        if(visited[child] == 0){
            nc = dfs(adj,child,visited,nc);
        }
    }
    return nc;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int V,E,u,v;
	    vector<int> adj[100001];
	    int visited[100001] = {0};
	    cin >> V >> E;
	    while(E--){
	        cin >> u >> v;
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }
	    int c=0,nc;
	    long long int ans = 1;
	    for(int i=1; i<=V; i++){
	        nc=0;
	        if(visited[i] == 0){
	            nc = dfs(adj,i,visited,nc);
	            ans = ans * nc % 1000000007;
	            c++;
	        }
	    }
	    cout << c << " " << ans << endl;
	    
	}
	return 0;
}