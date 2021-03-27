#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];
int in[100001];
int low[100001];
int timer;
set<int> AP; //as same node count will be repeated in counter

void dfs(int s, int parent){
    visited[s] = 1;
    timer++;
    in[s] = low[s] = timer;
    int children_cnt = 0;
    
    for(int child: adj[s]){
        if(child == parent)continue;
        
        else if(visited[child] == 1){
            // edge s-child will be back edge
            low[s] = min(low[s] , in[child]);
        }
        else {
            // edge s-child will be forward edge
            dfs(child,s);
            children_cnt++;
            
            //After dfs, now the cursor is backtracked and s is the current node
                
            low[s] = min(low[child] , low[s]); //if child can reach that ancestor thru backedge then parent can also reach that ancestor.
            if(in[s] <= low[child] && parent != -1){
                AP.insert(s);
            }
        }
    }
    //if root has more then one children then definetely it will be AP
    if(parent == -1 && children_cnt > 1){   
        AP.insert(s);
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
    
    cout << AP.size() << endl;
    
    return 0;
}
