#include<bits/stdc++.h>
using namespace std;

char grid[30][30];
int dist[30][30];
int visited[30][30];
int n;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool isValid(int x,int y){
    if(x<0 || x>n-1 || y<0 || y>n-1)return false;
    if(visited[x][y]==1 || grid[x][y]=='T')return false;
    return true;
}

void bfs(int sx,int sy){
    visited[sx][sy] = 1;
    dist[sx][sy] = 0;
    queue<pair<int,int>> q;
    q.push({sx,sy});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isValid(nx,ny)){
                dist[nx][ny] = dist[cx][cy] + 1;
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    int sx,sy,ex,ey;

    cin >> n ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S')
                sx = i, sy = j;
            if(grid[i][j] == 'E')
                ex = i, ey = j;    
        }
    }
    bfs(sx,sy);

    cout << dist[ex][ey] << endl;
}