#include <bits/stdc++.h>
using namespace std;

int visited[1001][1001];
char grid[1001][1001];
int n,m;

bool isValid(int x,int y){
    if(x < 0 || x > n-1 || y < 0 || y > m-1)return false;
    if(visited[x][y] == 1 || grid[x][y] == '#')return false;
    
    return true;
}

void dfs(int x,int y){
    
    visited[x][y] = 1;
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    
    for(int i=0; i<4; i++){
        if(isValid(x+dx[i] , y+dy[i]))
            dfs(x+dx[i] , y+dy[i]);
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    
    int cc = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j] == 0 && grid[i][j] == '.'){
                dfs(i,j);
                cc++;
            }
        }
    }
    
    cout << cc << endl;
    
    return 0;
}
