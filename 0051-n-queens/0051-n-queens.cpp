class Solution {
public:

    void solve(vector<vector<string>>& ans, vector<string>& board, vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag, int & n, int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n;row++){
            if(leftRow[row] == 0 && upperDiag[n-1+col-row]==0 && lowerDiag[row+col]==0){

                board[row][col]='Q';
                leftRow[row]=1;
                upperDiag[n-1+col-row]=1;
                lowerDiag[row+col]=1;
                solve(ans,board,leftRow,upperDiag,lowerDiag,n,col+1);
                 board[row][col]='.';
                leftRow[row]=0;
                upperDiag[n-1+col-row]=0;
                lowerDiag[row+col]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<int> leftRow(n,0), upperDiag(2*n-1,0), lowerDiag(2*n-1,0);
        solve(ans,board,leftRow,upperDiag,lowerDiag,n,0);
        return ans;
    }
};