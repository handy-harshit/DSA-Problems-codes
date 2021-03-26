    #include<bits/stdc++.h>
    using namespace std;
     
    vector<int> adj[100001];
    int visited[100001];
    int dist[100001];
     
    int bfs(int s, int d){
        queue<int> q;
        q.push(s);
        visited[s]=1;
        dist[s]=0;
        int c=0;
        while(!q.empty()){
            int curr = q.front();q.pop();
            for(int child: adj[curr]){
                if(visited[child] == 0){
                    visited[child] = 1;
                    q.push(child);
                    dist[child] = dist[curr] + 1;
                    if(dist[child] == d)c++; 
                }
            }
        }
        return c;
     
    }
     
    int main(){
        int n,m,a,b;
        cin >> n >> m;
        while(m--){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int q,s,d;
        cin >> q;
        for(int i=0; i<q; i++){
            cin >> s >> d;
            cout << bfs(s,d) << endl;
            for(int j=0; j<=n; j++){
                visited[j] = 0;
                dist[j] = 0;
            }
        }
    }
