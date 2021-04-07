class Solution {
public:
    int n,m;
    int visited[501][501];
    int dx[8] = {-1,0,1,0,1,1,-1,-1};
    int dy[8] = {0,1,0,-1,-1,1,-1,1};
    
    
    void dfs(int x ,int y, vector<vector<char>>& grid ){
        if(x < 0 || x >= n || y < 0 || y>=m || grid[x][y]=='0')return;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                dfs(nx,ny,grid);
            }
        }
    }
    

    int numIslands(vector<vector<char>>& grid) {
        
        
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                visited[i][j] = 0;
            }
        }

        int islands = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && visited[i][j]==0){
                    dfs(i,j,grid);
                    islands++;
                }
            }
        }
        
        return islands;