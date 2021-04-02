#include <bits/stdc++.h>
using namespace std;

int dist[9][9], visited[9][9];
int sx,sy,ex,ey;
int dx[] = {2,2,1,1,-1,-1,-2,-2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

bool isValid(int x,int y){
    if(x < 1 || x > 8 || y < 1 || y > 8 || visited[x][y] == 1)return false;
        
    return true;
}
    
void bfs(){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    visited[sx][sy] = 1;
    dist[sx][sy] = 0;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
            
        for(int i=0; i<8; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(isValid(nx,ny)){
                dist[nx][ny] = dist[cx][cy] + 1;
                if(nx == ex && ny == ey)return;
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int main()
{   
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        sx = a[0] - 'a' + 1;
        sy = a[1] - '0';
        ex = b[0] - 'a' + 1;
        ey = b[1] - '0';
        
        bfs();
        
        cout << dist[ex][ey] << endl;
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                visited[i][j] = 0; 
            }
        }
        
        
    }
    
    return 0;
}
