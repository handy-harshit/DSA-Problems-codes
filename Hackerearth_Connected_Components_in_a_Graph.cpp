#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], int s, int visited[]){
	visited[s] = 1;
	for(int child: adj[s]){
		if(visited[child] == 0)
			dfs(adj,child,visited);
	}
}

int main() {
	int n,e,u,v;
	int c=0;
	cin >> n >> e;
	vector<int> adj[100001];
	int visited[100001];
	while(e--){
		cin>> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n; i++){
		if(visited[i]==0){
			dfs(adj,i,visited);
			c++;
		}
	}
	cout << c;
}