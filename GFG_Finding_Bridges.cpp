#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];
int in[100001];
int low[100001];
int timer;

void dfs(int s, int parent){
    visited[s] = 1;
    in[s] = low[s] = timer;
    timer++;
    
    for(int child: adj[s]){
        if(child == parent)continue;
        
        else if(visited[child] == 1){
            // edge s-child will be back edge
            low[s] = min(low[s] , in[child]);
        }
        else {
            // edge s-child will be forward edge
            dfs(child,s);
            
            //now the cursor is backtracked and s is the current node
            
            //now if low[child] <= in[s] then definetely child has some issue of backedge
            if(low[child] > in[s]) 
                cout << s << "-" << child << "is a bridge" << endl;
            else 
                cout << "Not a bridge" << endl;
                
            low[s] = min(low[child] , low[s]); //if child can reach that minimum then parent can also reach that min.
        }
    }
}

int main()
{
    int n,m,a,b;
    cin>> n >> m;
    
    while(m--){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1,-1);
    
    return 0;
}
