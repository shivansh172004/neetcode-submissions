class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
         queue<pair<int, int>>q; 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int INF = INT_MAX;
        int delRow[] = {-1, 0, 1 , 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int nRow = r + delRow[k];
                int nCol = c + delCol[k];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol] == INF){
                    grid[nRow][nCol] = grid[r][c] + 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
};
