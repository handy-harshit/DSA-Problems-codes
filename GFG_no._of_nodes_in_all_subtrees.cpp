#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];
int subSize[100001];

int dfs(int s){
    visited[s] = 1;
    int currSize = 1;
    for(int child: adj[s]){
        if(visited[child] == 0)
            currSize += dfs(child); 
    }
    subSize[s] = currSize;
    return currSize;
}

int main() {
    int t;
    cin>> t;
    while(t--){
        int V,E,u,v;
        cin >> V >> E;
        int s;
        cin >> s;
        while(E--){
            cin>> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(s);
        for(int i=1; i<=V; i++){
            cout << i << ":" << subSize[i] << endl;
        }
        for(int i=1; i<=V; i++){
            adj[i].clear();
            visited[i] = 0;
            subSize[i] = 0;
        }
        
    }
	return 0;
}