class Solution {
    private:
    int solve(vector<vector<int>>& grid, vector<vector<int>>&vis, int row, int col){
        // bfs
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 1;
        queue<pair<int, int>>q;
        q.push({row, col});
        vis[row][col] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int newRow = r + delRow[k];
                int newCol = c + delCol[k];
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0){
                    vis[newRow][newCol] = 1;
                    cnt++;
                    q.push({newRow, newCol});
                }
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // maximum area within all the islands
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;
        int cnt = 0;
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                   int cnt = solve(grid, vis, i, j);
                    maxi = max(maxi, cnt);
                }
            }
        }
        return maxi;
    }
};
