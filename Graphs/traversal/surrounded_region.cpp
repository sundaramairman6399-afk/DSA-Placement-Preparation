// this is the same problem as no. of enclaves  
// phle toh sirf boundary wali O ko consider kro unke jitne bhi neighbour h unko vis krlo phir jisse ye pta chlta ki unke through hum un tk phoch skty h unko chodna h unko X nhi bnana then jo unvisited rhe gye unko X bna do ; 
// this is done by  dfs; 
class Solution {
public:
    void dfs(vector<vector<char>>&board, vector<vector<int>>& vis,int row , int col ){
        int n  = board.size(); 
        int m  = board[0].size(); 
        vis[row][col] = 1 ; 
        int delrow[] = {-1,0,1,0}; 
        int delcol[] = {0,1,0,-1}; 
        for(int i =0;i<4;i++){
            int nrow  = row + delrow[i]; 
            int ncol = col + delcol[i]; 
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0&& board[nrow][ncol] == 'O'){
                dfs(board , vis , nrow , ncol); 
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n  = board.size(); 
        int m  = board[0].size(); 
        vector<vector<int>>vis(n,vector<int>(m,0)); 
        for(int i =0;i<n;i++){
            if(board[i][0] == 'O' && vis[i][0] == 0){
                dfs(board, vis , i , 0); 
            }
            if(board[i][m-1] == 'O' && vis[i][m-1] == 0){
                dfs(board, vis , i , m-1); 
            }   
        }
        for(int i=0;i<m;i++){
            if(board[0][i] == 'O' && vis[0][i] == 0){
                dfs(board,  vis  ,0 , i ); 
            }
            if(board[n-1][i] == 'O' && vis[n-1][i] == 0){
                dfs(board,  vis  ,n-1 , i ); 
            }
        }
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X'; 
                }

            }
        }
    }
};