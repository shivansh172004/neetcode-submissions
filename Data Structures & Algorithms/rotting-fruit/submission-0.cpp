class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m, vector<int>(n, 0));
        int tm = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);
            for(int k=0; k<4; k++){
                int nRow = r + delRow[k];
                int nCol = c + delCol[k];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                    grid[nRow][nCol] = 2;
                    q.push({{nRow, nCol}, t+1});
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && vis[i][j] != 1){
                    return -1;
                }
            }
        }
        return tm;
    }
};
