#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> dfs(vector<int> adj[],int s, int visited[],vector<int> &ans){
        visited[s] = 1;
        ans.push_back(s);
        for(int u: adj[s]){
            if(visited[u] == 0)
                dfs(adj,u,visited,ans);
        }
        return ans;
    }
    
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    int visited[V];
	    vector<int> ans;
	    for(int i=0; i<V; i++)
	        visited[i] = 0;
	    ans = dfs(adj,0,visited,ans);
	    return ans;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}