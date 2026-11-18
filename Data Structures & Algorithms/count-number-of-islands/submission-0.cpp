class Solution {
    private:
    void solve(vector<vector<char>>& grid, int row, int col, vector<vector<int>>&vis){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        q.push({row, col});
        vis[row][col] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k=0; k<4; k++){
                int nRow = r + delRow[k];
                int nCol = c + delCol[k];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol <n && grid[nRow][nCol] == '1' && vis[nRow][nCol] == 0){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    count++;
                    solve(grid, i, j, vis);
                }
            }
        }
        return count;
    }
};
