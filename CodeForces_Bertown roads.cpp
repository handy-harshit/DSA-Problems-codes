#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];
int in[100001];
int low[100001];
int timer;
vector<pair<int,int>> edges;
bool hasBridge;

void dfs(int s, int parent){
    visited[s] = 1;
    in[s] = low[s] = timer;
    timer++;
    
    for(int child: adj[s]){
        if(child == parent)continue;
        
        else if(visited[child] == 1){
            // edge s-child will be back edge
            low[s] = min(low[s] , in[child]);
            
            if(in[s] > in[child]){
                edges.push_back({s,child}); //print back edge from curr_node(s) to ancestor(child)
            }
        }
        else {
            // edge s-child will be forward edge
            dfs(child,s);
            
            //After dfs, now the cursor is backtracked and s is the current node
            
            //now if low[child] <= in[s] then definetely child has some issue of backedge
            if(low[child] > in[s]) {
                hasBridge = true;
                return;
            }
            
            edges.push_back({s,child}); //print forward edge
                
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
    
    if(hasBridge) cout << "0" << endl;
    else {
        for(pair<int,int> i : edges){
            cout << i.first << " " << i.second << endl;
        }
    }
    
    return 0;
}
