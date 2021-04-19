class Solution {
public:
    int N;
    int board[9][9];
    vector<string>ans;
    vector<vector<string>> res;
    
    bool isSafe(int row, int col){
        
        //same row
        for(int i=0; i<col; i++){
            if(board[row][i])return false;
        }
        //diagonally up
        for(int i=row,j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j])return false;
        }
        //diagonally down
        for(int i=row,j=col; i<N && j>=0; i++,j--){
            if(board[i][j])return false;
        }
        
        return true;
    }
    
    
    void solve(int col){
        //base condn
        if(col == N){
            for(int i=0; i<N; i++){
                string str="";
                for(int j=0; j<N; j++){
                    if(board[i][j] == 0)str+='.';
                    else str+='Q';
                }
                ans.push_back(str);
            }
            res.push_back(ans);
            ans.clear();
            return ;
        }
        
        for(int i=0; i<N; i++){
            if(isSafe(i,col)){
                
                //do
                board[i][col] = 1;
                
                //recur
                solve(col+1);
                
                //undo
                board[i][col] = 0;
            }
        }    
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        solve(0);
        return res;
    }
};