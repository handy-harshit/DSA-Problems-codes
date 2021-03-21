#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], int s, int visited[], int dist[], int d){
	visited[s] = 1;
	dist[s] = d;
	for(int child: adj[s]){
		if(visited[child] == 0)
			dfs(adj,child,visited,dist,dist[s]+1);
	}
}

int main() {
	int n,q,u,v;
	cin >> n;
	int e = n-1;

	vector<int> adj[1001];
	int visited[1001];
	int dist[1001];

	while(e--){
		cin>> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(adj,1,visited,dist,0);

	int min_dist = INT_MAX;
	int ans = -1;

	cin >> q;
	while(q--){
		int queen_city;
		cin >> queen_city;
		if(dist[queen_city] < min_dist){
			min_dist = dist[queen_city];
			ans = queen_city;
		}  
	}
	cout << ans;
}