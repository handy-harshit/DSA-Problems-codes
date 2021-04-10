class Solution {
public:
    vector<int> findcor(int node, int n){       //function to find coordinates of given number
        int r = n- (node-1)/n-1;
        int c = (node-1) % n;
        if(r%2 == n%2)return {r,n-c-1};
        else return {r,c};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int visited[21][21];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] =0 ;
            }
        }
        queue<pair<int,int>> q;   // storing number and its step
        q.push({1,0});
        visited[n-1][0] = 1; 
        
        int total_steps = -1;
        
        while(!q.empty()){
            int curr_node = q.front().first;
            int curr_step = q.front().second;
            q.pop();
            if(curr_node == n*n)return curr_step;
            for(int i=1; i<=6; i++){
                if(curr_node + i > n*n)break;
                vector<int> pos = findcor(curr_node+i,n);
                int r = pos[0];
                int c = pos[1];
                if(visited[r][c] == 0){
                    visited[r][c] = 1;
                    if(board[r][c] == -1)q.push({curr_node+i,curr_step + 1});
                    else q.push({board[r][c],curr_step + 1});
                    total_steps = curr_step + 1;
                }
            }
        }
        return -1;
    }
};