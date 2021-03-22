#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<int> adj[], int s, int visited[], int parent){
        visited[s] = 1;
        for(int child: adj[s]){
            if(visited[child] == 0) {
                if(dfs(adj,child,visited,s) == true)
                    return true;
            }
            else {
                if(child != parent)
                    return true;
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[]){
	    int visited[V] = {0};
	    for(int i=0; i<V; i++){
	        if(visited[i] == 0)
	            if(dfs(adj,i,visited,-1) == true)
	                return true;
	    }
	    return false;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
} 