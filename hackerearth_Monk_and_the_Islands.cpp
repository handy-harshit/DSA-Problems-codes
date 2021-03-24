#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int visited[10001];
int dist[10001];

void bfs(int s){
    queue<int> q;
    q.push(s);
	visited[s] = 1;
    dist[s] = 0;
    while(!q.empty()){
        int curr = q.front();q.pop();
	    for(int child: adj[curr]){
		    if(visited[child] == 0){
                q.push(child);
			    visited[child] = 1;
                dist[child] = dist[curr] + 1;
            }
        }
	}
}

int main() {
	int t;
	cin>> t;
	while(t--){

		int n,m,u,v;
		cin >> n >> m;

		while(m--){
			cin>> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bfs(1);

		cout<< dist[n] << endl;

		for(int i=1; i<=n; i++){
			adj[i].clear();
			visited[i] = 0;
			dist[i] = 0;
		}
	}
}
