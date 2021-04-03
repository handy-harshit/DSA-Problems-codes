#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000001],tadj[1000001],scc;
int visited[1000001],value[1000001];
stack<int> st;

void dfs(int n){
    visited[n] = 1;
    for(int child: adj[n]){
        if(visited[child] == 0)
            dfs(child);
    }
    st.push(n);
}

void tdfs(int n){
    visited[n] = 1;
    for(int child: tadj[n]){
        if(visited[child] == 0)
            tdfs(child);
    }
    scc.push_back(n);
    
}

int main()
{   
    int t,n,m,u,v;
    cin >> t;
    while(t--){
        cin>> n;
        
        for(int i=0; i<n; i++){
            adj[i].clear();
            tadj[i].clear();
            visited[i] = 0;
            cin>> value[i];
        }
        
        for(int i=0; i<n; i++){
            int u = i;
            int v = (i+value[i]+1)%n;
            adj[u].push_back(v);
            tadj[v].push_back(u);
        }
        
        
        for(int i=0; i<n; i++){
            if(visited[i] == 0)
                dfs(i);
        }
        for(int i=0; i<n; i++)visited[i] = 0;
        
        int ans = 0;
        
        while(!st.empty()){
            int curr = st.top();st.pop();
            
            if(visited[curr] == 0){
                scc.clear();
                tdfs(curr);
                if(scc.size() == 1 && scc[0] != adj[scc[0]][0])continue;
                ans+=scc.size();
            }
            
        }
        cout <<  ans << endl;
        
    }
    
    return 0;
}
