#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001],tadj[10001],scc;
int visited[10001];
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
        cin>> n >> m;
        
        for(int i=1; i<=n; i++){
            adj[i].clear();
            tadj[i].clear();
            visited[i] = 0;
        }
        
        while(m--){
            cin >> u >> v;
            adj[u].push_back(v);
            tadj[v].push_back(u);
        }
        
        
        for(int i=1; i<=n; i++){
            if(visited[i] == 0)
                dfs(i);
        }
        for(int i=1; i<=n; i++)visited[i] = 0;
        
        while(!st.empty()){
            int curr = st.top();st.pop();
            
            if(visited[curr] == 0){
                scc.clear();
                tdfs(curr);
                for(int i=0; i<scc.size(); i++)cout<< scc[i] << " ";
                cout << endl;
            }
            
        }
        
    }
    
    return 0;
}
