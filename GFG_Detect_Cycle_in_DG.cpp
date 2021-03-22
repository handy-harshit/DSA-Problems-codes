#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<int> adj[], int s, int visited[], int RecSt[]){
        visited[s] = 1;
        RecSt[s] = 1;
        for(int child: adj[s]){
            if(visited[child] == 0){
                if(dfs(adj,child,visited,RecSt))return true;
            }
            else {
                if(RecSt[child] == 1)return true;
            }
        }
        RecSt[s] = 0;
        return false;
    }

	bool isCyclic(int V, vector<int> adj[]) {
	   	int visited[V] = {0};
	   	int RecSt[V] = {0};
	   	for(int i=0; i<V; i++){
	   	    if(visited[i] == 0)
	   	    if(dfs(adj,i,visited,RecSt))return true;
	   	}
	   	return false;
	}
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}