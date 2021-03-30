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

    /*USING DFS*/

    int visited[10001];
    stack<int> st;
    vector<int> ans;
    
    void DFS(vector<int> adj[], int s){
        visited[s] = 1;
        for(int child : adj[s]){
            if(visited[child] == 0){
                DFS(adj,child);
            }
        }
        st.push(s);
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        
        for(int i=0; i<V; i++){
            if(visited[i] == 0){
                DFS(adj,i);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        for(int i=0; i<V; i++){
            visited[i] = 0;
        }
        
        return ans;
    }