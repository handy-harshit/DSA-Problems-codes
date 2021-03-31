class Solution {
public:
    
    vector<int> ans;
    
    bool kahn(int n,vector<int> adj[], int indegree[]){
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();q.pop();
            ans.push_back(curr);
            for(int child : adj[curr]){
                indegree[child]--;
                if(indegree[child]==0)
                    q.push(child);
            }
        }
        return (ans.size() == n);
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int m = prerequisites.size();
        
        vector<int> adj[n*n];
        int indegree[n];
        for(int i=0; i<n; i++)indegree[i] = 0;
        
        for(int i=0; i<m; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        if(!kahn(n,adj,indegree))return {};
        else return ans;
        
        
    }
};