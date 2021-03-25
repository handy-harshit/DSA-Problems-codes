#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];
int dist[100001];
vector<int> primes;

bool isPrime(int n){
    
    for(int i=2; i*i<=n; i++){
        if(n % i == 0)return false;
    }
    return true;
    
}

bool isValid (int a, int b) {
    
    int c=0;
    while(a > 0){
        if((a % 10) != (b % 10))c++;
        a/=10;
        b/=10;
    }
    return (c==1);
    
}

void buildGraph() {
    
    for(int i=1000; i<=9999; i++){
        if(isPrime(i))
            primes.push_back(i);
    }
    for(int i=0; i<primes.size(); i++){
        for(int j=i+1; j<primes.size(); j++){
            int a = primes[i];
            int b = primes[j];
            if(isValid(a,b)){
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
    }
    
}

void bfs(int s){
    
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    dist[s] = 0;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int child: adj[curr]){
            if(visited[child] == 0){
                visited[child] = 1;
                q.push(child);
                dist[child] = dist[curr] + 1;
            }
        }
        
    }
    
}

int main() {
    buildGraph();
    
    int t;
    cin>> t;
    
    while(t--){
        
        int a, b;
        cin>> a>> b;
        
        for(int i=1000; i<=9999; i++){
            dist[i] = -1;
            visited[i] = 0;
        }
        
        bfs(a);
        
        if(dist[b] == -1)cout<< "Impossible" << endl;
        else cout << dist[b] << endl;
        
        
    }
    
	return 0;
}