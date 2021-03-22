#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<int> adj[], int s, int visited[], int colour[], int c){
        visited[s] = 1;
        colour[s] = c;
        for(int child: adj[s]){
            if(visited[child] == 0){
                if(dfs(adj,child,visited,colour,!c) == false)
                    return false;
            } 
            else {
                if(colour[child] == colour[s])
                    return false;
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    int visited[V] = {0};
	    int colour[V] = {0};
	    bool ans;
	    for(int i=0; i<V; i++){
	        if(visited[i] == 0)
	            ans = dfs(adj,i,visited,colour,1);
	            if(ans == false)
	                break;
	    }
	    return ans;    
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}