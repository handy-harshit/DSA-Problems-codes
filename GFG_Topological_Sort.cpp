/*USING BFS(KAHN) */
	
	int inDegree[10001];
	vector<int> ans;
	
	void kahn(int V,vector<int> adj[]){
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if(inDegree[i] == 0)q.push(i);
	    }
	    while(!q.empty()){
	        int curr = q.front(); q.pop();
	        ans.push_back(curr);
	        for(int child: adj[curr]){
	            inDegree[child]--;
	            if(inDegree[child] == 0)q.push(child);
	        }
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    for(int i=0; i<V; i++){
	        for(int child : adj[i])
	            inDegree[child]++;
	    }
	    kahn(V,adj);
	    return ans;
	    
	}