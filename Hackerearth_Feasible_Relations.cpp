#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1000001];
int visited[1000001];
int cc_arr[1000001];
int curr_cc;

void dfs(int s){
    visited[s] = 1;
    cc_arr[s] = curr_cc;
    for(int child: adj[s]){
        if(visited[child] == 0){
            dfs(child);
        }
    }
}

int main(){
    int t;
    cin>> t;
    while(t--){
        int n,k,a,b;
        string op;
        vector<pair<int,int>> p;

        cin>> n >> k;
        
        while(k--){
            cin>> a >> op >> b;
            if(op == "="){
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            else p.push_back({a,b}); 
        }
        curr_cc = 0;
        for(int i=1; i<=n; i++){
            if(visited[i]==0){
                curr_cc++;
                dfs(i);
            }
        }

        bool flag = true;

        for(int i=0; i<p.size(); i++){
            if(cc_arr[p[i].first] == cc_arr[p[i].second]){
                flag = false;
                break;
            }
        }

        if(flag)cout<< "YES" << endl;
        else cout << "NO" << endl;

        for(int i=1; i<=n; i++){
            adj[i].clear();
            visited[i] = 0;
            cc_arr[i] = 0;
        }

    }
}