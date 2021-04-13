#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[10001];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b,wt;
        cin >> n >> m;
        
        while(m--){
            cin>> a >> b >> wt;
            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }
        int s;
        cin >> s;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > minH;
        vector<int> dist(n+1, INT_MAX);
        vector<int> visited(n+1, 0);
        
        minH.push({0,s});
        dist[s] = 0;
        
        while(!minH.empty()){
            auto curr = minH.top();minH.pop();
            int n1 = curr.second;
            int n1_dist = curr.first;
            
            
            //if(dist[n1] != n1_dist)continue;
            if(visited[n1])continue;
            visited[n1] = 1;
            
            for(auto edge : adj[n1]){
                int n2 = edge.first;
                int wt = edge.second;
                if(dist[n1] + wt < dist[n2]){
                    dist[n2] = dist[n1] + wt;
                    minH.push({dist[n2],n2});
                }
                    
            }
        }
        for(int i=1; i<=n ; i++){
            if(i == s)continue;
            if(visited[i] == 0)cout << -1 << " ";
            else cout<< dist[i] << " ";
            
        }
        cout<<endl;
            
        
        for(int i=0; i<=n; i++)adj[i].clear();
    
    }
    
    return 0;
}


